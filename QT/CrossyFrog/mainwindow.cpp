#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent, QTranslator *translator, Resources *resources) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Set the translator
    this->translator = translator;
    //Set the resources
    this->resources = resources;

    //Creation of the menu widget
    launchMenu();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::launchGameMode00(QImage * frogChosen,string playerName)
{
    //Change the widget that displayed
    GameMode00 *game = new GameMode00(this,WIDTH,HEIGHT,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,resources,frogChosen,playerName);
    setCentralWidget(game);
    game->setFocus();
    game->activateWindow();
    game->show();
}

void MainWindow::launchChooseFrog()
{
    //Change the widget that displayed
    ChooseFrog *choose = new ChooseFrog(this,0,WIDTH,HEIGHT,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,resources);
    setCentralWidget(choose);
    choose->setFocus();
    choose->activateWindow();
    choose->show();
}

void MainWindow::launchMenu()
{
    Menu *menu = new Menu(this,resources);
    setCentralWidget(menu);
    menu->setFocus();
    menu->activateWindow();
    menu->show();
}

void MainWindow::exitGame()
{
    this->deleteLater();
}

void MainWindow::launchSettings(MainWindow *parent,Resources *resources, Frog * frog,int frogState,QImage *cloud,int cloudX, QRect grassRect)
{
    Settings *settings = new Settings(parent,resources,frog,frogState,cloud,cloudX,grassRect);
    setCentralWidget(settings);
    settings->setFocus();
    settings->activateWindow();
    settings->show();
}

void MainWindow::launchHallOfFame(MainWindow *parent, Resources *resources, Frog *frog, int frogState, QImage *cloud, int cloudX, QRect grassRect)
{
    HallOfFame *hallOfFame = new HallOfFame(parent,resources,frog,frogState,cloud,cloudX,grassRect);
    setCentralWidget(hallOfFame);
    hallOfFame->setFocus();
    hallOfFame->activateWindow();
    hallOfFame->show();
}
