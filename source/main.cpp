#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <QtDebug>
#include <QFont>

int main(int argc, char *argv[]) {
    QGuiApplication application(argc, argv);

    qDebug() << "start";

    QFont font(QFont().defaultFamily(), 20);

    application.setFont(font);

    QQmlApplicationEngine engine;

    QQuickStyle::setStyle("Material");

    engine.load(QUrl(QStringLiteral("qrc:/qml/form/main.qml")));
    engine.load(QUrl(QStringLiteral("qrc:/qml/form/labels.qml")));

    return application.exec();
}
