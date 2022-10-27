#ifndef FFTFILTERPROCESSOR_H
#define FFTFILTERPROCESSOR_H

#include <QObject>
#include <iostream>
#include <vector>
#include "fftw3.h"
#include <QVariantList>

class FFTFilterProcessor : public QObject
{
    Q_OBJECT
public:
    explicit FFTFilterProcessor(QObject *parent = nullptr);
    ~FFTFilterProcessor();
    Q_INVOKABLE double outputBufferAt(const int index, const int p);
    Q_INVOKABLE QList<qreal> outputBufferList();
    Q_INVOKABLE QString getPeakScientificNote();
    Q_INVOKABLE qreal getPeakFreq();
    void processBuffer(int16_t* in, const int samplingRate, const int numFrames);
signals:
    void processingDone(const int numFrames, const qreal peakFreq, QList<double> outputBufferList);
private:
    int m_buffer_length;
    int m_processed_frames;
    qreal m_last_peak_freq;
    std::vector<double> m_in_buffer;
    fftw_complex* m_fft_output;
    fftw_plan m_fft_plan;
};

#endif // FFTFILTERPROCESSOR_H
