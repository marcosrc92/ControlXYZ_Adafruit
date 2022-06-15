QT += core gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    mainwindow.h

FORMS += \
    mainwindow.ui

TRANSLATIONS += \
    App_escritorio_6ejes_en_GB.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Imgs.qrc

DISTFILES += \
    ../Imagenes/3d-plane.jpg \
    ../Imagenes/8305_RBL13D_SGL.jpg \
    ../Imagenes/isoaxis.jpg \
    ../Imagenes/istockphoto-841962328-612x612.jpg \
    ../Imagenes/keyA.jpg \
    ../Imagenes/keyD.jpg \
    ../Imagenes/keyDown.jpg \
    ../Imagenes/keyLeft.jpg \
    ../Imagenes/keyRight.jpg \
    ../Imagenes/keyS.jpg \
    ../Imagenes/keyShift.jpg \
    ../Imagenes/keyUp.jpg \
    ../Imagenes/keyW.jpg \
    ../Imagenes/mesa optica - editable 1.jpg \
    ../Imagenes/mesa optica - editable 1.jpg \
    ../Imagenes/mesa optica - editable 2.jpg \
    ../Imagenes/mesa optica - editable 2.jpg \
    ../Imagenes/mesa optica.jpg \
    ../Imagenes/mesa optica.jpg \
    ../Imagenes/teclado-qwerty-español-de-la-disposición-del-sp-gris-54269213.jpg \
    ../Imagenes/teclado-qwerty-español-de-la-disposición-del-sp-gris-54269213.jpg \
    Imagenes/3d-plane.jpg \
    Imagenes/8305_RBL13D_SGL.jpg \
    Imagenes/isoaxis.jpg \
    Imagenes/istockphoto-841962328-612x612.jpg \
    Imagenes/keyA.jpg \
    Imagenes/keyD.jpg \
    Imagenes/keyDown.jpg \
    Imagenes/keyLeft.jpg \
    Imagenes/keyRight.jpg \
    Imagenes/keyS.jpg \
    Imagenes/keyShift.jpg \
    Imagenes/keyUp.jpg \
    Imagenes/keyW.jpg \
    Imagenes/mesa optica - editable 1.jpg \
    Imagenes/mesa optica - editable 1.jpg \
    Imagenes/mesa optica - editable 2.jpg \
    Imagenes/mesa optica - editable 2.jpg \
    Imagenes/mesa optica.jpg \
    Imagenes/mesa optica.jpg \
    Imagenes/teclado-qwerty-español-de-la-disposición-del-sp-gris-54269213.jpg \
    Imagenes/teclado-qwerty-español-de-la-disposición-del-sp-gris-54269213.jpg
