#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "httpclient.h"
#include "blemgr.h"
#include <QDebug>
#include <Qt>
#include <QZXing.h>
#include <QDebug>
int main(int argc, char *argv[])
{
    qDebug() << "start app";
    QLoggingCategory::setFilterRules(QStringLiteral("qt.bluetooth* = true"));
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    HttpClient m_httpClient;
    bleMgr m_bleMgr;
    QQmlApplicationEngine engine;
    QZXing::registerQMLTypes();
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));
    engine.rootContext()->setContextProperty("_httpClient",&m_httpClient);
    engine.rootContext()->setContextProperty("_bleMgr",&m_bleMgr);

    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
