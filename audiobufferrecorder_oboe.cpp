#include "audiobufferrecorder_oboe.h"
#include <QJniEnvironment>
#include <QJniObject>
#include <QCoreApplication>
#include "appsettings.h"

AudioBufferRecorder::AudioBufferRecorder(QObject *parent)
    : QObject{parent}, m_engine(this)
{

}


void
requestPermissions(const QStringList &permissions)
{
    const int requestCode = 1;
    bool isFinished = false;
    auto threadPromise = QNativeInterface::QAndroidApplication::runOnAndroidMainThread([permissions, requestCode, &isFinished] {
        QJniEnvironment env;
        jclass clazz = env.findClass("java/lang/String");
        auto array = env->NewObjectArray(permissions.size(), clazz, nullptr);
        int index = 0;

        for (auto &perm : permissions)
            env->SetObjectArrayElement(array, index++, QJniObject::fromString(perm).object());

        QJniObject(QNativeInterface::QAndroidApplication::context()).callMethod<void>("requestPermissions",
                                                                                      "([Ljava/lang/String;I)V",
                                                                                      array,
                                                                                      requestCode);
        env->DeleteLocalRef(array);
        isFinished = true;
    });
    while (!isFinished);
}


OboeEngine::OboeEngine(AudioBufferRecorder *p)
    : m_p(p)
{
    QJniEnvironment env;
    int devId = 0;
    requestPermissions({"android.permission.RECORD_AUDIO"});
    //based on code from https://github.com/juce-framework/JUCE/blob/master/modules/juce_audio_devices/native/juce_android_Oboe.cpp
    jclass audioManagerClass = env->FindClass ("android/media/AudioManager");
    jclass ctxClass = env->FindClass("android/content/Context");
    jmethodID methodGetSystemService = env.findMethod(ctxClass,
                                      "getSystemService",
                                      "(Ljava/lang/String;)Ljava/lang/Object;");
    auto audioManager = env->CallObjectMethod(
                QNativeInterface::QAndroidApplication::context(),
                methodGetSystemService,
                QJniObject::fromString("audio").object()
                );
    jmethodID methodGetDevices = env->GetMethodID(audioManagerClass,
                                                  "getDevices",
                                                  "(I)[Landroid/media/AudioDeviceInfo;");
    const int getInputDevs = 1;
    jobjectArray devices = (jobjectArray)env->CallObjectMethod(audioManager,
                          methodGetDevices,
                          getInputDevs);
    const int numDevices = env->GetArrayLength(devices);
    jclass audioDeviceInfoClass = env->FindClass("android/media/AudioDeviceInfo");
    jmethodID methodGetProductName = env.findMethod(audioDeviceInfoClass,
                                                    "getProductName",
                                                    "()Ljava/lang/CharSequence;");
    jmethodID methodGetId = env.findMethod(audioDeviceInfoClass,
                                           "getId",
                                           "()I");
    jclass charSequenceClass = env->FindClass("java/lang/CharSequence");
    jmethodID methodToString = env.findMethod(charSequenceClass,
                                              "toString",
                                              "()Ljava/lang/String;");
    jmethodID methodGetType = env.findMethod(audioDeviceInfoClass,
                                             "getType",
                                             "()I");
    const std::vector<const char*> audioDevTypeNames = {
            "TYPE_UNKNOWN",
            "TYPE_BUILTIN_EARPIECE",
            "TYPE_BUILTIN_SPEAKER",
            "TYPE_WIRED_HEADSET",
            "TYPE_WIRED_HEADPHONES",
            "TYPE_LINE_ANALOG",
            "TYPE_LINE_DIGITAL",
            "TYPE_BLUETOOTH_SCO",
            "TYPE_BLUETOOTH_A2DP",
            "TYPE_HDMI",
            "TYPE_HDMI_ARC",
            "TYPE_USB_DEVICE",
            "TYPE_USB_ACCESSORY",
            "TYPE_DOCK",
            "TYPE_FM",
            "TYPE_BUILTIN_MIC",
            "TYPE_FM_TUNER",
            "TYPE_TV_TUNER",
            "TYPE_TELEPHONY",
            "TYPE_AUX_LINE",
            "TYPE_IP",
            "TYPE_BUS",
            "TYPE_USB_HEADSET",
            "TYPE_HEARING_AID",
            "TYPE_BUILTIN_SPEAKER_SAFE",
            "TYPE_REMOTE_SUBMIX",
            "TYPE_BLE_HEADSET",
            "TYPE_BLE_SPEAKER",
            "TYPE_ECHO_REFERENCE",
            "TYPE_HDMI_EARC",
            "TYPE_BLE_BROADCAST"};
    jobject info = env->GetObjectArrayElement(devices, 0);
    jint id = env->CallIntMethod(info, methodGetId);
    m_record_device_id = id;
    QString devName;
    QList<QString> audioDevNames;
    QList<uint32_t> samplingRates = {44100};
    for (int i=0; i < numDevices; i++) {
        jobject info = env->GetObjectArrayElement(devices, i);
        jobject productName = env->CallObjectMethod(info, methodGetProductName);
        jstring productNameJstr = (jstring)env->CallObjectMethod(productName,
                                                        methodToString);
        const char* productNameCstr = env->GetStringUTFChars(productNameJstr, 0);
        audioDevNames.push_back(productNameCstr);
        jint id = env->CallIntMethod(info, methodGetId);
        if (id == m_record_device_id) {
            jint type = env->CallIntMethod(info, methodGetType);
            qDebug() << productNameCstr << ", " << id << ", " << audioDevTypeNames[type];
            devName = QString("%1 (%2)").arg(productNameCstr).arg(id);
            env->ReleaseStringUTFChars(productNameJstr, productNameCstr);
            break;
        }
    }
    using std::move;
    AppSettings* appSettings = AppSettingsInstance();
    appSettings->setAvailableInputDevNames(move(audioDevNames));
    appSettings->setAvailableSamplingRates(move(samplingRates));
    if (appSettings->isFirstRun()) {
        appSettings->setAudioInputDeviceName(devName);
        m_sample_rate = 44100;
        appSettings->setSamplingRate(m_sample_rate);
        appSettings->setNumInputChannels(1);
    }
    //env->DeleteLocalRef(devices);
}

