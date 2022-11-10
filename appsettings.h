#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QObject>
#include <QHash>

class AudioBufferRecorder;

class AppSettings : public QObject
{
    Q_OBJECT
public:
    enum BarChartHorizontalScaling {
      Linear, Logarithmic
    };
    Q_ENUM(BarChartHorizontalScaling)
    Q_PROPERTY(QString audioInputDeviceName
               READ getAudioInputDeviceName
               WRITE setAudioInputDeviceName
               NOTIFY audioInputDeviceNameChanged)
    Q_PROPERTY(uint32_t numInputChannels
               READ getNumInputChannels
               WRITE setNumInputChannels
               NOTIFY numInputChannelsChanged
               )
    Q_PROPERTY(uint32_t samplingRate
               READ getSamplingRate
               WRITE setSamplingRate
               NOTIFY samplingRateChanged)
    Q_PROPERTY(BarChartHorizontalScaling barChartHorizontalScaling
               READ getBarChartHorizontalScaling)
    explicit AppSettings(QObject *parent = nullptr);
    //called when app is starting
    void loadFromDefaultLocation();
    //called when the app is about to exit
    void saveToDefaultLocation();
    void apply();
    uint32_t getAudioInputDeviceID();
    QString getAudioInputDeviceName();
    void setAudioInputDeviceName(QString& value);
    uint32_t getNumInputChannels();
    void setNumInputChannels(uint32_t value);
    uint32_t getSamplingRate();
    void setSamplingRate(uint32_t value);
    BarChartHorizontalScaling getBarChartHorizontalScaling();
    //lists of options
    Q_INVOKABLE QList<QString> getAvailableInputDevNames();
    Q_INVOKABLE QList<uint32_t> getAvailableNumInputChannels();
    Q_INVOKABLE QList<uint32_t> getAvailableSamplingRates();
    //moves values into member variables
    void setAvailableInputDevNames(QList<QString>&& value);
    void setAvailableNumInputChannels(QList<uint32_t>&& value);
    void setAvailableSamplingRates(QList<uint32_t>&& value);
    //used by AudioBufferRecord to set default settings
    bool isFirstRun();
signals:
    void settingsApplied();
    void audioInputDeviceNameChanged(QString& value);
    void numInputChannelsChanged(uint32_t value);
    void samplingRateChanged(uint32_t value);
private:
    QString m_configFilePath;
    BarChartHorizontalScaling m_barChartHorizontalScaling = BarChartHorizontalScaling::Linear;
    //device name with id in brackets
    //these are changed when the configuration data has been parsed from a
    //file, or set by AudioBufferRecord::start when the file doesn't exist.
    QString m_audioInputDeviceName;
    uint32_t m_numInputChannels;
    uint32_t m_samplingRate;
    //used to populate state data for items in QML engine, ie: ComboBox's
    //these are changed each time the application starts
    QList<QString> m_availableInputDevNames;
    QList<uint32_t> m_availableNumInputChannels;
    QList<uint32_t> m_availableSamplingRates;
};

AppSettings* AppSettingsInstance();
#endif // APPSETTINGS_H
