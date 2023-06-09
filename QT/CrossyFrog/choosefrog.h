#ifndef CHOOSEFROG_H
#define CHOOSEFROG_H

#include <QWidget>
#include "tools/includes.h"
#include <gameMode00.h>

namespace Ui {
class ChooseFrog;
}

class ChooseFrog : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseFrog(MainWindow *parent = nullptr, int numGame=0, int WIDTH = 1200, int HEIGHT = 800, int OFFSETX = 158, int OFFSETY = 36, int WIDTHP = 884, int HEIGHTP = 728,Resources *resources=nullptr);
    ~ChooseFrog();

    ///
    /// \brief the paintEvent call every loop
    /// \param event
    ///
    void paintEvent(QPaintEvent * event);
    ///
    /// \brief keyPressEvent
    /// \param event
    ///
    void keyPressEvent(QKeyEvent * event);

private:
    Ui::ChooseFrog *ui;
    ///
    /// \brief parent
    ///
    MainWindow *parent;
    ///
    /// \brief The Widget Game that will be display when the play button is clicked
    ///
    GameMode00 * game;
    ///
    /// \brief all the FrontFrogs that can be selected
    ///
    vector<QImage *> allFrontFrogs;
    ///
    /// \brief allMinFrogs from the top
    ///
        vector<QImage *> allMinFrogs;
    ///
    /// \brief index (the index is the num of the frog at the front)
    ///
    int index=0;
    ///
    /// \brief WIDTH of the screen
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
    /// \brief All the resources we need
    ///
    Resources * resources;
    ///
    /// \brief playerName
    ///
    string playerName;
    ///
    /// \brief errorNameNotValid is false but put on true if the name is empty, used in the paint event
    ///
    bool errorNameNotValid=false;
    ///
    /// \brief numGame
    ///
    int numGame;

private slots:
    void timerLoop();
};

#endif // CHOOSEFROG_H
