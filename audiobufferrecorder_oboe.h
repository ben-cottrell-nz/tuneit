#ifndef AUDIOBUFFERRECORDER_OBOE_H
#define AUDIOBUFFERRECORDER_OBOE_H

#include <QObject>
#include <QThread>
#include "oboe/AudioStream.h"

class AudioBufferRecorder;

class OboeEngine : public oboe::AudioStreamDataCallback {
public:
    OboeEngine(AudioBufferRecorder* p);
    // AudioStreamErrorCallback interface
public:
    void start();
    void stop();
    void onErrorBeforeClose(oboe::AudioStream *, oboe::Result);
    void onErrorAfterClose(oboe::AudioStream *, oboe::Result);
    // AudioStreamDataCallback interface
    oboe::DataCallbackResult onAudioReady(oboe::AudioStream *audioStream, void *audioData, int32_t numFrames);
private:
    AudioBufferRecorder* m_p;
    int32_t m_record_device_id = oboe::kUnspecified;
    const oboe::AudioFormat m_format = oboe::AudioFormat::I16;
    int32_t m_sample_rate = oboe::kUnspecified;
    oboe::AudioStreamBuilder m_in_builder;
    std::shared_ptr<oboe::AudioStream> m_record_stream;
};

class AudioBufferRecorder : public QObject
{
    Q_OBJECT
public:
    explicit AudioBufferRecorder(QObject *parent = nullptr);
    Q_INVOKABLE bool start();
    Q_INVOKABLE bool stop();
    uint32_t m_sampleRate;
    uint32_t m_bufferFrames;
signals:
    void bufferReady(int16_t* buffer, uint32_t bufferFrames);
private:
    OboeEngine m_engine;
};

#endif // AUDIOBUFFERRECORDER_OBOE_H
