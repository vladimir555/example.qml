#ifndef HEADER_MAIN_FC29FF1F_038C_413E_935D_4E9D21BDB054
#define HEADER_MAIN_FC29FF1F_038C_413E_935D_4E9D21BDB054


#include <QObject>

#include "utility/pattern/singleton.h"
#include "utility/pattern/initializable.h"


// business logic
namespace logic {


class Main:
    public QObject,
    public utility::pattern::Singleton<Main>,
    public utility::pattern::IInitializable
{
public:
    void updateButtonsByPassword(QString const &password);
    QList<bool> getButtonVisibleStates() const;
    QStringList getButtonNames() const;

    void initialize() override;
    void finalize() override;

private:
    Main() = default;
    virtual ~Main() = default;
    friend class utility::pattern::Singleton<Main>;

    struct TButtonState {
        QString name;
        bool    is_enabled;
    };

    QList<TButtonState> m_button_states;
};


} // logic


#endif // HEADER_MAIN_FC29FF1F_038C_413E_935D_4E9D21BDB054
