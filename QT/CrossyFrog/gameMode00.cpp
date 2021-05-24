#include "gameMode00.h"
#include "ui_gameMode00.h"

GameMode00::GameMode00(QWidget *parent, int WIDTH, int HEIGHT, int OFFSETX, int OFFSETY, int WIDTHP, int HEIGHTP) :
    QWidget(parent),
    ui(new Ui::GameMode00)
{
    //Display the bash
    //Creation of the bash widget
    bash = new Bash(parentWidget(),this);
    //Show the bash
    bash->show();

    //Setup the interface of the widget
    ui->setupUi(this);

    //Set the value passed
    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    this->OFFSETX = OFFSETX;
    this->OFFSETY = OFFSETY;
    this->WIDTHP = WIDTHP;
    this->HEIGHTP = HEIGHTP;

    //Create the player and his frog (1 player cause we're in solo)
    player1 = new Player("default1");
    frog1 = new Frog(sizeCase,sizeCase);
    //Set the basic position
    // X
    frog1->setPosX(OFFSETX+((WIDTHP/sizeCase/2)*sizeCase)); //Center on the X axe
    // Y
    frog1->setPosY(OFFSETY+HEIGHTP-frog1->getWidth()-sizeCase*3);
    // Set the frog the the player
    player1->setItsFrog(frog1);
    //Create the 3 parterns
    paterns[0] = new Patern(0,0,WIDTHP,HEIGHTP/2);
    paterns[1] = new Patern(0,HEIGHTP/2,WIDTHP,HEIGHTP/2);
    paterns[2] = new Patern(0,-(HEIGHTP/2),WIDTHP,HEIGHTP/2);

    //Just set a basic dirt ground for the first (default ground)
    paterns[1]->defaultGround();


    //Timer of the menu, each 15millis it call mainTimer (private slots method)
    itsTimer = new QTimer();
    //Connect the timer to the mainTimer method
    connect(itsTimer,SIGNAL(timeout()),this,SLOT(gameLoop()));
    //Start and set the timer to 15millis
    itsTimer->start(speedOfTheTimer);
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
    //Create the brush
    QBrush brush;


    //Set the type of the brush
    brush.setStyle(Qt::SolidPattern);
    //Set the brush of the pen
    itsPainter->setBrush(brush);

    //Change colors
    itsPainter->setPen(Tools::COLOR_GRASS());
    brush.setColor(Tools::COLOR_GRASS());
    //Reset the brush of the pen
    itsPainter->setBrush(brush);
    //Draw the playground rect
    itsPainter->drawRect(QRect(OFFSETX,OFFSETY,WIDTHP,HEIGHTP));

    //Draw The Elements
    //Patern
    for(auto i : paterns){
        i->draw(itsPainter);
    }
    //Frog
    itsPainter->drawImage(player1->getItsFrog()->getPosX(),player1->getItsFrog()->getPosY(),player1->getItsFrog()->getShape());

    //Bash commands
    //Command tha display the grid on the screen
    if(displayGrid){
        for(auto i : paterns){
            i->drawGrid(itsPainter);
        }
    }
    if(displayUi){
        displayUiDevTools(itsPainter);
    }

    //Draw the border of UI
    //Change color
    itsPainter->setPen(Tools::COLOR_NIGHT());
    brush.setColor(Tools::COLOR_NIGHT());
    //Reset the brush
    itsPainter->setBrush(brush);
    //Draw the 4 rect
    //Left
    itsPainter->drawRect(QRect(0,0,OFFSETX,HEIGHT));
    //Right
    itsPainter->drawRect(QRect(OFFSETX+WIDTHP,0,WIDTH-(OFFSETX+WIDTHP),HEIGHT));
    //Up
    itsPainter->drawRect(QRect(0,0,WIDTH,OFFSETY));
    //Down
    itsPainter->drawRect(QRect(0,OFFSETY+HEIGHTP,WIDTH,HEIGHT-(OFFSETY+HEIGHTP)));


    //End the painter
    itsPainter->end();
}

