#-------------------------------------------------
#
# Project created by QtCreator 2024-07-21T09:07:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = volantis_assistant
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


SOURCES += main.cpp\
        mainwindow.cpp \
    home_window.cpp \
    about.cpp \
    rule_set_edit_widget.cpp \
    which_rule_set.cpp \
    edit_w.cpp \
    text_style_w.cpp \
    notes_w.cpp \
    check_box_w.cpp \
    buttons_w.cpp \
    url_w.cpp \
    img_w.cpp

HEADERS  += mainwindow.h \
    home_window.h \
    chinese_encoding_enable.h \
    about.h \
    rule_set_edit_widget.h \
    which_rule_set.h \
    values_used_always.h \
    edit_w.h \
    text_style_w.h \
    notes_w.h \
    check_box_w.h \
    buttons_w.h \
    url_w.h \
    img_w.h \
    with_menus.h

FORMS += \
    home_window.ui \
    about.ui \
    rule_set_edit_widget.ui \
    which_rule_set.ui \
    edit_w.ui \
    text_style_w.ui \
    notes_w.ui \
    check_box_w.ui \
    buttons_w.ui \
    url_w.ui \
    img_w.ui

RESOURCES += \
    res.qrc

msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}    //解决中文乱码和常量中含有换行符的问题

DISTFILES +=
