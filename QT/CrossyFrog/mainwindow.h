#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "tools/includes.h"
#include "menu.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, QTranslator *translator = nullptr,Resources *resources=nullptr);
    ~MainWindow();
    ///
    /// \brief launchGameMode00
    ///
    void launchGameMode00(QImage * frogChosen,string playerName);
    ///
    /// \brief launchChooseFrog
    ///
    void launchChooseFrog();
    ///
    /// \brief launchChooseFrog
    ///
    void launchMenu();
    ///
    /// \brief exitGame
    ///
    void exitGame();

private:
    Ui::MainWindow *ui;
    ///
    /// \brief translator
    ///
    QTranslator *translator;
    ///
    /// \brief The class that contain all the resources
    ///
    Resources *resources;
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
};

#endif // MAINWINDOW_H
