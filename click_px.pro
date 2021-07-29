#-------------------------------------------------
#
# Project created by QtCreator 2021-07-13T17:01:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = click_px
TEMPLATE = app

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
        mainwindow.cpp \
    z.cpp \
    scenario.cpp \
    vehicle.cpp

HEADERS += \
        mainwindow.h \
    scenario.h \
    vehicle.h

FORMS += \
        mainwindow.ui



win32{
INCLUDEPATH += "C:/Qt/Opencv3/include"                                                             ###
INCLUDEPATH += "C:/Qt/Opencv3/include/opencv"
LIBS        += -L"C:/Qt/Opencv3/vs11/lib/"  -lopencv_calib3d343 \
                                            -lopencv_core343 \
                                            -lopencv_dnn343 \
                                            -lopencv_features2d343 \
                                            -lopencv_flann343 \
                                            -lopencv_highgui343 \
                                            -lopencv_imgcodecs343 \
                                            -lopencv_imgproc343 \
                                            -lopencv_ml343 \
                                            -lopencv_objdetect343 \
                                            -lopencv_photo343 \
                                            -lopencv_shape343 \
                                            -lopencv_stitching343 \
                                            -lopencv_superres343 \
                                            -lopencv_video343 \
                                            -lopencv_videoio343 \
                                            -lopencv_videostab343

}

DISTFILES += \
    Vehicles.csv
