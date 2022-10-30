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
    Q_PROPERTY(uint32_t samplingRate READ getSampleRate NOTIFY sampleRateChanged)
    Q_PROPERTY(uint32_t bufferSize READ getBufferSize)
    Q_PROPERTY(uint32_t numChannels READ getNumChannels NOTIFY numChannelsChanged)
    Q_INVOKABLE bool start();
    explicit AudioBufferRecorder(QObject *parent = nullptr);
    Q_INVOKABLE bool stop();

    uint32_t getSampleRate() { return m_sampleRate; }
    uint32_t getNumChannels() { return m_numChannels; }
    uint32_t getBufferSize() { return m_bufferFrames; }
private:
    QString getAPIName();
signals:
    void apiNameChanged();
    void numChannelsChanged();
    void sampleRateChanged();
    void bufferReady(int16_t* buffer, uint32_t bufferFrames);
private:
    uint32_t m_numChannels;
    uint32_t m_sampleRate;
    uint32_t m_bufferFrames;
    RtAudio m_adc;
};

#endif // AUDIOBUFFERRECORDER_H
#endif
