#include "menu.h"

#include <QApplication>
#include "tools/includes.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //Add the font to the project
    QFontDatabase::addApplicationFont("../CrossyFrog/res/8_bit_arcade/8-bit_In.ttf");
    QFontDatabase::addApplicationFont("../CrossyFrog/res/8_bit_arcade/8-bit_Out.ttf");
    //Creation of the menu widget
    Menu menu;
    //Remove the action/title bar, let the choice to the machine to upgrade the compatibilty and avoir bugs
    menu.setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //Show the current widget (menu)
    menu.show();
    return a.exec();
}
