#include "labels.h"

#include <QQmlContext>

#include "utility/assert.h"

#include "logic/main__.h"


using utility::assertExists;


namespace form {


Labels::Labels()
:
    m_view(&m_engine, nullptr)
{
    m_view.rootContext()->setContextProperty("form", this);
    m_view.setSource(QStringLiteral("qrc:/qml/form/labels.qml"));

    m_window_labels = assertExists(
        m_view.findChild<QObject *>("window_labels"),
        "window_labels not found");
}


void Labels::show() {
    m_view.show();
}


void Labels::updateFormLabelState() {
    QMetaObject::invokeMethod(m_window_labels, "updateFormLabelsState",
        Q_ARG(QVariant, QVariant::fromValue(logic::Main::instance().getButtonVisibleStates())));
}


} // form
