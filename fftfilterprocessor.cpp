#include "fftfilterprocessor.h"
#include "fftw3.h"

FFTFilterProcessor::FFTFilterProcessor(QObject *parent)
    : QObject{parent}
{
    m_buffer_length = 512;
    m_in_buffer = std::vector<double>(m_buffer_length,0);
    m_fft_output = (fftw_complex*)fftw_malloc(sizeof(fftw_complex)*m_buffer_length);
    m_fft_plan = fftw_plan_dft_r2c_1d(m_buffer_length,
                                      m_in_buffer.data(),
                                      m_fft_output,
                                      FFTW_ESTIMATE);
}

FFTFilterProcessor::~FFTFilterProcessor()
{
    fftw_destroy_plan(m_fft_plan);
    fftw_free(m_fft_output);
}

double FFTFilterProcessor::outputBufferAt(const int index, const int p)
{
    double out = 0;
    out = m_fft_output[index][p];
    return out;
}

QList<qreal> FFTFilterProcessor::outputBufferList()
{
    QList<qreal> list(m_processed_frames,0);
    for (int i=0;i<m_processed_frames;i++) {
        //square the sum of re^2 + im^2 to get absolute value
        list.append(
                    sqrt(
                        pow(m_fft_output[i][0],2) +
                        pow(m_fft_output[i][1],2)
                    )
                );
    }
    return list;
}

QString FFTFilterProcessor::getPeakScientificNote()
{

}

void FFTFilterProcessor::processBuffer(int16_t *in, const int numFrames)
{
    // https://github.com/audacity/audacity/blob/c5ebc396eb06857b4509101fdd2b0620dc0658b3/src/FFT.cpp#L344
    const double multiplier = 2 * M_PI / numFrames;
    static const double coeff0 = 0.54, coeff1 = -0.46;
    for (int i=0;i<numFrames;i++) {
        m_in_buffer[i] = (double)in[i] / std::numeric_limits<int16_t>::max();
        m_in_buffer[i] *= coeff0 + coeff1 * cos(i * multiplier);
    }
    fftw_execute(m_fft_plan);
    m_processed_frames = numFrames;
    emit processingDone(numFrames, outputBufferList());
}
