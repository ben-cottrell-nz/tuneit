#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>
#include <QQuickWindow>
#ifdef Q_OS_ANDROID
#include "audiobufferrecorder_oboe.h"
#else
#include "audiobufferrecorder_rtaudio.h"
#endif
#include <QThread>
#include "fftfilterprocessor.h"
#include "appsettings.h"
#include <QRegularExpression>


class QSGInfo : public QObject
{
    Q_OBJECT
public:
    enum GraphicsApi {
        Unknown,
        Software,
        OpenVG,
        OpenGL,
        Direct3D11,
        Vulkan,
        Metal,
        Null,

        OpenGLRhi = OpenGL,
        Direct3D11Rhi = Direct3D11,
        VulkanRhi = Vulkan,
        MetalRhi = Metal,
        NullRhi = Null
    };
    Q_ENUM(GraphicsApi)
    Q_INVOKABLE QString getRenderingApiName() { return QVariant::fromValue(
            QSGInfo::GraphicsApi(QQuickWindow::graphicsApi())).toString(); }
};

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    AudioBufferRecorder recorder;
    FFTFilterProcessor processor;
    QSGInfo qsgInfo;
    //qDebug() << "Built with FFTW version " << fftw_version;
    QObject::connect(&recorder,
                     &AudioBufferRecorder::bufferReady,
                     &app,
                     [&](int16_t* buffer, int numFrames){
        processor.processBuffer(buffer, AppSettingsInstance()->getSamplingRate(), numFrames);
    });
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("fftProcessor", &processor);
    engine.rootContext()->setContextProperty("audioRecorder", &recorder);
    engine.rootContext()->setContextProperty("qsgInfo", &qsgInfo);
    engine.rootContext()->setContextProperty("appSettings", AppSettingsInstance());
    if (!AppSettingsInstance()->isFirstRun()) {
        AppSettingsInstance()->loadFromDefaultLocation();
    }
    engine.load(url);
    QObject::connect(AppSettingsInstance(), &AppSettings::settingsApplied, &app, [&](){
        recorder.stop();
        recorder.start();
//        AppSettings* settings = AppSettingsInstance();
//        QString audioDevName = settings->getAudioInputDeviceName();
//        int lBracketIndex = audioDevName.indexOf('(');
//        int rBracketIndex = audioDevName.indexOf(')');
//        int deviceID = 0;
//        if (lBracketIndex != -1 && rBracketIndex != -1) {
//            deviceID = audioDevName.sliced(lBracketIndex+1, rBracketIndex-lBracketIndex-1).toUInt();
//        }
    });
    QThread* audioThread/* = new QThread(&app);*/;
    audioThread = QThread::create([&](){
        recorder.start();
    });
    audioThread->start();
    QObject::connect(&app, &QCoreApplication::aboutToQuit, &app, [&](){
        recorder.stop();
        AppSettingsInstance()->saveToDefaultLocation();
        audioThread->deleteLater();
    });
    return app.exec();
}
#include "main.moc"
