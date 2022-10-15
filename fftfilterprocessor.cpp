#include "fftfilterprocessor.h"

FFTFilterProcessor::FFTFilterProcessor(QObject *parent)
    : QObject{parent}
{

}

double FFTFilterProcessor::outputBufferAt(const int index, const int p)
{
    double out = 0;
    out = m_fft_output[index][p];
    return out;
}

void FFTFilterProcessor::processBuffer(int16_t *in, const int numFrames)
{
    emit processingDone(numFrames);
}
