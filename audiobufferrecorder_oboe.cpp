#include "audiobufferrecorder_oboe.h"
#include "qcoreapplication_platform.h"
#include <QJniEnvironment>
#include <QJniObject>

AudioBufferRecorder::AudioBufferRecorder(QObject *parent)
    : QObject{parent}, m_engine(this)
{

}


void
requestPermissions(const QStringList &permissions)
{
    const int requestCode = 1;
    QNativeInterface::QAndroidApplication::runOnAndroidMainThread([permissions, requestCode] {
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
    });
}


OboeEngine::OboeEngine(AudioBufferRecorder *p)
    : m_p(p)
{
    QJniEnvironment env;
    int devId = 0;
    requestPermissions({"android.permission.RECORD_AUDIO"});
    {
        jclass audioDevsClass = env->FindClass("com/bgcottrell/tuneit/AudioDevices");
//        jmethodID method = env->GetStaticMethodID(audioDevsClass, "myfun", "(Landroid/content/Context;)V");
//        jmethodID method = env->GetStaticMethodID(audioDevsClass, "getDefaultInputDeviceInfo", "(Landroid/content/Context;)V");
//        jmethodID method = env->GetStaticMethodID(audioDevsClass,
//                                            "getDefaultInputDeviceInfo",
//                                            "(Landroid/content/context;)Landroid/media/AudioDeviceInfo;");
//        env->CallStaticVoidMethod(audioDevsClass, method, QNativeInterface::QAndroidApplication::context());
//        jobjectArray audioDevsInfo;
//        env->CallStaticObjectMethod(audioDevsClass,
//                                    method,
//                                    QNativeInterface::QAndroidApplication::context());
//        jint obj = QJniObject::callStaticMethod<jint>("com.bgcottrell.tuneit.AudioDevices",
//                                              "getDefaultInputDeviceId",
//                                              "(Landroid/content/context;)I",
//                                                            QNativeInterface::QAndroidApplication::context()
//                                              );
    }


//    QJniEnvironment jniEnv;
//    jclass audioDevsjclass = jniEnv.findClass("com/bgcottrell/tuneit/AudioDevices");
//    jclass audioDevInfoCls = jniEnv.findClass("android/media/AudioDeviceInfo");
//    QJniObject audioDevInfo = jniEnv->AllocObject(audioDevInfoCls);
//    audioDevInfo.fromLocalRef(QJniObject::callStaticObjectMethod(
//                "com/bgcottrell/tuneit/AudioDevices", "getDefaultInputDeviceInfo",
//                "(Landroid/content/Context;)Landroid/media/AudioDeviceInfo;").object());

//    {
//      QJniObject obj = audioDevInfo.callObjectMethod(
//          "getId", "()I;",
//          QNativeInterface::QAndroidApplication::context());
//      devId = *((int32_t *)obj.object());
//    }
    int32_t defaultSamplingRate = 44100;
    m_in_builder.setDeviceId(devId)
            ->setDirection(oboe::Direction::Input)
            ->setFormat(oboe::AudioFormat::I16)
            ->setFormatConversionAllowed(true)
            ->setPerformanceMode(oboe::PerformanceMode::LowLatency)
            ->setSampleRate(defaultSamplingRate)
            ->setChannelCount(1)
            ->setErrorCallback(this)
            ->setDataCallback(this);
}

void OboeEngine::start()
{
    m_in_builder.openStream(m_record_stream);
}

void OboeEngine::stop()
{
    m_record_stream->stop();
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
