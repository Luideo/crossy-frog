#ifndef MENU_H
#define MENU_H

#include <QWidget>
#include "tools/includes.h"
#include "tools/tools.h"
#include "gameMode00.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Menu; }
QT_END_NAMESPACE

///
/// \brief The main class on startup
///
class Menu : public QWidget
{
    Q_OBJECT
public:
    Menu(QWidget *parent = nullptr);
    ~Menu();

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
    /// \brief animatePlayPressed method (call wen the play button is pressed)
    /// \param event
    ///
    void animatePlayPressed();

private:
    Ui::Menu *ui;
    ///
    /// \brief The Widget Game that will be display when the play button is clicked
    ///
    GameMode00 * game;
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
    /// \brief Text of the menu
    ///
    QLabel * leave;
    ///
    /// \brief The index of the menu (0 to start)
    ///
    int index = 0;
    ///
    /// \brief This QLabel is here to make the background of the selected text white
    ///
    QLabel *bck;
    ///
    /// \brief This is the variable that say if we are currently animate the transition
    ///
    bool animationPlay=false;
    ///
    /// \brief This is the grass rect, used for the animation
    ///
    QRect grassRect = QRect(OFFSETX,OFFSETY+HEIGHTP-150,WIDTHP,150);
    ///
    /// \brief This is the second grass rect, used for the animation
    ///
    QRect grassRect2 = QRect(OFFSETX,OFFSETY+HEIGHTP-10,WIDTHP,10);

private slots:
    ///
    /// \brief Private slots method call every 10millis (by the timer)
    ///
    void mainTimer();
};
#endif // MENU_H
