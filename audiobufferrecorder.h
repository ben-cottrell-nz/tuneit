#ifndef AUDIOBUFFERRECORDER_H
#define AUDIOBUFFERRECORDER_H

#include <QObject>

class AudioBufferRecorder : public QObject
{
    Q_OBJECT
public:
    explicit AudioBufferRecorder(QObject *parent = nullptr);
    bool start();
    bool stop();
    uint32_t m_sampleRate;
    uint32_t m_bufferFrames;
signals:
    void bufferReady(int16_t* buffer, uint32_t bufferFrames);
};

#endif // AUDIOBUFFERRECORDER_H
