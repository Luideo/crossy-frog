#include "settings.h"
#include "ui_settings.h"

Settings::Settings(MainWindow *parent,Resources *resources, Frog * frog,int frogState,QImage *cloud,int cloudX, QRect grassRect) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);

    //Set the value
    this->parent = parent;
    this->resources = resources;
    this->cloud = cloud;
    this->cloudX = cloudX;
    this->frog = frog;
    this->frogState = frogState;
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

Settings::~Settings()
{
    delete ui;
}

void Settings::paintEvent(QPaintEvent *event)
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
    itsPainter->drawText(QRect(0,120,WIDTH,120),tr("SETTINGS"),QTextOption(Qt::AlignHCenter));

    //Set the font
    itsPainter->setFont(fontIn);
    //Change the color
    itsPainter->setPen(Tools::COLOR_WHITE());
    //Draw the items on the screen
    itsPainter->drawText(QRect(OFFSETX+70,300,500,50),tr("Language"),QTextOption(Qt::AlignLeft));

    itsPainter->setPen(Tools::COLOR_GRAY80());
    itsPainter->drawText(QRect(OFFSETX+70,405,500,50),tr("Game mode"),QTextOption(Qt::AlignLeft));
    //Change the size
    QFont f = itsPainter->font();
    f.setPointSize(f.pointSize()-8);
    itsPainter->setFont(f);
    //Change the color
    itsPainter->setPen(Tools::COLOR_BLACK());
    //Draw the text
    itsPainter->drawText(QRect(OFFSETX+75,355,200,40),tr("English"),QTextOption(Qt::AlignCenter));
    itsPainter->drawText(QRect(OFFSETX+275+20,355,200,40),tr("French"),QTextOption(Qt::AlignCenter));


    itsPainter->setPen(Tools::COLOR_GRAY80());
    itsPainter->drawText(QRect(OFFSETX+75,455+5,270,40),tr("Solo Endless"),QTextOption(Qt::AlignCenter));
    itsPainter->drawText(QRect(OFFSETX+345+20,455+5,250,40),tr("2 Players"),QTextOption(Qt::AlignCenter));

    //Draw the rules and credit button
    itsPainter->setPen(QPen(Tools::COLOR_BLACK(),5));
    QBrush b = itsPainter->brush();
    b.setColor(Tools::COLOR_WHITE());
    itsPainter->setBrush(b);
    itsPainter->drawRect(OFFSETX+(WIDTHP/2-300)/2,600,300,50);
    itsPainter->drawRect(OFFSETX+(WIDTHP/2-300)/2+WIDTHP/2,600,300,50);
    itsPainter->setPen(Tools::COLOR_BLACK());
    itsPainter->drawText(QRect(OFFSETX+(WIDTHP/2-300)/2,600,300,50),tr("Rules"),QTextOption(Qt::AlignCenter));
    itsPainter->drawText(QRect(OFFSETX+(WIDTHP/2-300)/2+WIDTHP/2,600,300,50),tr("Credits"),QTextOption(Qt::AlignCenter));

    //Draw the selected item
    //Change the color
            itsPainter->setPen(QPen(Tools::COLOR_WHITE(),5));
    b = itsPainter->brush();
    b.setColor(Qt::transparent);
    itsPainter->setBrush(b);
    //Draw it
    if(line==0){
        if(column==0){
            itsPainter->drawRect(OFFSETX+80,360,200,40);
        }else if(column==1){
            itsPainter->drawRect(OFFSETX+280+20,360,200,40);
        }
    }else if(line==1){
        if(column==0){
            itsPainter->setPen(QPen(Tools::COLOR_GRAY80(),5));
            itsPainter->drawRect(OFFSETX+(WIDTHP/2-300)/2,600,300,50);
        }else if(column==1){
            itsPainter->setPen(QPen(Tools::COLOR_GRAY80(),5));
            itsPainter->drawRect(OFFSETX+(WIDTHP/2-300)/2+WIDTHP/2,600,300,50);
        }
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

void Settings::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape){
        parent->launchMenu();
        this->deleteLater();
    }
    if(event->key() == Qt::Key_Left){
        column--;
        if(column<0){
            column=1;
        }
    }
    if(event->key() == Qt::Key_Right){
        column++;
        column = column%2;
    }
    if(event->key() == Qt::Key_Up){
        line--;
        if(line<0){
            line=1;
        }
    }
    if(event->key() == Qt::Key_Down){
        line++;
        line = line%2;
    }
    if(event->key() == Qt::Key_Return){
        //Save this
        ofstream save;
        save.open("../CrossyFrog/settings.txt");
        if(line==0){
            if(column==0){
                save << "US";
                resources->setLanguage("../CrossyFrog/en_US.qm");
                qDebug() << "US save";
            }else if(column==1){
                save << "FR";
                resources->setLanguage("../CrossyFrog/fr_FR.qm");
                qDebug() << "FR save";
            }
        }
        save.close();
        resources->loadSettings();
        //Laod the translator
        resources->getTranslator()->load(QString::fromStdString(resources->getLanguage()));
    }
}

void Settings::mainTimer()
{
    //Repaint the UI (call the paintEvent method)
    repaint();
}

void Settings::animationTick(){
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
