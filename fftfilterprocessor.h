#ifndef FFTFILTERPROCESSOR_H
#define FFTFILTERPROCESSOR_H

#include <QObject>
#include "fftw3.h"
#include <QVariantList>

class FFTFilterProcessor : public QObject
{
    Q_OBJECT
public:
    explicit FFTFilterProcessor(QObject *parent = nullptr);
    Q_INVOKABLE double outputBufferAt(const int index, const int p);
    void processBuffer(int16_t* in, const int numFrames);
signals:
    void processingDone(QVector<double> out);
private:
    int m_buffer_length;
    fftw_complex* m_fft_output;
    fftw_plan m_fft_plan;
};

#endif // FFTFILTERPROCESSOR_H
