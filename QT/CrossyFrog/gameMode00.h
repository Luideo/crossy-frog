#ifndef GAMEMODE00_H
#define GAMEMODE00_H

#include <QWidget>
#include "tools/includes.h"
#include "tools/tools.h"
#include "player.h"
#include "bash.h"
#include "tools/patern.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameMode00; }
QT_END_NAMESPACE

///
/// \brief The class of the first game mode (solo endless)
///
class GameMode00 : public QWidget
{
    Q_OBJECT

public:
    explicit GameMode00(QWidget *parent = nullptr, int WIDTH = 1200, int HEIGHT = 800, int OFFSETX = 158, int OFFSETY = 36, int WIDTHP = 884, int HEIGHTP = 728,Resources *resources=nullptr);
    ~GameMode00();
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
    /// \brief this method verify if the move is possible (if it's in the playground)
    /// \param The frog (to get his position)
    /// \param The move on X
    /// \param The move on Y
    /// \return if the move is valid (true)
    ///
    bool validMove(Frog *frog,int moveX,int moveY);
    ///
    /// \brief getDisplayGrid
    /// \return
    ///
    bool getDisplayGrid() const;
    ///
    /// \brief setDisplayGrid
    /// \param value
    ///
    void setDisplayGrid(bool value);
    ///
    /// \brief getPaused
    /// \return
    ///
    bool getPaused() const;
    ///
    /// \brief setPaused
    /// \param value
    ///
    void setPaused(bool value);
    ///
    /// \brief interactElement method is call every tick and it's do the interaction between frog and element
    ///
    void interactElement(Frog *frog);
    ///
    /// \brief getDisplayUi
    /// \return
    ///
    bool getDisplayUi() const;
    ///
    /// \brief setDisplayUi
    /// \param value
    ///
    void setDisplayUi(bool value);
    ///
    /// \brief diplayUiDevTools method called on paint event if the boolean is on true to display a lot of tools on the playground
    /// \param itsPainter
    ///
    void displayUiDevTools(QPainter *itsPainter);
    ///
    /// \brief this method restart the game from the beginning
    ///
    void restartGame();
    ///
    /// \brief getSizeCase
    /// \return
    ///
    static int getSizeCase();
    ///
    /// \brief advancementSpeed is a method call every second that change the speed in function of the advancement
    ///
    void advancementSpeed();
    ///
    /// \brief getPlayer1
    /// \return
    ///
    Player *getPlayer1() const;
    ///
    /// \brief setPlayer1
    /// \param value
    ///
    void setPlayer1(Player *value);

private:
    Ui::GameMode00 *ui;
    ///
    /// \brief The main timer of the game
    ///
    ///
    QTimer * itsTimer;
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
    /// \brief The size of a case on the playground
    ///
    const static int sizeCase = 52;
    ///
    /// \brief Create the player of the game
    ///
    Player *player1;
    ///
    /// \brief Create the frog of the first player
    ///
    Frog *frog1;
    ///
    /// \brief The menu of the command for debug
    ///
    Bash *bash;
    ///
    /// \brief The 3 patern present in the game
    ///
    Patern *paterns[3];
    ///
    /// \brief State changed by Bash Class
    ///
    bool displayGrid=false;
    ///
    /// \brief If the game is paused, change with spacebar and bash
    ///
    bool paused=false;
    ///
    /// \brief If the game is started, can be change with spacebar (key press event)
    ///
    bool started=false;
    ///
    /// \brief If display the ui dev tools
    ///
    bool displayUi=false;
    ///
    /// \brief The variable speed is the number of pixel that move in a frame
    ///
    int speed=1;
    ///
    /// \brief adv is the advancement of the game, every second it increase by one
    ///
    int adv=0;
    ///
    /// \brief tick increase by one every tick of the timer, reset to 0 every seconds
    ///
    int tick=0;
    ///
    /// \brief tickSpeed is the same as tick just it reset every move of the gameLoop
    ///
    int tickSpeed=0;
    ///
    /// \brief tickRepaint is the same as tick just it reset every 16ms (60fps appr.)
    ///
    int tickRepaint=0;
    ///
    /// \brief speedOfTheTime its the time in millis between every tick
    ///
    int speedOfTheTimer=1;
    ///
    /// \brief Every 12 tick it move the frog (can be lower with the time)
    ///
    int speedGeneral=10;
    ///
    /// \brief atg is the allGround class generated at the begining
    ///
    AllGrounds *atg;
    ///
    /// \brief All the resources we need
    ///
    Resources * resources;
    ///
    /// \brief lastElapsed equals to the time it tooks to the game Loop to do the cycle
    ///
    int lastElapsed=0;

private slots:
    ///
    /// \brief Private slots method call every 10millis (by the timer)
    ///
    void gameLoop();
};

#endif // GAMEMODE00_H
