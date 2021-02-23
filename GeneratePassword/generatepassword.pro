#-------------------------------------------------
#
# Project created by QtCreator 2021-02-23T17:33:29
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GeneratePassword
TEMPLATE = app

win32: RC_ICONS = $$PWD/GeneratePassword.ico

SOURCES += main.cpp\
        generatepassword.cpp

HEADERS  += generatepassword.h

FORMS    += generatepassword.ui
