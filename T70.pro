QT       += core gui network
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

# Для Миши
QMAKE_CXXFLAGS += -std=gnu++11
QMAKE_CXXFLAGS += -lrt

QMAKE_CXXFLAGS_RELEASE += -std=gnu++11
QMAKE_CXXFLAGS_RELEASE += -lrt

QMAKE_LFLAGS += -Wl,--copy-dt-needed-entries
#----------------------------------------------
CONFIG += debug
CONFIG += c++17

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    sourceApp/main.cpp \
    sourceApp/mainwindow.cpp \
    sourceApp/utilTimeClassQt.cpp\
        sourceApp/threadModel.cpp  \
    sourcePlaneSystem/aircondition_10.cpp \
    sourcePlaneSystem/aircondition_12.cpp \
    sourcePlaneSystem/aircondition_13.cpp \
    sourcePlaneSystem/aircondition_14.cpp \
    sourcePlaneSystem/aircondition_15.cpp \
    sourcePlaneSystem/aircondition_16.cpp \
    sourcePlaneSystem/aircondition_17.cpp \
    sourcePlaneSystem/aircondition_1_2_3.cpp \
    sourcePlaneSystem/aircondition_4_5.cpp \
    sourcePlaneSystem/aircondition_6_7.cpp \
    sourcePlaneSystem/aircondition_8.cpp \
    sourcePlaneSystem/aircondition_9.cpp \
    sourcePlaneSystem/aircondition_int.cpp \
    sourcePlaneSystem/airconditioni_11.cpp \
    sourcePlaneSystem/algorithms.cpp \
    sourcePlaneSystem/allElCons.cpp \
    sourcePlaneSystem/antifire_1.cpp \
    sourcePlaneSystem/antifire_2.cpp \
    sourcePlaneSystem/antifire_3.cpp \
    sourcePlaneSystem/antifire_int.cpp \
    sourcePlaneSystem/antiicing_1.cpp \
    sourcePlaneSystem/antiicing_2.cpp \
    sourcePlaneSystem/antiicing_3.cpp \
    sourcePlaneSystem/antiicing_4.cpp \
    sourcePlaneSystem/antiicing_5.cpp \
    sourcePlaneSystem/antiicing_6.cpp \
    sourcePlaneSystem/antiicing_int.cpp \
    sourcePlaneSystem/bailout_1_2.cpp \
    sourcePlaneSystem/bailout_int.cpp \
    sourcePlaneSystem/brakes_1.cpp \
    sourcePlaneSystem/brakes_2.cpp \
    sourcePlaneSystem/brakes_3.cpp \
    sourcePlaneSystem/brakes_4.cpp \
    sourcePlaneSystem/brakes_5.cpp \
    sourcePlaneSystem/brakes_6.cpp \
    sourcePlaneSystem/brakes_int.cpp \
    sourcePlaneSystem/bss.cpp \
    sourcePlaneSystem/cabinlighting_1.cpp \
    sourcePlaneSystem/cabinlighting_10.cpp \
    sourcePlaneSystem/cabinlighting_2.cpp \
    sourcePlaneSystem/cabinlighting_3.cpp \
    sourcePlaneSystem/cabinlighting_4.cpp \
    sourcePlaneSystem/cabinlighting_5.cpp \
    sourcePlaneSystem/cabinlighting_6.cpp \
    sourcePlaneSystem/cabinlighting_7.cpp \
    sourcePlaneSystem/cabinlighting_8.cpp \
    sourcePlaneSystem/cabinlighting_9.cpp \
    sourcePlaneSystem/cabinlighting_int.cpp \
    sourcePlaneSystem/databasemanager.cpp \
    sourcePlaneSystem/emergencyalarm_1.cpp \
    sourcePlaneSystem/emergencyalarm_int.cpp \
    sourcePlaneSystem/exchange.cpp \
    sourcePlaneSystem/hydro_1.cpp \
    sourcePlaneSystem/hydro_10.cpp \
    sourcePlaneSystem/hydro_2.cpp \
    sourcePlaneSystem/hydro_3.cpp \
    sourcePlaneSystem/hydro_4.cpp \
    sourcePlaneSystem/hydro_5.cpp \
    sourcePlaneSystem/hydro_6.cpp \
    sourcePlaneSystem/hydro_7.cpp \
    sourcePlaneSystem/hydro_8.cpp \
    sourcePlaneSystem/hydro_9.cpp \
    sourcePlaneSystem/hydro_int.cpp \
    sourcePlaneSystem/input_feed.cpp \
    sourcePlaneSystem/interfacing.cpp \
    sourcePlaneSystem/land_comstations.cpp \
    sourcePlaneSystem/landinggear_event.cpp \
    sourcePlaneSystem/landinggear_int.cpp \
    sourcePlaneSystem/landinggear_old.cpp \
    sourcePlaneSystem/pneumatic_1.cpp \
    sourcePlaneSystem/pneumatic_int.cpp \
    sourcePlaneSystem/powerdc_1.cpp \
    sourcePlaneSystem/powerdc_11.cpp \
    sourcePlaneSystem/powerdc_12.cpp \
    sourcePlaneSystem/powerdc_13.cpp \
    sourcePlaneSystem/powerdc_14.cpp \
    sourcePlaneSystem/powerdc_15.cpp \
    sourcePlaneSystem/powerdc_16.cpp \
    sourcePlaneSystem/powerdc_20.cpp \
    sourcePlaneSystem/powerdc_21.cpp \
    sourcePlaneSystem/powerdc_2_3.cpp \
    sourcePlaneSystem/powerdc_4.cpp \
    sourcePlaneSystem/powerdc_5_6.cpp \
    sourcePlaneSystem/powerdc_7.cpp \
    sourcePlaneSystem/powerdc_8.cpp \
    sourcePlaneSystem/powerdc_9_10.cpp \
    sourcePlaneSystem/powerdc_int.cpp \
    sourcePlaneSystem/presure.cpp \
    sourcePlaneSystem/presure_int.cpp \
    sourcePlaneSystem/station.cpp \
    sourcePlaneSystem/stationsdao.cpp \
    sourcePlaneSystem/switches.cpp \
    sourcePlaneSystem/uks.cpp \
    sourcePlaneSystem/vim95.cpp \
    sourcePlaneSystem/wind_functions.cpp \
    sourcePlaneSystem/wingsmech_1.cpp \
    sourcePlaneSystem/wingsmech_2.cpp \
    sourcePlaneSystem/wingsmech_3.cpp \
    sourcePlaneSystem/wingsmech_4.cpp \
    sourcePlaneSystem/wingsmech_int.cpp
    
   

