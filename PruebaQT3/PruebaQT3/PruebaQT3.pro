#-------------------------------------------------
#
# Project created by QtCreator 2013-12-23T13:10:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PruebaQT3
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp \
    thread.cpp

LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\PruebaDLL3.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_calib3d242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_contrib242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_core242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_features2d242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_flann242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_gpu242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_highgui242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_imgproc242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_legacy242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_ml242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_nonfree242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_objdetect242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_photo242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_stitching242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_video242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\libopencv_videostab242.dll"
LIBS += "D:\Users\gcucho\Desktop\COMPUTER VISION\Proyecto IS\PruebaQT3\Release\release\opencv_ffmpeg242.dll"

HEADERS  += dialog.h \
    ../Release/ui_dialog.h \
    main.h \
    thread.h \
    structures.h

FORMS    += dialog.ui

OTHER_FILES +=

RESOURCES += \
    resource.qrc

RC_FILE = myapp.rc
