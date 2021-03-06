#-------------------------------------------------
#
# Project created by QtCreator 2017-06-30T11:54:34
#
#-------------------------------------------------

QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += qml quick quickcontrols2

TARGET = example.qml
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    source/main.cpp \
    source/form/main_.cpp \
    source/form/labels.cpp \
    source/logic/main__.cpp \

HEADERS += \
    source/form/main_.h \
    source/form/labels.h \
    source/logic/main__.h \
    source/utility/assert.h \
    source/utility/smart_ptr.h \
    source/utility/pattern/initializable.h \
    source/utility/pattern/singleton.h \
    source/utility/pattern/non_movable.h \
    source/utility/pattern/non_copyable.h

INCLUDEPATH += source/

FORMS +=

DISTFILES += \
    qml/form/main.qml \
    qml/form/labels.qml \
    locale/application_ru.ts

RESOURCES += \
    application.qrc

TRANSLATIONS += locale/application_ru.ts

lupdate_only {
    SOURCES += \
        qml/form/main.qml \
        qml/form/labels.qml
}
