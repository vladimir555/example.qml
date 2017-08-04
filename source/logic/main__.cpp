#include "main__.h"


namespace logic {


void Main::updateButtonsByPassword(QString const &password) {
    auto button = tr("Button");
    // operator password
    if (password == "") {
        m_button_states = QList<TButtonState> ({
            {button + "1", true},
            {button + "2", true},
            {button + "3", false},
            {button + "4", false},
            {button + "5", false},
            {button + "6", false}
        });
        return;
    }

    // technician password
    if (password == "111") {
        m_button_states = QList<TButtonState> ({
            {button + "1", true},
            {button + "2", true},
            {button + "3", true},
            {button + "4", true},
            {button + "5", false},
            {button + "6", false}
        });
        return;
    }

    // engineer password
    if (password == "222") {
        m_button_states = QList<TButtonState> ({
            {button + "1", true},
            {button + "2", true},
            {button + "3", true},
            {button + "4", true},
            {button + "5", true},
            {button + "6", true}
        });
        return;
    }

    // wrong password
    {
        m_button_states = QList<TButtonState> ({
            {button + "1", false},
            {button + "2", false},
            {button + "3", false},
            {button + "4", false},
            {button + "5", false},
            {button + "6", false}
        });
    }
}


QList<bool> Main::getButtonVisibleStates() const {
    QList<bool> result;
    for (auto const &button_state: m_button_states)
        result.push_back(button_state.is_enabled);
    return result;
}


QStringList Main::getButtonNames() const {
    QStringList result;
    for (auto const &button_state: m_button_states)
        result.push_back(button_state.name);
    return result;
}


void Main::initialize() {
    updateButtonsByPassword("");
}


void Main::finalize() {

}


} // logic
