#include "audiobufferrecorder.h"
#include "RtAudio.h"

static RtAudio g_adc;

AudioBufferRecorder::AudioBufferRecorder(QObject *parent)
    : QObject{parent}
{

}

bool AudioBufferRecorder::start()
{
    RtAudio adc;
    if (adc.getDeviceCount() < 1) {
        return false;
    }
    RtAudio::StreamParameters params;
    params.deviceId = adc.getDefaultInputDevice();
    params.nChannels = 2;
    params.firstChannel = 0;
    m_sampleRate = 44100;
    m_bufferFrames = 512;
    auto recordFun = []( void *outputBuffer, void *inputBuffer, unsigned int nBufferFrames,
            double streamTime, RtAudioStreamStatus status, void *userData ) -> int {
        emit ((AudioBufferRecorder*)userData)->bufferReady((int16_t*)inputBuffer, nBufferFrames);
    };
    try {
      adc.openStream( NULL, &params, RTAUDIO_SINT16,
                      m_sampleRate, &m_bufferFrames, recordFun );
      adc.startStream();
    }
    catch (void* e) {
        return false;
    }
}

bool AudioBufferRecorder::stop()
{
    try {
        g_adc.stopStream();
    }
    catch (void* e) {
        return false;
    }
    if (g_adc.isStreamOpen()) { g_adc.closeStream(); }
    return true;
}
