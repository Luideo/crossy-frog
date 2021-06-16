#include "halloffame.h"
#include "ui_halloffame.h"

HallOfFame::HallOfFame(MainWindow *parent,Resources *resources, Frog * frog,int frogState,QImage *cloud,int cloudX, QRect grassRect) :
    QWidget(parent),
    ui(new Ui::HallOfFame)
{
    ui->setupUi(this);

    //Set all the variables
    this->parent = parent;
    this->resources = resources;
    this->frog = frog;
    this->frogState = frogState;
    this->cloud = cloud;
    this->cloudX = cloudX;
    this->grassRect = grassRect;

    //Set the focus
    this->raise();
    this->activateWindow();
    this->setFocusPolicy(Qt::StrongFocus);
    this->setFocus();

    //Timer of the menu, each 10millis it call mainTimer (private slots method)
    itsTimer = new QTimer();
    //Connect the timer to the mainTimer method
    connect(itsTimer,SIGNAL(timeout()),this,SLOT(mainTimer()));
    //Start and set the timer to 10millis
    itsTimer->start(10);

    //Timer of the menu, each 10millis it call mainTimer (private slots method)
    itsTimerA = new QTimer();
    //Connect the timer to the mainTimer method
    connect(itsTimerA,SIGNAL(timeout()),this,SLOT(animationTick()));
    //Start and set the timer to 10millis
    itsTimerA->start(20);
}

HallOfFame::~HallOfFame()
{
    delete ui;
}

void HallOfFame::paintEvent(QPaintEvent *event)
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
    itsPainter->setPen(Tools::COLOR_CYANSKY());
    brush.setColor(Tools::COLOR_CYANSKY());
    //Reset the brush of the pen
    itsPainter->setBrush(brush);
    //Draw the playground rect
    itsPainter->drawRect(QRect(OFFSETX,OFFSETY,WIDTHP,HEIGHTP));

    //Draw the background animated frog
    itsPainter->drawImage(frog->getPosX(),frog->getPosY(),frog->getShape());
    //Draw background animated cloud
    itsPainter->drawImage(cloudX,100,*cloud);

    //Draw the sign
    itsPainter->setPen(Qt::transparent);
    itsPainter->drawImage(OFFSETX+(WIDTHP-resources->getImages().at("sign").size().width())/2,220,resources->getImages().at("sign"));

    //Draw the ui
    //Change colors
    itsPainter->setPen(Tools::COLOR_GRASS());
    brush.setColor(Tools::COLOR_GRASS());
    //Reset the brush
    itsPainter->setBrush(brush);
    //Draw the grass on the bottom
    itsPainter->drawRect(grassRect);

    //Set the font
    QFont fontOut;
    fontOut.setFamily("8-bit Arcade Out");
    fontOut.setPointSize(40);
    QFont fontIn;
    fontIn.setFamily("8-bit Arcade In");
    fontIn.setPointSize(32);
    QFont fontInBig = fontIn;
    fontInBig.setPointSize(fontIn.pointSize()+18);
    //Set the font
    itsPainter->setFont(fontInBig);
    //Draw the title
    itsPainter->drawText(QRect(0,120,WIDTH,120),tr("HALL OF FAME"),QTextOption(Qt::AlignHCenter));


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

void HallOfFame::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        parent->launchMenu();
        this->deleteLater();
    }
}

void HallOfFame::mainTimer()
{
    //Repaint the UI (call the paintEvent method)
    repaint();
}

void HallOfFame::animationTick(){
    timerAnimTick++;
    //Change the frog state and position
    if(timerAnimTick%7==0){
        timerAnimTick=0;
        if(frogState==0){
            frogState=1;
            frog->setPosX(frog->getPosX()+55);
            frog->setPosY(frog->getPosY()-15);
            frog->setShape(resources->getImages().at("frogMenu2"));
            if(frog->getPosX()>WIDTH){
                frog->setPosX(-(rand()%128+128));
            }
        }else if(frogState==1){
            frogState=2;
            frog->setPosX(frog->getPosX()+55);
            frog->setPosY(frog->getPosY()+15);
            frog->setShape(resources->getImages().at("frogMenu1"));
        }else if(frogState == 2){
            frogState=3;
        }else if(frogState == 3){
            frogState=0;
        }
    }
    if(cloudX>WIDTH){
        cloudX=0;
    }else{
        cloudX++;
    }
}
