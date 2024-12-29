#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <portmanager.h>
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    PortManager portManager;
    engine.rootContext()->setContextProperty("portManager", &portManager);


    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("RS232CPortTransmission", "Main");



    return app.exec();
}
