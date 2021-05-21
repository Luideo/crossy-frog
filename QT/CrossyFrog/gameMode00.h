#ifndef GAMEMODE00_H
#define GAMEMODE00_H

#include <QWidget>
#include "tools/includes.h"
#include "tools/tools.h"
#include "player.h"

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
    explicit GameMode00(QWidget *parent = nullptr, int WIDTH = 1200, int HEIGHT = 800, int OFFSETX = 158, int OFFSETY = 36, int WIDTHP = 884, int HEIGHTP = 728);
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
    int sizeCase;
    ///
    /// \brief Create the player of the game
    ///
    Player *player1;

private slots:
    ///
    /// \brief Private slots method call every 10millis (by the timer)
    ///
    void gameLoop();
};

#endif // GAMEMODE00_H
