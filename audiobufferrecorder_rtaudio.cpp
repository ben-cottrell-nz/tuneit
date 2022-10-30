#include "audiobufferrecorder_rtaudio.h"
#include <QDebug>

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
    RtAudio::StreamParameters params;
    m_sampleRate = 44100;
    m_bufferFrames = 1024;
    m_numChannels = 1;
    params.deviceId = m_adc.getDefaultInputDevice();
    params.nChannels = m_numChannels;
    params.firstChannel = 0;
    emit numChannelsChanged();
    emit sampleRateChanged();
    auto recordFun = []( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
            double streamTime, RtAudioStreamStatus status, void *userData ) -> int {
        emit ((AudioBufferRecorder*)userData)->bufferReady((int16_t*)inputBuffer, nBufferFrames);
        return 0;
    };
    try {
        qDebug() << "Using audio api " << RtAudio::getApiName(m_adc.getCurrentApi()).c_str();
      m_adc.openStream( NULL, &params, RTAUDIO_SINT16,
                      m_sampleRate, &m_bufferFrames, recordFun, this );
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

QString AudioBufferRecorder::getAPIName() {
    return QString(m_adc.getApiDisplayName(m_adc.getCurrentApi()).c_str());
}