void OboeEngine::start()
{
    oboe::AudioStreamBuilder builder;
    builder.setDeviceId(m_record_device_id)
            ->setDirection(oboe::Direction::Input)
            ->setFormat(oboe::AudioFormat::I16)
            ->setFormatConversionAllowed(true)
            ->setPerformanceMode(oboe::PerformanceMode::LowLatency)
            ->setSampleRate(m_sample_rate)
            ->setChannelCount(1)
            ->setDataCallback(this)
            ->openStream(m_record_stream);
    m_record_stream->requestStart();
}

void OboeEngine::stop()
{
    m_record_stream->stop();
    m_record_stream->close();
}

void OboeEngine::onErrorBeforeClose(oboe::AudioStream *oboeStream, oboe::Result error)
{
    qDebug("%s stream Error before close: %s",
             oboe::convertToText(oboeStream->getDirection()),
             oboe::convertToText(error));
}

void OboeEngine::onErrorAfterClose(oboe::AudioStream *oboeStream, oboe::Result error)
{
    qDebug("%s stream Error after close: %s",
             oboe::convertToText(oboeStream->getDirection()),
             oboe::convertToText(error));
}

oboe::DataCallbackResult OboeEngine::onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames)
{
    emit m_p->bufferReady((int16_t*)audioData, numFrames);
    return oboe::DataCallbackResult::Continue;
}

bool AudioBufferRecorder::start()
{
    m_engine.start();
    return true;
}
bool AudioBufferRecorder::stop()
{
    m_engine.stop();
    return true;
}