HEADERS += \
    externStruct/Struct_DeviceConnect.h \
    externStruct/Struct_FromRmiOper.h \
    externStruct/Struct_FromRmiPilot.h \
    externStruct/Struct_ISU.h \
    externStruct/Struct_ToRmiNavig.h \
    sourceApp/mainwindow.h \
    sourceApp/utilTimeClassQt.h\
    sourceApp/threadModel.h \ \
    sourcePlaneSystem/aircondition_10.h \
    sourcePlaneSystem/aircondition_12.h \
    sourcePlaneSystem/aircondition_13.h \
    sourcePlaneSystem/aircondition_14.h \
    sourcePlaneSystem/aircondition_15.h \
    sourcePlaneSystem/aircondition_16.h \
    sourcePlaneSystem/aircondition_17.h \
    sourcePlaneSystem/aircondition_1_2_3.h \
    sourcePlaneSystem/aircondition_4_5.h \
    sourcePlaneSystem/aircondition_6_7.h \
    sourcePlaneSystem/aircondition_8.h \
    sourcePlaneSystem/aircondition_9.h \
    sourcePlaneSystem/aircondition_int.h \
    sourcePlaneSystem/airconditioni_11.h \
    sourcePlaneSystem/algorithms.h \
    sourcePlaneSystem/allElCons.h \
    sourcePlaneSystem/antifire_1.h \
    sourcePlaneSystem/antifire_2.h \
    sourcePlaneSystem/antifire_3.h \
    sourcePlaneSystem/antifire_int.h \
    sourcePlaneSystem/antiicing_1.h \
    sourcePlaneSystem/antiicing_2.h \
    sourcePlaneSystem/antiicing_3.h \
    sourcePlaneSystem/antiicing_4.h \
    sourcePlaneSystem/antiicing_5.h \
    sourcePlaneSystem/antiicing_6.h \
    sourcePlaneSystem/antiicing_int.h \
    sourcePlaneSystem/bailout_1_2.h \
    sourcePlaneSystem/bailout_int.h \
    sourcePlaneSystem/brakes_1.h \
    sourcePlaneSystem/brakes_2.h \
    sourcePlaneSystem/brakes_3.h \
    sourcePlaneSystem/brakes_4.h \
    sourcePlaneSystem/brakes_5.h \
    sourcePlaneSystem/brakes_6.h \
    sourcePlaneSystem/brakes_int.h \
    sourcePlaneSystem/bss.h \
    sourcePlaneSystem/cabinlighting_1.h \
    sourcePlaneSystem/cabinlighting_10.h \
    sourcePlaneSystem/cabinlighting_2.h \
    sourcePlaneSystem/cabinlighting_3.h \
    sourcePlaneSystem/cabinlighting_4.h \
    sourcePlaneSystem/cabinlighting_5.h \
    sourcePlaneSystem/cabinlighting_6.h \
    sourcePlaneSystem/cabinlighting_7.h \
    sourcePlaneSystem/cabinlighting_8.h \
    sourcePlaneSystem/cabinlighting_9.h \
    sourcePlaneSystem/cabinlighting_int.h \
    sourcePlaneSystem/databasemanager.h \
    sourcePlaneSystem/emergencyalarm_1.h \
    sourcePlaneSystem/emergencyalarm_int.h \
    sourcePlaneSystem/exchange.h \
    sourcePlaneSystem/hydro_1.h \
    sourcePlaneSystem/hydro_10.h \
    sourcePlaneSystem/hydro_2.h \
    sourcePlaneSystem/hydro_3.h \
    sourcePlaneSystem/hydro_4.h \
    sourcePlaneSystem/hydro_5.h \
    sourcePlaneSystem/hydro_6.h \
    sourcePlaneSystem/hydro_7.h \
    sourcePlaneSystem/hydro_8.h \
    sourcePlaneSystem/hydro_9.h \
    sourcePlaneSystem/hydro_int.h \
    sourcePlaneSystem/input_feed.h \
    sourcePlaneSystem/interfacing.h \
    sourcePlaneSystem/land_comstations.h \
    sourcePlaneSystem/landinggear_event.h \
    sourcePlaneSystem/landinggear_int.h \
    sourcePlaneSystem/landinggear_old.h \
    sourcePlaneSystem/mainwindow.h \
    sourcePlaneSystem/pneumatic_1.h \
    sourcePlaneSystem/pneumatic_int.h \
    sourcePlaneSystem/powerdc_1.h \
    sourcePlaneSystem/powerdc_11.h \
    sourcePlaneSystem/powerdc_12.h \
    sourcePlaneSystem/powerdc_13.h \
    sourcePlaneSystem/powerdc_14.h \
    sourcePlaneSystem/powerdc_15.h \
    sourcePlaneSystem/powerdc_16.h \
    sourcePlaneSystem/powerdc_20.h \
    sourcePlaneSystem/powerdc_21.h \
    sourcePlaneSystem/powerdc_2_3.h \
    sourcePlaneSystem/powerdc_4.h \
    sourcePlaneSystem/powerdc_5_6.h \
    sourcePlaneSystem/powerdc_7.h \
    sourcePlaneSystem/powerdc_8.h \
    sourcePlaneSystem/powerdc_9_10.h \
    sourcePlaneSystem/powerdc_int.h \
    sourcePlaneSystem/presure.h \
    sourcePlaneSystem/presure_int.h \
    sourcePlaneSystem/station.h \
    sourcePlaneSystem/stationsdao.h \
    sourcePlaneSystem/switches.h \
    sourcePlaneSystem/uks.h \
    sourcePlaneSystem/vim95.h \
    sourcePlaneSystem/wind_functions.h \
    sourcePlaneSystem/wingsmech_1.h \
    sourcePlaneSystem/wingsmech_2.h \
    sourcePlaneSystem/wingsmech_3.h \
    sourcePlaneSystem/wingsmech_4.h \
    sourcePlaneSystem/wingsmech_int.h

FORMS += \
    sourceUI/T70_Win.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

unix: LIBS += -lbiodaq
