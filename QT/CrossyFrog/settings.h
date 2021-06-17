#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include "tools/includes.h"
#include "resources.h"
#include "mainwindow.h"
#include "frog.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(MainWindow *parent = nullptr,Resources *resources=nullptr, Frog * frog = nullptr,int frogState=0,QImage *cloud = nullptr,int cloudX = 100, QRect grassRect = QRect(0,0,100,150));
    ~Settings();

    ///
    /// \brief paintEvent method (paint all the elements of the widget)
    /// \param event
    ///
    void paintEvent(QPaintEvent * event);
    ///
    /// \brief keyPressEvent method (call when a key is pressed)
    /// \param event
    ///
    void keyPressEvent(QKeyEvent * event);

private:
    Ui::Settings *ui;
    ///
    /// \brief parent
    ///
    MainWindow *parent;
    ///
    /// \brief The main timer of the game
    ///
    ///
    QTimer * itsTimer;
    ///
    /// \brief itsTimerA is the timer specified for the frog and cloud anim in background
    ///
    QTimer * itsTimerA;
    ///
    /// \brief Width of the screen
    ///
    int WIDTH = 1200;
    ///
    /// \brief Height of the screen
    ///
    int HEIGHT = 800;
    ///
    /// \brief Offset of the playground(middle screen) X
    ///
    int OFFSETX = 158;
    ///
    /// \brief Offset of the playground(middle screen) Y
    ///
    int OFFSETY = 36;
    ///
    /// \brief Width of the playgorund
    ///
    int WIDTHP = 884;
    ///
    /// \brief Width of the playgorund
    ///
    int HEIGHTP = 728;
    ///
    /// \brief This is the grass rect, used for the animation
    ///
    QRect grassRect = QRect(OFFSETX,OFFSETY+HEIGHTP-150,WIDTHP,150);
    ///
    /// \brief All the resources we need
    ///
    Resources *resources;
    ///
    /// \brief frog in the background
    ///
    Frog *frog;
    ///
    /// \brief frogState 0 or 1(0 ground, 1 int the air)
    ///
    int frogState=0;
    ///
    /// \brief cloud in the background
    ///
    QImage *cloud;
    ///
    /// \brief cloudX pos
    ///
    int cloudX = 100;
    ///
    /// \brief timerAnimTick +1 every tick
    ///
    int timerAnimTick=0;
    ///
    /// \brief timerSecondAnim
    ///
    int timerSecondAnim=0;
    ///
    /// \brief line selected
    ///
    int line=0;
    ///
    /// \brief column selected
    ///
    int column=0;
    ///
    /// \brief rules
    ///
    bool rules=false;
    ///
    /// \brief credits
    ///
    bool credits=false;

private slots:
    ///
    /// \brief Private slots method call every 10millis (by the timer)
    ///
    void mainTimer();
    ///
    /// \brief animationtic
    ///
    void animationTick();
};

#endif // SETTINGS_H
