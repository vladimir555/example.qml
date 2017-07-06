#include "main_.h"

#include <qlogging.h>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QMetaObject>
#include <QGuiApplication>

#include "../utility/assert.h"


using utility::assertExists;


namespace form {


Main::Main()
:
    m_view(&m_engine, nullptr),
    m_buttons(createButtonsByPassword("wrong_password")),
    m_labels_form(getButtonsState())
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

    m_buttons = createButtonsByPassword(password);

    updateFormButtonsState(getButtonsState());
    m_labels_form.updateFormLabelState(getButtonsState());
}


void Main::updateFormButtonsState(QList<bool> const &buttons_state) {
    QMetaObject::invokeMethod(m_window_main, "updateFormButtonsState",
        Q_ARG(QVariant, QVariant::fromValue(buttons_state)));
}


QStringList Main::getButtonsName() {
    QStringList result;
    for (auto const button: m_buttons)
        result.append(button.name);
    return result;
}


QList<bool> Main::getButtonsState() {
    QList<bool> result;
    for (auto const button: m_buttons)
        result.append(button.is_enabled);
    return result;
}


QList<Main::TButton> Main::createButtonsByPassword(QString const &password) {
    auto button = tr("Button");
    // operator password
    if (password == "") {
        return QList<TButton> ({
            {button + "1", true},
            {button + "2", true},
            {button + "3", false},
            {button + "4", false},
            {button + "5", false},
            {button + "6", false}
        });
    }

    // technician password
    if (password == "111") {
        return QList<TButton> ({
            {button + "1", true},
            {button + "2", true},
            {button + "3", true},
            {button + "4", true},
            {button + "5", false},
            {button + "6", false}
        });
    }

    // engineer password
    if (password == "222") {
        return QList<TButton> ({
            {button + "1", true},
            {button + "2", true},
            {button + "3", true},
            {button + "4", true},
            {button + "5", true},
            {button + "6", true}
        });
    }

    // wrong password
    {
        return QList<TButton> ({
            {button + "1", false},
            {button + "2", false},
            {button + "3", false},
            {button + "4", false},
            {button + "5", false},
            {button + "6", false}
        });
    }
}


void Main::onButtonNewWindowClicked() {
    m_labels_form.updateFormLabelState(getButtonsState());
    m_labels_form.show();
}


} // form
