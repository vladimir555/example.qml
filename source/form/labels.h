#ifndef HEADER_LABELS_C25D050C_95D9_4508_BD89_A9E7D34333F5
#define HEADER_LABELS_C25D050C_95D9_4508_BD89_A9E7D34333F5


#include <QQuickView>
#include <QQmlEngine>
#include <QList>


namespace form {


class Labels : public QObject {
public:
    Labels(QList<bool> const &buttons_state);
    virtual ~Labels() = default;

    void show();

private:
    QQmlEngine              m_engine;
    QQuickView              m_view;
    //QList<TButton>          m_buttons;
};


} // form


#endif // HEADER_LABELS_C25D050C_95D9_4508_BD89_A9E7D34333F5
