#include "complexbuffermodel.h"

ComplexBufferModel::ComplexBufferModel()
{

}

void ComplexBufferModel::assign(fftw_complex *in, const int len)
{
    m_data = in;
    m_length = len;
}


QModelIndex ComplexBufferModel::index(int row, int column, const QModelIndex &parent) const
{
}

QModelIndex ComplexBufferModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int ComplexBufferModel::rowCount(const QModelIndex &parent) const
{
    return m_length;
}

int ComplexBufferModel::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant ComplexBufferModel::data(const QModelIndex &index, int role) const
{
    QVariant value;
    value = m_data[index.row()][index.column()];
    return value;
}
