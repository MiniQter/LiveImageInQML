#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include "liveimageitem.h"
#include "liveimageprovider.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    qmlRegisterType<LiveImageItem>("com.mycompany.qmlcomponents", 1, 0, "LiveImageItem");

    LiveImageProvider *liveImageProvider(new LiveImageProvider());
    engine.rootContext()->setContextProperty("liveImageProvider", liveImageProvider);
    engine.addImageProvider("live", liveImageProvider);
    // connect updateImage with your live image source

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
