#include "splash.h"

#include <QApplication>
#include "tools/includes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Set the random
    srand(time(NULL));

    //Add the font to the project
    QFontDatabase::addApplicationFont("../CrossyFrog/res/8_bit_arcade/8-bit_In.ttf");
    QFontDatabase::addApplicationFont("../CrossyFrog/res/8_bit_arcade/8-bit_Out.ttf");

    //Loading screen
    //Creation of the loading widget
    Splash *splash = new Splash;
    //Remove the action/title bar, let the choice to the machine to upgrade the compatibilty and avoir bugs
    splash->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //Display
    splash->show();

    return a.exec();
}
