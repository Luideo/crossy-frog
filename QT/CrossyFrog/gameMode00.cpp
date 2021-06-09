#include "gameMode00.h"
#include "ui_gameMode00.h"

GameMode00::GameMode00(QWidget *parent, int WIDTH, int HEIGHT, int OFFSETX, int OFFSETY, int WIDTHP, int HEIGHTP,Resources *resources,QImage * frogChoosen) :
    QWidget(parent),
    ui(new Ui::GameMode00)
{
    //Display the bash
    //Creation of the bash widget
    bash = new Bash(parentWidget(),this);
    //Change the name
    bash->setWindowTitle("Bash");
    //Show the bash
    bash->show();

    //Setup the interface of the widget
    ui->setupUi(this);

    //Set the resources
    this->resources = resources;

    //Set the value passed
    this->WIDTH = WIDTH;
    this->HEIGHT = HEIGHT;
    this->OFFSETX = OFFSETX;
    this->OFFSETY = OFFSETY;
    this->WIDTHP = WIDTHP;
    this->HEIGHTP = HEIGHTP;

    //Create the player and his frog (1 player cause we're in solo)
    player1 = new Player("default1",resources);
    frog1 = new Frog(sizeCase,sizeCase,resources);

    //Set the basic position
    // X
    frog1->setPosX(OFFSETX+((WIDTHP/sizeCase/2)*sizeCase)); //Center on the X axe
    // Y
    frog1->setPosY(OFFSETY+HEIGHTP-frog1->getWidth()-sizeCase*3);
    // Set the frog the the player
    player1->setItsFrog(frog1);
    //Create all ground class
    atg = new AllGrounds(resources);
    //Create the 3 parterns
    paterns[0] = new Patern(0,0,WIDTHP,HEIGHTP/2,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,sizeCase,*atg,"patern1",resources);
    paterns[1] = new Patern(0,HEIGHTP/2,WIDTHP,HEIGHTP/2,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,sizeCase,*atg,"patern2",resources);
    paterns[2] = new Patern(0,-(HEIGHTP/2),WIDTHP,HEIGHTP/2,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,sizeCase,*atg,"patern3",resources);

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

    //Change the size and the font of the painter
    QFont original = itsPainter->font();
    QFont font = itsPainter->font();
    font.setFamily("8-bit Arcade In");
    font.setPointSize(40);
    itsPainter->setFont(font);
    //Change the color
    itsPainter->setPen(Tools::COLOR_WHITE());
    //Display the score
    itsPainter->drawText(QRect(OFFSETX+5,OFFSETY+5,200,50),QString::number(player1->getItsMaxScore()),QTextOption(Qt::AlignLeft));
    //Reset the original font
    itsPainter->setFont(original);

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
    //Draw the game over screen
    if(partyFinished){
        drawPartyFinished(itsPainter);
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
    if(!paused && started && !partyFinished){
        //Go Up
        if(event->key() == Qt::Key_Z  && event->isAutoRepeat()==false){ //Z Pressed and not maintained
            //Is a valide move
            if(validMove(player1->getItsFrog(),0,-sizeCase)){
                //Move the frog
                player1->getItsFrog()->setPosY(player1->getItsFrog()->getPosY()-sizeCase);
                //Set the score
                player1->goUp();
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
                //Set the score
                player1->goDown();
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
            || frog->getPosY()+moveY >= OFFSETY+HEIGHTP || frog->getPosY()+moveY < OFFSETY-sizeCase){ // Verify on the Y axis
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
    bool crossable = true;
    for(int index=0; index<3;index++){//In a pattern (3 is the number of patern)
        for(int x=0; x<17; ++x){ //Column of block
            for(int y=0; y<7; ++y){ //Line of block
                Block block = paterns[index]->getGround()->getBlocks()->at(y).at(x); //Create a local block to simplify the code
                /*
                if(block.getCrossable()==false){
                    qDebug() << "name : " << QString::fromStdString(paterns[index]->getName()) << " | block : " << block.getPosX() << " | " << block.getPosY() << " | adresse : " << paterns[index]->getGround();
                }
                */
                //Verify if the frog is not in a non crossable type
                if(frog->getPosX()== block.getPosX() && //Check the X pos
                        frog->getPosY()== block.getPosY() && //Check the Y pos
                        block.getCrossable()==false && //Check if it's non crossable
                        player1->getItsFrog()->getInvicible() == false){ //Check if the frog is not invincible
                    crossable = false;
                }
            }
        }
        //Check all the items
        int in =0;
        for(auto i : paterns[index]->getAllItems()){
            //qDebug() << frog->getPosY() << " : " <<+paterns[index]->getPosY();
            //Now check the items
            if(((frog->getPosX() > i->getItsPosx() && frog->getPosX() < i->getItsPosx()+i->getItsBackground().size().width()) //for x
                || (frog->getPosX()+frog->getWidth() > i->getItsPosx() && frog->getPosX()+frog->getWidth() < i->getItsPosx()+i->getItsBackground().size().width()))
                    && (frog->getPosY()==i->getItsPosy()+paterns[index]->getPosY())){ //for y
                //Only if the item is crossable
                if(i->getItsCrossability()){
                    crossable = true;
                }else{
                    crossable = false;
                }
            }
            in++;
        }
    }
    if(!crossable && player1->getItsFrog()->getInvicible() == false){
        //Repaint before restart
        repaint();
        partyFinished=true;
        /*
        //Restart the game
        restartGame();
        //Repaint after restart
        repaint();
        */
    }
    //Verify that the frog is not out of map, if it's invincible the replace it
    if(frog->getPosY()>OFFSETY+HEIGHTP){
        if(player1->getItsFrog()->getInvicible() == false){
            //Repaint before restart
            repaint();
            partyFinished=true;
            /*
            //Restart the game
            restartGame();
            //Repaint after restart
            repaint();
            */
        }else{
            //Change it's posY
            player1->getItsFrog()->setPosY(player1->getItsFrog()->getPosY()-sizeCase);
            //Set the score
            player1->goUp();
            //Then repaint
            repaint();
        }
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
    itsPainter->drawText(QRect(OFFSETX+WIDTHP-200,OFFSETY+10+4*15+5,190,15),"speedGeneral:"+QString::fromStdString(to_string(speedGeneral))+"%",QTextOption(Qt::AlignRight));
    itsPainter->drawText(QRect(OFFSETX+WIDTHP-200,OFFSETY+10+5*15+5,190,15),"invincible:"+QString::fromStdString(to_string(player1->getItsFrog()->getInvicible())),QTextOption(Qt::AlignRight));
    itsPainter->drawText(QRect(OFFSETX+WIDTHP-200,OFFSETY+10+6*15+5,190,15),"partyFinished:"+QString::fromStdString(to_string(partyFinished)),QTextOption(Qt::AlignRight));
}

void GameMode00::restartGame()
{
    //Create the player and his frog (1 player cause we're in solo)
    player1 = new Player("default1",resources);
    frog1 = new Frog(sizeCase,sizeCase,resources);
    //Set the basic position
    // X
    frog1->setPosX(OFFSETX+((WIDTHP/sizeCase/2)*sizeCase)); //Center on the X axe
    // Y
    frog1->setPosY(OFFSETY+HEIGHTP-frog1->getWidth()-sizeCase*3);
    // Set the frog the the player
    player1->setItsFrog(frog1);

    //Delete olds paterns
    for(int i =0; i < 3 ; ++i){
        paterns[i]->~Patern();
    }
    //Create the 3 parterns
    paterns[0] = new Patern(0,0,WIDTHP,HEIGHTP/2,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,sizeCase,*atg,"patern1",resources);
    paterns[1] = new Patern(0,HEIGHTP/2,WIDTHP,HEIGHTP/2,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,sizeCase,*atg,"patern2",resources);
    paterns[2] = new Patern(0,-(HEIGHTP/2),WIDTHP,HEIGHTP/2,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,sizeCase,*atg,"patern3",resources);

    //Set the default ground for the first
    paterns[1]->defaultGround();

    //Restart timer etc etc
    speed=1;
    adv=0;
    tick=0;
    tickSpeed=0;
    tickRepaint=0;
    speedGeneral=10;

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
    if(adv%12==0 && speedGeneral!=99){ //Every 12sec
        speedGeneral+=1;
    }
}

Player *GameMode00::getPlayer1() const
{
    return player1;
}

void GameMode00::setPlayer1(Player *value)
{
    player1 = value;
}

void GameMode00::drawPartyFinished(QPainter *itsPainter)
{
    //Create the 50% transparent Black color and set it to the painter
    QColor black50 = Tools::COLOR_BLACK();
    black50.setAlpha(255/2);
    itsPainter->setPen(black50);
    QBrush b = itsPainter->brush();
    QBrush bef = itsPainter->brush();
    b.setColor(black50);
    itsPainter->setBrush(b);

    //Draw the black50 rect on bg
    itsPainter->drawRect(OFFSETX,OFFSETY,WIDTHP,HEIGHTP);

    //Reset the default brush
    itsPainter->setBrush(bef);

    //Set the font and size
    //Set the font
    QFont fontIn;
    fontIn.setFamily("8-bit Arcade In");
    fontIn.setPointSize(60);
    QFont fontOut;
    fontOut.setFamily("8-bit Arcade Out");
    fontOut.setPointSize(60);
    itsPainter->setFont(fontIn);
    b = itsPainter->brush();
    b.setColor(Tools::COLOR_WHITE());
    itsPainter->setBrush(b);
    itsPainter->setPen(Tools::COLOR_WHITE());
    //Draw the game over text
    itsPainter->drawText(QRect(OFFSETX,OFFSETY+30,WIDTHP,200),"Game Over",QTextOption(Qt::AlignCenter));
    //Draw the score
    itsPainter->drawText(QRect(OFFSETX,OFFSETY+260,WIDTHP,150),QString::number(player1->getItsScore()),QTextOption(Qt::AlignCenter));
    //Draw black on it
    itsPainter->setFont(fontOut);
    b = itsPainter->brush();
    b.setColor(Tools::COLOR_BLACK());
    itsPainter->setBrush(b);
    itsPainter->setPen(Tools::COLOR_BLACK());
    //Draw the game over text
    itsPainter->drawText(QRect(OFFSETX,OFFSETY+30,WIDTHP,200),"Game Over",QTextOption(Qt::AlignCenter));
}

void GameMode00::gameLoop()
{
    //Repaint every 16ms (60fps)
    if(tickRepaint%16==0){
        tickRepaint=0;
        //Set a chrono that count elapsed time
        QElapsedTimer chrono;
        chrono.start();
        //Repaint (before interact element to have posX and posY up to date)
        repaint();
        //Do the interaction just after the repaint
        interactElement(frog1);
        qDebug() << "Repaint took " << chrono.elapsed() << "ms";
    }
    //If the game is not paused or not started
    if(!paused && started && !partyFinished){
        //Every second
        if(tick>=(1000/(speedOfTheTimer))){ //
            tick=0;
            //Increase adv value
            adv++;
            //Change the speed in function of advancement
            advancementSpeed();
        }
        //Every speed
        if(tickSpeed>=100/(double)speedGeneral){
            tickSpeed=0;
            //Move all the paterns
            for(auto i : paterns){
                i->moveBottom(speed);
            }
            //Move the frog
            frog1->moveBottom(speed);
            //Browse paterns
            for(auto p : paterns){
                //Browse all items
                for(auto i : p->getAllItems()){
                    i->moveFrame();
                }
            }
        }
        //Icrease tick value
        tick++;
        tickSpeed++;
    }
    tickRepaint++;
}
