#-------------------------------------------------
#
# Project created by QtCreator 2019-10-14T14:05:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = zy_qt_lib
TEMPLATE = app
USE_XDEBUG=1

MOC_DIR = build/moc
OBJECTS_DIR = build/objs

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwidget.cpp \
    tableview/tablemodel_custom.cpp \
    tableview/tableview_custom.cpp \
    tableview/item_delegate_btn.cpp \
    tableview/item_delegate_checkbtn.cpp \
    tableview/test_tableview_widget.cpp \
    date/date_time_edit.cpp \
    date/date_edit.cpp \
    date/calendar_widget.cpp \
    date/test_date_widget.cpp

HEADERS += \
        mainwidget.h \
    data_define.h \
    tableview/item_delegate_btn.h \
    tableview/item_delegate_checkbtn.h \
    tableview/test_tableview_widget.h \
    date/date_time_edit.h \
    date/date_edit.h \
    date/calendar_widget.h \
    date/test_date_widget.h
