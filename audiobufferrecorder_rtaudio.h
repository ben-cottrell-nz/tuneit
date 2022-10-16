#ifndef AUDIOBUFFERRECORDER_H
#define AUDIOBUFFERRECORDER_H

#include <QObject>
#include <QThread>
#include "RtAudio.h"

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
    QThread m_thread;
    RtAudio m_adc;
};

#endif // AUDIOBUFFERRECORDER_H
