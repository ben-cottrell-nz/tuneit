#include "audiobufferrecorder_rtaudio.h"
#include <QDebug>
#include "appsettings.h"

AudioBufferRecorder::AudioBufferRecorder(QObject *parent)
    : QObject{parent}
{

}

bool AudioBufferRecorder::start()
{
    if (m_adc.getDeviceCount() < 1) {
        return false;
    }
    m_adc.setErrorCallback([](RtAudioErrorType type,
                           const std::string &errorText){
        qDebug() << "rtaudio error, type " << type << ": " << errorText.c_str();
    });
    using std::move;
    AppSettings* appSettings = AppSettingsInstance();
    //get available settings, and move the lists to the AppSettings instance
    auto devIds = m_adc.getDeviceIds();
    QList<QString> availableDevNames;
    for (int i=0; i<devIds.size(); i++) {
        RtAudio::DeviceInfo devInfo = m_adc.getDeviceInfo(devIds[i]);
        if (devInfo.inputChannels > 0) {
            availableDevNames.push_back(QString("%1 (%2)").arg(devInfo.name.c_str()).arg(devInfo.ID));
            appSettings->setAvailableSamplingRates(
                            move(QList<uint32_t>(devInfo.sampleRates.begin(), devInfo.sampleRates.end()))
                        );
//            QList<uint32_t> numChannels(devInfo.inputChannels);
//            for (int i=0;i<numChannels.size();i++) {
//                numChannels.push_back(i+1);
//            }
            appSettings->setAvailableNumInputChannels(move(QList<uint32_t>{1,2}));
        }
    }
    appSettings->setAvailableInputDevNames(move(availableDevNames));
    //set the default settings
    if (appSettings->isFirstRun()) {
        uint32_t defaultInputID = m_adc.getDefaultInputDevice();
        RtAudio::DeviceInfo devInfo = m_adc.getDeviceInfo(defaultInputID);
        QString devName = QString("%1 (%2)").arg(devInfo.name.c_str()).arg(defaultInputID);
        appSettings->setAudioInputDeviceName(devName);
        appSettings->setSamplingRate(devInfo.preferredSampleRate);
        appSettings->setNumInputChannels(1);
    }
    RtAudio::StreamParameters params;
//    m_sampleRate = AppSettingsInstance()->getSamplingRate();
    m_bufferFrames = 1024;
//    m_numChannels = AppSettingsInstance()->getNumInputChannels();
    params.deviceId = AppSettingsInstance()->getAudioInputDeviceID();
    params.nChannels = AppSettingsInstance()->getNumInputChannels();
    params.firstChannel = 0;
//    emit numChannelsChanged();
//    emit sampleRateChanged();
    auto recordFun = []( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
            double streamTime, RtAudioStreamStatus status, void *userData ) -> int {
        emit ((AudioBufferRecorder*)userData)->bufferReady((int16_t*)inputBuffer, nBufferFrames);
        return 0;
    };
    try {
        qDebug() << "Using audio api " << RtAudio::getApiName(m_adc.getCurrentApi()).c_str();
      m_adc.openStream( NULL, &params, RTAUDIO_SINT16,
                      AppSettingsInstance()->getSamplingRate(), &m_bufferFrames, recordFun, this );
      m_adc.startStream();
    }
    catch (void* e) {
        return false;
    }
    return true;
}

bool AudioBufferRecorder::stop()
{
    try {
        m_adc.stopStream();
    }
    catch (void* e) {
        return false;
    }
    if (m_adc.isStreamOpen()) { m_adc.closeStream(); }
    return true;
}

//QString AudioBufferRecorder::getAPIName() {
//    return QString(m_adc.getApiDisplayName(m_adc.getCurrentApi()).c_str());
//}
