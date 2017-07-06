#ifndef HEADER_MAIN_0A260B7B_463A_4056_8BFF_1D692C4AAD62
#define HEADER_MAIN_0A260B7B_463A_4056_8BFF_1D692C4AAD62


#include <QQuickView>
#include <QQmlApplicationEngine>

#include "labels.h"


namespace form {


class Main: public QObject {
    Q_OBJECT
    Q_PROPERTY(QStringList buttons_name READ getButtonsName)
    Q_PROPERTY(QList<bool> buttons_state READ getButtonsState)

public:
    Main();
    virtual ~Main() = default;

    void show();

private:
    void updateFormButtonsState(QList<bool> const &buttons_state);

    QStringList getButtonsName();
    QList<bool> getButtonsState();

    struct TButton {
        QString name;
        bool    is_enabled;
    };

    static QList<TButton>   createButtonsByPassword(QString const &password);

    QQmlApplicationEngine   m_engine;
    QQuickView              m_view;
    QList<TButton>          m_buttons;
    QObject                *m_text_field_password;
    QObject                *m_window_main;

    Labels                  m_labels_form;

public slots:
    void onButtonEnterClicked();
    void onButtonNewWindowClicked();
};


} // form


#endif // HEADER_MAIN_0A260B7B_463A_4056_8BFF_1D692C4AAD62
