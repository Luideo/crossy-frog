#include "bash.h"
#include "ui_bash.h"
#include "gameMode00.h"

Bash::Bash(QWidget *parent, GameMode00 *w) :
    QWidget(parent),
    ui(new Ui::Bash)
{
    ui->setupUi(this);

    //Assigner widget
    this->w = w;

    //Créer les tools
    //Afficher la grille
    QPushButton *displayGrid = new QPushButton("display Patern Ui");
    displayGrid->setFixedSize(QSize(100,50));
    //Mettre en pause
    QPushButton *pauseTheGame = new QPushButton("pause");
    pauseTheGame->setFixedSize(QSize(100,50));
    //Ui
    QPushButton *displayUi = new QPushButton("display Ui");
    displayUi->setFixedSize(QSize(100,50));

    //Afficher les tools
    ui->gridLayout->addWidget(displayGrid,0,0);
    ui->gridLayout->addWidget(pauseTheGame,1,0);
    ui->gridLayout->addWidget(displayUi,0,1);

    //Connecter les boutons
    connect(displayGrid,SIGNAL(pressed()),this,SLOT(displayGrid()));
    connect(pauseTheGame,SIGNAL(pressed()),this,SLOT(pauseGame()));
    connect(displayUi,SIGNAL(pressed()),this,SLOT(displayUi()));
}

Bash::~Bash()
{
    delete ui;
}

void Bash::displayGrid()
{
    //Invert the params and repaint
    w->setDisplayGrid(!w->getDisplayGrid());
    w->repaint();
}

void Bash::pauseGame()
{
    //Invert the params and repaint
    w->setPaused(!w->getPaused());
    w->repaint();
}

void Bash::displayUi()
{
    //Invert the params and repaint
    w->setDisplayUi(!w->getDisplayUi());
    w->repaint();
}
