#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "include/backend.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<Backend>("extren",0,1,"ExternFunc");

    QQmlApplicationEngine engine;
    const QUrl url(u"qrc:/SecondTry/main.qml"_qs);
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
