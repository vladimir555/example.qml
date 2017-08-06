#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickStyle>
#include <qlogging.h>
#include <QTranslator>

#include "form/main_.h"
#include "logic/main__.h"


int main(int argc, char *argv[]) {
    QGuiApplication application(argc, argv);

    QQuickStyle::setStyle("Universal");

    QTranslator translator;
    bool is_loaded = translator.load(QStringLiteral(":/locale/application_ru.qm"));
    if (is_loaded)
        QGuiApplication::installTranslator(&translator);
    else
        qDebug() << "translatinon not loaded";

    logic::Main::instance().initialize();
    form::Main main_form;
    main_form.show();

    return application.exec();
}
