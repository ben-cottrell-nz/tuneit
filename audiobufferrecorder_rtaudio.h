#ifndef Q_OS_ANDROID
#ifndef AUDIOBUFFERRECORDER_H
#define AUDIOBUFFERRECORDER_H

#include <QObject>
#include <QThread>
#include "RtAudio.h"

class AudioBufferRecorder : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QString apiName READ getAPIName NOTIFY apiNameChanged)
    Q_PROPERTY(int samplingRate MEMBER m_sampleRate)
    Q_PROPERTY(int bufferSize MEMBER m_bufferFrames)
    Q_INVOKABLE bool start();
    explicit AudioBufferRecorder(QObject *parent = nullptr);
    Q_INVOKABLE bool stop();
    uint32_t m_sampleRate;
    uint32_t m_bufferFrames;
private:
    QString getAPIName();
signals:
    void apiNameChanged();
    void bufferReady(int16_t* buffer, uint32_t bufferFrames);
private:
    RtAudio m_adc;
};

#endif // AUDIOBUFFERRECORDER_H
#endif
