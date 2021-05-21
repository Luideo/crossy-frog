#include "gameMode00.h"
#include "ui_gameMode00.h"

GameMode00::GameMode00(QWidget *parent, int WIDTH, int HEIGHT, int OFFSETX, int OFFSETY, int WIDTHP, int HEIGHTP) :
    QWidget(parent),
    ui(new Ui::GameMode00)
{
    //Setup the interface of the widget
    ui->setupUi(this);

    //Set the value passed
    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    this->OFFSETX = OFFSETX;
    this->OFFSETY = OFFSETY;
    this->WIDTHP = WIDTHP;
    this->HEIGHTP = HEIGHTP;
    this->sizeCase = 52;

    //Create the player and his frog (1 player cause we're in solo)
    player1 = new Player("default1");
    Frog *frog1 = new Frog(sizeCase,sizeCase);
    //Set the basic position
    // X
    frog1->setPosX(OFFSETX+((WIDTHP/sizeCase/2)*sizeCase)); //Center on the X axe
    // Y
    frog1->setPosY(OFFSETY+HEIGHTP-frog1->getWidth());
    // Set the frog the the player
    player1->setItsFrog(frog1);


    //Timer of the menu, each 10millis it call mainTimer (private slots method)
    itsTimer = new QTimer();
    //Connect the timer to the mainTimer method
    connect(itsTimer,SIGNAL(timeout()),this,SLOT(gameLoop()));
    //Start and set the timer to 10millis
    itsTimer->start(10);
}

GameMode00::~GameMode00()
{
    delete ui;
}

void GameMode00::paintEvent(QPaintEvent *event)
{
    //Retirer les warnings dues à la non utilisation de l'event
    Q_UNUSED(event);
    //Create the painter
    QPainter * itsPainter = new QPainter(this);
    //Set the color of the painter (the stroke)
    itsPainter->setPen(Tools::COLOR_NIGHT());
    //Create the brush
    QBrush brush;


    //Set the fill color of the brush
    brush.setColor(Tools::COLOR_NIGHT());
    brush.setStyle(Qt::SolidPattern);
    //Set the brush of the pen
    itsPainter->setBrush(brush);
    //Draw the blackground
    itsPainter->drawRect(QRect(0,0,WIDTH,HEIGHT));

    //Change colors
    itsPainter->setPen(Tools::COLOR_GRASS());
    brush.setColor(Tools::COLOR_GRASS());
    //Reset the brush of the pen
    itsPainter->setBrush(brush);
    //Draw the playground rect
    itsPainter->drawRect(QRect(OFFSETX,OFFSETY,WIDTHP,HEIGHTP));

    //Draw The Elements
    //Frog
    itsPainter->drawImage(player1->getItsFrog()->getPosX(),player1->getItsFrog()->getPosY(),player1->getItsFrog()->getShape());


    //End the painter
    itsPainter->end();
}

void GameMode00::keyPressEvent(QKeyEvent *event)
{
    //Go Up
    if(event->key() == Qt::Key_Z){
        //Move the frog
        player1->getItsFrog()->setPosY(player1->getItsFrog()->getPosY()-sizeCase);
        //Change the rotate params
        player1->getItsFrog()->setRotation(0);
        //Set the QTransform rotation
        QTransform rotation;
        rotation.rotate(player1->getItsFrog()->getRotation());
        QImage newShape = player1->getItsFrog()->getOriginalShape().transformed(rotation);
        //Reset the shape with the newest rotation
        player1->getItsFrog()->setShape(newShape);
    }
    //Go Left
    if(event->key() == Qt::Key_Q){
        //Move the frog
        player1->getItsFrog()->setPosX(player1->getItsFrog()->getPosX()-sizeCase);
        //Change the rotate params
        player1->getItsFrog()->setRotation(-90);
        //Set the QTransform rotation
        QTransform rotation;
        rotation.rotate(player1->getItsFrog()->getRotation());
        QImage newShape = player1->getItsFrog()->getOriginalShape().transformed(rotation);
        //Reset the shape with the newest rotation
        player1->getItsFrog()->setShape(newShape);
    }
    //Go Down
    if(event->key() == Qt::Key_S){
        //Move the frog
        player1->getItsFrog()->setPosY(player1->getItsFrog()->getPosY()+sizeCase);
        //Change the rotate params
        player1->getItsFrog()->setRotation(180);
        //Set the QTransform rotation
        QTransform rotation;
        rotation.rotate(player1->getItsFrog()->getRotation());
        QImage newShape = player1->getItsFrog()->getOriginalShape().transformed(rotation);
        //Reset the shape with the newest rotation
        player1->getItsFrog()->setShape(newShape);
    }
    //Go Right
    if(event->key() == Qt::Key_D){
        //Move the frog
        player1->getItsFrog()->setPosX(player1->getItsFrog()->getPosX()+sizeCase);
        //Change the rotate params
        player1->getItsFrog()->setRotation(90);
        //Set the QTransform rotation
        QTransform rotation;
        rotation.rotate(player1->getItsFrog()->getRotation());
        QImage newShape = player1->getItsFrog()->getOriginalShape().transformed(rotation);
        //Reset the shape with the newest rotation
        player1->getItsFrog()->setShape(newShape);
    }
}

void GameMode00::gameLoop()
{
    repaint();
}
