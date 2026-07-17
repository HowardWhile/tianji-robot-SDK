#-------------------------------------------------
#
# Project created by QtCreator 2026-07-06T09:19:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
//CONFIG += console
TARGET = piano
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += CMPL_WIN L1_SDK_EXPORTS

win32: LIBS += -lws2_32 -lwinmm


# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    C_SDK/FXUtility/FXCfg/CfgBase.cpp \
    C_SDK/FXUtility/FXMath/FXMath.cpp \
    C_SDK/FXUtility/FXMath/FXMatrix.cpp \
    C_SDK/FileClient/FXFileClient.cpp \
    C_SDK/FileClient/FileOP.cpp \
    C_SDK/FileClient/Parser.cpp \
    C_SDK/FileClient/TCPAgent.cpp \
    C_SDK/FileClient/TCPFileClient.cpp \
    C_SDK/Kinematics/ArmKinematics/FXArmKinematics.cpp \
    C_SDK/Kinematics/ArmKinematics/FXKinematics.cpp \
    C_SDK/Kinematics/DynaIdent/FXDynaIndentification.cpp \
    C_SDK/Kinematics/KineCommon/FXDG.cpp \
    C_SDK/Kinematics/KineCommon/FXEnviroment.cpp \
    C_SDK/Kinematics/KineCommon/FXLog.cpp \
    C_SDK/Kinematics/KineCommon/PointSet.cpp \
    C_SDK/Kinematics/L0KineMotion.cpp \
    C_SDK/Kinematics/MotionPlanner/FXAxisPln.cpp \
    C_SDK/Kinematics/MotionPlanner/FXMotionPlanner.cpp \
    C_SDK/Kinematics/MotionPlanner/FXO3Polynorm.cpp \
    C_SDK/Kinematics/SkyeBodyKinematics/FXSkyeBodyKinematics.cpp \
    C_SDK/L0Control/L0Robot.cpp \
    C_SDK/L0Control/RobotCtrl.cpp \
    C_SDK/L0Control/Utility.cpp \
    C_SDK/L1Robot/L1Robot.cpp \
    main.cpp\
    mainwindow.cpp

HEADERS  += \
    C_SDK/Common/FXCmplOpt.h \
    C_SDK/Common/FXCommon.h \
    C_SDK/Common/FXErrorCode.h \
    C_SDK/Common/FXType.h \
    C_SDK/FXUtility/FXCfg/CfgBase.h \
    C_SDK/FXUtility/FXMath/FXMath.h \
    C_SDK/FXUtility/FXMath/FXMatrix.h \
    C_SDK/FXUtility/FXMath/FxMathType.h \
    C_SDK/FileClient/FXFileClient.h \
    C_SDK/FileClient/FileOP.h \
    C_SDK/FileClient/Parser.h \
    C_SDK/FileClient/TCPAgent.h \
    C_SDK/FileClient/TCPFileClient.h \
    C_SDK/FileClient/netdef.h \
    C_SDK/Kinematics/ArmKinematics/FXArmKinematics.h \
    C_SDK/Kinematics/ArmKinematics/FXKinematics.h \
    C_SDK/Kinematics/DynaIdent/FXDynaIndentification.h \
    C_SDK/Kinematics/KineCommon/FXDG.h \
    C_SDK/Kinematics/KineCommon/FXEnviroment.h \
    C_SDK/Kinematics/KineCommon/FXLog.h \
    C_SDK/Kinematics/KineCommon/PointSet.h \
    C_SDK/Kinematics/L0KineMotion.h \
    C_SDK/Kinematics/MotionPlanner/FXAxisPln.h \
    C_SDK/Kinematics/MotionPlanner/FXMotionPlanner.h \
    C_SDK/Kinematics/MotionPlanner/FXO3Polynorm.h \
    C_SDK/Kinematics/SkyeBodyKinematics/FXSkyeBodyKinematics.h \
    C_SDK/L0Control/L0Robot.h \
    C_SDK/L0Control/RobotCtrl.h \
    C_SDK/L0Control/UdpCommon.h \
    C_SDK/L0Control/Utility.h \
    C_SDK/L1Robot/L1Robot.h \
    C_SDK/L1Robot/SampleOffsetTable.h \
    TrajTable.h \
    mainwindow.h

INCLUDEPATH +=  \
   C_SDK \
   C_SDK/Common \
   C_SDK/FileClient \
   C_SDK/FXUtility/FXCfg\
   C_SDK/FXUtility/FXMath\
   C_SDK/Interf\
   C_SDK/Kinematics \
   C_SDK/Kinematics/ArmKinematics \
   C_SDK/Kinematics/BaseMath \
   C_SDK/Kinematics/DynaIdent \
   C_SDK/Kinematics/KineCommon \
   C_SDK/Kinematics/MotionPlanner \
   C_SDK/Kinematics/SkyeBodyKinematics \
   C_SDK/L0Control \
   C_SDK/L1Robot \

FORMS    += mainwindow.ui
