#include "appsettings.h"
#include <QStandardPaths>
#include <QDir>
#include <QDomDocument>
#include <QStringListModel>

AppSettings::AppSettings(QObject *parent)
    : QObject{parent}
{
    m_configFilePath = QDir(
                QStandardPaths::writableLocation(
                QStandardPaths::StandardLocation::AppConfigLocation)
                ).filePath("config.xml");

}

void AppSettings::loadFromDefaultLocation()
{
    QDomDocument doc;
    if (!QFile::exists(m_configFilePath)) {
        qDebug() << m_configFilePath << " doesn't exist";
        return;
    }
    QFile file(m_configFilePath);
    if (!file.open(QIODevice::ReadOnly)) {
        qDebug() << "failed to open " << m_configFilePath << " for reading";
        return;
    }
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();
    QDomElement rootElem = doc.firstChildElement("config");
    QString inputDevName = rootElem.firstChildElement("inputdevname").firstChild().nodeValue();
    setAudioInputDeviceName(inputDevName);
    setNumInputChannels(rootElem.firstChildElement("numinputchannels").firstChild().nodeValue().toInt());
    setSamplingRate(rootElem.firstChildElement("samplingrate").firstChild().nodeValue().toInt());
}

void AppSettings::saveToDefaultLocation()
{
    QDomDocument doc;
    QDomElement rootElem = doc.createElement("config");
    doc.appendChild(rootElem);
    QDomElement inputDevNameElem = doc.createElement("inputdevname");
    inputDevNameElem.appendChild(doc.createTextNode(m_audioInputDeviceName));
    QDomElement numInputChannelsElem = doc.createElement("numinputchannels");
    numInputChannelsElem.appendChild(doc.createTextNode(QString().setNum(m_numInputChannels)));
    QDomElement samplingRateElem = doc.createElement("samplingrate");
    samplingRateElem.appendChild(doc.createTextNode(QString().setNum(m_samplingRate)));
    rootElem.appendChild(inputDevNameElem);
    rootElem.appendChild(numInputChannelsElem);
    rootElem.appendChild(samplingRateElem);
    QString configFileParentDir = QFileInfo(m_configFilePath).absolutePath();
    if (!QDir(configFileParentDir).exists()) {
        QDir().mkdir(configFileParentDir);
    }
    QFile fileWriter(m_configFilePath);
    if (!fileWriter.open(QIODevice::ReadWrite)) {
        qDebug() << "failed to open " << m_configFilePath << " for writing";
        return;
    }
    fileWriter.write(doc.toByteArray());
    fileWriter.close();
}

void AppSettings::apply()
{
    emit settingsApplied();
}

QString AppSettings::getAudioInputDeviceName()
{
    return m_audioInputDeviceName;
}

void AppSettings::setAudioInputDeviceName(QString &value)
{
    m_audioInputDeviceName = value;
    emit audioInputDeviceNameChanged(m_audioInputDeviceName);
}

uint32_t AppSettings::getNumInputChannels()
{
    return m_numInputChannels;
}

void AppSettings::setNumInputChannels(uint32_t value)
{
    m_numInputChannels = value;
    emit numInputChannelsChanged(m_numInputChannels);
}

uint32_t AppSettings::getSamplingRate()
{
    return m_samplingRate;
}

void AppSettings::setSamplingRate(uint32_t value)
{
    m_samplingRate = value;
    emit samplingRateChanged(m_samplingRate);
}

AppSettings::BarChartHorizontalScaling AppSettings::getBarChartHorizontalScaling()
{
    return m_barChartHorizontalScaling;
}

QList<QString> AppSettings::getAvailableInputDevNames()
{
    return m_availableInputDevNames;
}

QList<uint32_t> AppSettings::getAvailableNumInputChannels()
{
    return m_availableNumInputChannels;
}

QList<uint32_t> AppSettings::getAvailableSamplingRates()
{
    return m_availableSamplingRates;
}

void AppSettings::setAvailableInputDevNames(QList<QString>&& value)
{
    m_availableInputDevNames = QList<QString>(value);
}

void AppSettings::setAvailableNumInputChannels(QList<uint32_t>&& value)
{
    m_availableNumInputChannels = QList<uint32_t>(value);
}

void AppSettings::setAvailableSamplingRates(QList<uint32_t>&& value)
{
    m_availableSamplingRates = QList<uint32_t>(value);
}

bool AppSettings::isFirstRun()
{
    return !QFile::exists(m_configFilePath);
}

uint32_t AppSettings::getAudioInputDeviceID() {
    int lBracket = 0, rBracket = 0;
    lBracket = m_audioInputDeviceName.indexOf('(');
    rBracket = m_audioInputDeviceName.indexOf(')');
    if (lBracket != -1 && rBracket != -1) {
        return m_audioInputDeviceName.sliced(lBracket+1,rBracket-lBracket-1).toInt();
    }
    return 0;
}

AppSettings* AppSettingsInstance()
{
    static AppSettings instance;
    return &instance;
}


//QModelIndex AppSettingsModel::index(int row, int column, const QModelIndex &parent) const
//{
//}

//QModelIndex AppSettingsModel::parent(const QModelIndex &child) const
//{
//}

//int AppSettingsModel::rowCount(const QModelIndex &parent) const
//{
//}

//int AppSettingsModel::columnCount(const QModelIndex &parent) const
//{
//}

//QVariant AppSettingsModel::data(const QModelIndex &index, int role) const
//{
//}
