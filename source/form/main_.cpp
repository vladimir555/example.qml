#include "main_.h"

#include <qlogging.h>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QMetaObject>
#include <QGuiApplication>

#include "utility/assert.h"
#include "logic/main__.h"


using utility::assertExists;


namespace form {


Main::Main()
:
    m_view(&m_engine, nullptr),
    m_labels_form()
{
    m_view.rootContext()->setContextProperty("form", this);
    m_view.setSource(QStringLiteral("qrc:/qml/form/main.qml"));

    m_text_field_password = assertExists(
        m_view.findChild<QObject *>("password"),
        "password not found");
    m_window_main = assertExists(
        m_view.findChild<QObject *>("window_main"),
        "window_main not found");
}


void Main::show() {
    m_view.show();
}


void Main::onButtonEnterClicked() {
    auto password = m_text_field_password->property("text").toString();

    qDebug() << "password: " << password;
    logic::Main::instance().updateButtonsByPassword(password);
    qDebug() << logic::Main::instance().getButtonVisibleStates();
    updateFormButtonsState(getButtonVisibleStates());
    m_labels_form.updateFormLabelState();
}


void Main::updateFormButtonsState(QList<bool> const &buttons_state) {
    QMetaObject::invokeMethod(m_window_main, "updateFormButtonsState",
        Q_ARG(QVariant, QVariant::fromValue(buttons_state)));
}


QStringList Main::getButtonNames() {
    return logic::Main::instance().getButtonNames();
}


QList<bool> Main::getButtonVisibleStates() {
    return logic::Main::instance().getButtonVisibleStates();
}


void Main::onButtonNewWindowClicked() {
    m_labels_form.updateFormLabelState();
    m_labels_form.show();
}


} // form
