#include <QApplication>
#include <QQmlApplicationEngine>
#include "SoundBufferReader.hpp"



int main(int argc, char *argv[])
{

    SoundBufferReader myRecorder;
    myRecorder.setDevice(myRecorder.getDefaultDevice());
    myRecorder.calibrate(4000);
    myRecorder.start();


    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}


/*To do list:
 * "Remember last calibration settings"
 * SoundThreshold to be set on a 0-100 scale instead of whatever obscure scale its on rn
 *
 *
 *
 *
 *
 */
