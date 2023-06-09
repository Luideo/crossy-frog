#ifndef HALLOFFAME_H
#define HALLOFFAME_H

#include <QWidget>
#include "tools/includes.h"
#include "resources.h"
#include "mainwindow.h"

namespace Ui {
class HallOfFame;
}

class HallOfFame : public QWidget
{
    Q_OBJECT

public:
    explicit HallOfFame(MainWindow *parent = nullptr,Resources *resources=nullptr, Frog * frog = nullptr,int frogState=0,QImage *cloud = nullptr,int cloudX = 100, QRect grassRect = QRect(0,0,100,150));
    ~HallOfFame();

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
    ///
    /// \brief sortByVal used with the algorithm sort function
    /// \param a
    /// \param b
    /// \return
    ///
    static bool sortByVal(const pair<string, int> &a,const pair<string, int> &b);

private:
    Ui::HallOfFame *ui;
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
    /// \brief scrollArea
    ///
    QScrollArea *scrollArea;
    ///
    /// \brief data base
    ///
    QSqlDatabase db;
    ///
    /// \brief model of the database
    ///
    QSqlTableModel *model;
    ///
    /// \brief layout
    ///
    QVBoxLayout *layout;
    ///
    /// \brief count
    ///
    int count=0;
    ///
    /// \brief player
    ///
                QMediaPlayer *player;

private slots:
    ///
    /// \brief Private slots method call every 10millis (by the timer)
    ///
    void mainTimer();
    ///
    /// \brief animationtic
    ///
    void animationTick();

public slots:
    ///
    /// \brief initDatabase
    /// \return
    ///
    bool initDatabase();
    ///
    /// \brief populateDataItem
    ///
    void drawDatabase();
};

#endif // HALLOFFAME_H
