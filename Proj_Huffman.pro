#-------------------------------------------------
#
# Project created by QtCreator 2014-12-30T16:15:44
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proj_Huffman
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    classHuffmanTree.cpp \

HEADERS  += mainwindow.h \
    structs.h \
    comm.h \
    classHuffmanTree.h

FORMS    += mainwindow.ui

RESOURCES  +=spreadsheet.qrc

OTHER_FILES += \
    tags \
    Proj_Huffman.pro.user \
    test.in \
    bg.png
