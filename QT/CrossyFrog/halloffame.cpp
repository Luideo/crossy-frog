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

    //Create the scroll area
    scrollArea = new QScrollArea(this);
    scrollArea->setGeometry(OFFSETX+(WIDTHP-resources->getImages().at("sign").size().width())/2+25,220+30,550,320);
    scrollArea->setStyleSheet("background-color:transparent;");
    //scrollArea->setFrameShape(QFrame::NoFrame);
    //Init this
    layout = new QVBoxLayout();
    scrollArea->setLayout(layout);
    //Add the db
    initDatabase();

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

    //Draw background animated cloud
    itsPainter->drawImage(cloudX,100,*cloud);

    //Draw the sign
    itsPainter->setPen(Qt::transparent);
    itsPainter->drawImage(OFFSETX+(WIDTHP-resources->getImages().at("sign").size().width())/2,220,resources->getImages().at("sign"));

    //Draw the background animated frog
    itsPainter->drawImage(frog->getPosX(),frog->getPosY(),frog->getShape());

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


    //Draw all the bests scores
    drawDatabase(itsPainter);

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

bool HallOfFame::initDatabase()
{
    //qDebug() << "initDataBase";
    // Création de la base de données
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../CrossyFrog/res/sqlDB/scoreList.db"); //DOES'NT WORK ON MAC
    if(db.open()){
        //qDebug() << "database file:opened";
    }else{
        qDebug() << "database file:error while opening file";
    }
    // Initialisation de la vue à partir des informations de la base de données
    model=new QSqlTableModel(0,db);
    model->setTable("scoreList");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);

    /*
               //Delete all row
               QSqlQuery query;
               query.exec("DELETE FROM scoreList");
               save();
               */

    return db.open();
}

void HallOfFame::drawDatabase(QPainter * itsPainter)
{
    //qDebug() << "drawDatabase";
    //Change the font color and size
    itsPainter->setPen(Tools::COLOR_WHITE());
    QBrush b = itsPainter->brush();
    b.setColor(Tools::COLOR_WHITE());
    itsPainter->setBrush(b);
    QFont font = itsPainter->font();
    font.setFamily("8-bit Arcade In");
    font.setPointSize(40);
    itsPainter->setFont(font);

    //Before drawing scores, drawing a white bg on the future emplacement of it
    //With a white quite transparent
    QColor white70 = Tools::COLOR_WHITE();
    white70.setAlpha(255*0.7);
    b = itsPainter->brush();
    b.setColor(white70);
    itsPainter->setBrush(b);
    //Draw it
    itsPainter->drawRect(QRect(OFFSETX+150,OFFSETY+320,WIDTHP-300,220));

    //Set the scores in black
    itsPainter->setPen(Tools::COLOR_BLACK());
    b = itsPainter->brush();
    b.setColor(Tools::COLOR_BLACK());

    //qDebug() << "Draw Database";
    QSqlQuery query;
    query.exec("SELECT name, score FROM scoreList");

    //Create the vector with the scores
    vector<pair<string,int>> scores;

    //Create a int to display only 3 score (the bests)
    int i =0;
    while (query.next()) {
        string name = query.value(0).toString().toStdString();
        int score = query.value(1).toInt();
        // qDebug() << name << score;
        //Store the score in a vector
        scores.push_back(make_pair(name,score));
        i++;
    }
    //Sort the scores
    sort(scores.rbegin(),scores.rend(),sortByVal);

    //Display the 3 first text
    for(int i =0 ;i < 4 && i<(int)scores.size() ; i++){
        //itsPainter->drawText(QRect(OFFSETX,OFFSETY+320 + i*50,WIDTHP,50),QString::fromStdString(scores.at(i).first)+" : "+QString::number(scores.at(i).second),QTextOption(Qt::AlignCenter));
        QLabel *label = new QLabel(QString::fromStdString(scores.at(i).first)+ " : " + QString::number(scores.at(i).second));
        layout->addWidget(label);
    }
}

bool HallOfFame::sortByVal(const pair<string, int> &a, const pair<string, int> &b)
{
    return (a.second < b.second);
}
