#include "main_.h"

#include <qlogging.h>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQmlComponent>
#include <QMetaObject>

#include "../utility/assert.h"


using utility::assertExists;


namespace form {


Main::Main()
:
    m_view(&m_engine, nullptr),
    m_buttons {
        {"button1", false},
        {"button2", false},
        {"button3", false},
        {"button4", false},
        {"button5", false},
        {"button6", false}
    }
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
    // operator password
    if (password == "") {
        return QList<TButton> ({
            {"button1", true},
            {"button2", true},
            {"button3", false},
            {"button4", false},
            {"button5", false},
            {"button6", false}
        });
    }

    // technician password
    if (password == "111") {
        return QList<TButton> ({
            {"button1", true},
            {"button2", true},
            {"button3", true},
            {"button4", true},
            {"button5", false},
            {"button6", false}
        });
    }

    // engineer password
    if (password == "222") {
        return QList<TButton> ({
            {"button1", true},
            {"button2", true},
            {"button3", true},
            {"button4", true},
            {"button5", true},
            {"button6", true}
        });
    }

    // wrong password
    {
        return QList<TButton> ({
            {"button1", false},
            {"button2", false},
            {"button3", false},
            {"button4", false},
            {"button5", false},
            {"button6", false}
        });
    }
}


} // form
