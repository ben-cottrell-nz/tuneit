#ifndef COMPLEXBUFFERMODEL_H
#define COMPLEXBUFFERMODEL_H

#include <QAbstractItemModel>
#include <QObject>
#include "fftw3.h"

//index(), parent(), rowCount(), columnCount(), and data()
class ComplexBufferModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ComplexBufferModel();
    void assign(fftw_complex* in, const int len);

    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
private:
    fftw_complex* m_data;
    int m_length;
};

#endif // COMPLEXBUFFERMODEL_H
