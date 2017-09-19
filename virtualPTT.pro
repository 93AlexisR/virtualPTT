TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    SoundBufferReader.cpp \
    ButtonPress.cpp \
    Timer.cpp

RESOURCES += qml.qrc

LIBS += -LG:\Libraries\SFML\SFML-Compiled\lib

CONFIG(release, debug|release): LIBS += -lsfml-audio -lsfml-graphics -lsfml-main -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -lsfml-audio-d -lsfml-graphics-d -lsfml-main-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

INCLUDEPATH += G:\Libraries\SFML\SFML-Compiled\include
DEPENDPATH += G:\Libraries\SFML\SFML-Compiled\include

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    SoundBufferReader.hpp \
    ButtonPress.hpp \
    Timer.hpp

CONFIG += c++11
