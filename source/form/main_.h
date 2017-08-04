#ifndef HEADER_MAIN_0A260B7B_463A_4056_8BFF_1D692C4AAD62
#define HEADER_MAIN_0A260B7B_463A_4056_8BFF_1D692C4AAD62


#include <QQuickView>
#include <QQmlApplicationEngine>

#include "labels.h"


namespace form {


class Main: public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList button_names  READ getButtonNames)
    Q_PROPERTY(QList<bool> button_states READ getButtonVisibleStates)

public:
    Main();
    virtual ~Main() = default;

    void show();

private:
    void updateFormButtonsState(QList<bool> const &button_states);

    QStringList getButtonNames();
    QList<bool> getButtonVisibleStates();

    QQmlApplicationEngine   m_engine;
    QQuickView              m_view;
    QObject                *m_text_field_password;
    QObject                *m_window_main;

    Labels                  m_labels_form;

public slots:
    void onButtonEnterClicked();
    void onButtonNewWindowClicked();
};


} // form


#endif // HEADER_MAIN_0A260B7B_463A_4056_8BFF_1D692C4AAD62
