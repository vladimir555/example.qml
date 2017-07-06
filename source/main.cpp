#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <qlogging.h>
#include <QTranslator>

#include "form/main_.h"


int main(int argc, char *argv[]) {
    QGuiApplication application(argc, argv);

    QQuickStyle::setStyle("Universal");

    QTranslator translator;
    translator.load(
        "application_ru.ts");
    qApp->installTranslator(&translator);

    try {
        form::Main main_form;
        main_form.show();

        return application.exec();
    } catch (std::exception const &e) {
        qDebug() << e.what();
    }

    return application.exec();

//    engine.load(QUrl(QStringLiteral("qrc:/qml/form/main.qml")));
//    engine.load(QUrl(QStringLiteral("qrc:/qml/form/labels.qml")));
//    engine.load(QUrl(QStringLiteral("qrc:/qml/form/labels.qml")));

}