void GameMode00::keyPressEvent(QKeyEvent *event)
{
    //Start the game
    if(event->key() == Qt::Key_Space){ //Spacebar pressed
        //Start the party if it's not
        if(!started){
            started=true;
        }//If already the pause
        else{
            paused = !paused;
        }
    }
    //Verifiy that's not in pause or not started
    if(!paused && started){
        //Go Up
        if(event->key() == Qt::Key_Z  && event->isAutoRepeat()==false){ //Z Pressed and not maintained
            //Is a valide move
            if(validMove(player1->getItsFrog(),0,-sizeCase)){
                //Move the frog
                player1->getItsFrog()->setPosY(player1->getItsFrog()->getPosY()-sizeCase);
            }
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
        if(event->key() == Qt::Key_Q && event->isAutoRepeat()==false){//Q Pressed and not maintained
            //Is a valide move
            if(validMove(player1->getItsFrog(),-sizeCase,0)){
                //Move the frog
                player1->getItsFrog()->setPosX(player1->getItsFrog()->getPosX()-sizeCase);
            }
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
        if(event->key() == Qt::Key_S && event->isAutoRepeat()==false){//S Pressed and not maintained
            //Is a valide move
            if(validMove(player1->getItsFrog(),0,+sizeCase)){
                //Move the frog
                player1->getItsFrog()->setPosY(player1->getItsFrog()->getPosY()+sizeCase);
            }
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
        if(event->key() == Qt::Key_D && event->isAutoRepeat()==false){//D Pressed and not maintained
            //Is a valide move
            if(validMove(player1->getItsFrog(),+sizeCase,0)){
                //Move the frog
                player1->getItsFrog()->setPosX(player1->getItsFrog()->getPosX()+sizeCase);
            }
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
}

bool GameMode00::validMove(Frog *frog, int moveX, int moveY)
{
    if(frog->getPosX()+moveX+frog->getWidth() > OFFSETX+WIDTHP || frog->getPosX()+moveX < OFFSETX //Verify on the X axis
            || frog->getPosY()+moveY >= OFFSETY+HEIGHTP || frog->getPosY()+moveY < OFFSETY){ // Verify on the Y axis
        return false;
    }
    return true;
}

bool GameMode00::getDisplayGrid() const
{
    return displayGrid;
}

void GameMode00::setDisplayGrid(bool value)
{
    displayGrid = value;
}

bool GameMode00::getPaused() const
{
    return paused;
}

void GameMode00::setPaused(bool value)
{
    paused = value;
}

void GameMode00::interactElement(Frog *frog)
{
    //Verify that the case is crossable
    for(int index=0; index<3;index++){//In a pattern (3 is the number of patern)
        for(int x=0; x<17; ++x){ //Column of block
            for(int y=0; y<7; ++y){ //Line of block
                Block *block = paterns[index]->getGround()->getBlocks().at(y).at(x); //Create a local block to simplify the code
                /*
                if(block->getCrossable()==false){
                    qDebug() << "block : " << block->getPosX() << " | " << block->getPosY();
                }
                */
                //Verify if the frog is not in a non crossable type
                if(frog->getPosX()== block->getPosX() && //Check the X pos
                        frog->getPosY()== 1+block->getPosY() && //Check the Y pos (+1 is because of the historical size of a rect)
                        block->getCrossable()==false){ //Check if it's non crossable
                    //Repaint befor restart
                    repaint();
                    //Restart the game
                    restartGame();
                }
            }
        }
    }
    //Verify that the frog is not out of map
    if(frog->getPosY()>OFFSETY+HEIGHTP){
        //Repaint befor restart
        repaint();
        //Restart the game
        restartGame();
    }
}

bool GameMode00::getDisplayUi() const
{
    return displayUi;
}

void GameMode00::setDisplayUi(bool value)
{
    displayUi = value;
}

void GameMode00::displayUiDevTools(QPainter *itsPainter)
{
    //Change the color
    itsPainter->setPen(Tools::COLOR_WHITE());
    //Change the font
    QFont minFont = itsPainter->font();
    minFont.setPointSize(8);
    itsPainter->setFont(minFont);
    //Paint all the information we want on the screen
    itsPainter->drawText(QRect(OFFSETX+WIDTHP-200,OFFSETY+10,190,15),"frog1-pos-x:"+QString::fromStdString(to_string(frog1->getPosX())),QTextOption(Qt::AlignRight));
    itsPainter->drawText(QRect(OFFSETX+WIDTHP-200,OFFSETY+10+15+5,190,15),"frog1-pos-y:"+QString::fromStdString(to_string(frog1->getPosY())),QTextOption(Qt::AlignRight));
    itsPainter->drawText(QRect(OFFSETX+WIDTHP-200,OFFSETY+10+2*15+5,190,15),"advancement:"+QString::fromStdString(to_string(adv)),QTextOption(Qt::AlignRight));
    itsPainter->drawText(QRect(OFFSETX+WIDTHP-200,OFFSETY+10+3*15+5,190,15),"speed:"+QString::fromStdString(to_string(speed)),QTextOption(Qt::AlignRight));
    itsPainter->drawText(QRect(OFFSETX+WIDTHP-200,OFFSETY+10+4*15+5,190,15),"speedGeneral:"+QString::fromStdString(to_string(speedGeneral)),QTextOption(Qt::AlignRight));
}

void GameMode00::restartGame()
{
    //Create the player and his frog (1 player cause we're in solo)
    player1 = new Player("default1");
    frog1 = new Frog(sizeCase,sizeCase);
    //Set the basic position
    // X
    frog1->setPosX(OFFSETX+((WIDTHP/sizeCase/2)*sizeCase)); //Center on the X axe
    // Y
    frog1->setPosY(OFFSETY+HEIGHTP-frog1->getWidth()-sizeCase*3);
    // Set the frog the the player
    player1->setItsFrog(frog1);

    //Create the 3 parterns
    paterns[0] = new Patern(0,0,WIDTHP,HEIGHTP/2);
    paterns[1] = new Patern(0,HEIGHTP/2,WIDTHP,HEIGHTP/2);
    paterns[2] = new Patern(0,-(HEIGHTP/2),WIDTHP,HEIGHTP/2);

    //Set the default ground for the first
    paterns[1]->defaultGround();

    //Restart timer etc etc
    speed=1;
    adv=0;
    tick=0;

    //Set started and paused on default value
    started=false;
    paused=false;
}

int GameMode00::getSizeCase()
{
    return sizeCase;
}

void GameMode00::advancementSpeed()
{
    if(adv%20==0 && speedGeneral!=1){
        speedGeneral-=5;
    }
}

void GameMode00::gameLoop()
{
    //Icrease tick value
    tick++;
    //Every second
    if(tick==(1000/speedOfTheTimer)){
        tick=0;
        //Increase adv value
        adv++;
        //Change the speed in function of advancement
        advancementSpeed();
    }
    //Every speed
   // if(tick%1==0){
        if(!paused && started){
            //Move all the paterns
            for(auto i : paterns){
                i->moveBottom(speed);
            }
            //Move the frog
            frog1->moveBottom(speed);
            //Do the interaction
            interactElement(frog1);
            //Repaint
            repaint();
        }
  //  }
}
