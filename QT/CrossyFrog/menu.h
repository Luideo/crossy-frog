#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "tools/includes.h"
#include "tools/tools.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

class Menu : public QWidget
{
    Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

    //PaintEvent method (paint all the elements of the widget)
    void paintEvent(QPaintEvent * event);

private:
    Ui::Menu *ui;
    //The main timer of the game
    QTimer * itsTimer;
    //Width of the screen
    int WIDTH = 1200;
    //Height of the screen
    int HEIGHT = 800;
    //Offset of the playground(middle screen) X
    int OFFSETX = 158;
    //Offset of the playground(middle screen) Y
    int OFFSETY = 36;
    //Width of the playgorund
    int WIDTHP = 884;
    //Width of the playgorund
    int HEIGHTP = 728;
    //The label that display the name of the game
    QLabel *name;

private slots:
    ///
    /// \brief Private slots method call every 10millis (by the timer)
    ///
    void mainTimer();
};
#endif // MENU_H
