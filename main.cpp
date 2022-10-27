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

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    AudioBufferRecorder recorder;
    FFTFilterProcessor processor;
    //qDebug() << "Built with FFTW version " << fftw_version;
    QObject::connect(&recorder,
                     &AudioBufferRecorder::bufferReady,
                     &app,
                     [&](int16_t* buffer, int numFrames){
        processor.processBuffer(buffer, recorder.m_sampleRate, numFrames);
    });
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.rootContext()->setContextProperty("fftProcessor", &processor);
    engine.rootContext()->setContextProperty("audioRecorder", &recorder);
    engine.load(url);
    QThread* audioThread/* = new QThread(&app);*/;
    audioThread = QThread::create([&](){
        recorder.start();
    });
    audioThread->start();
    QObject::connect(&app, &QCoreApplication::aboutToQuit, &app, [&](){
        recorder.stop();
        audioThread->deleteLater();
    });
    return app.exec();
}
