#include "choosefrog.h"
#include "ui_choosefrog.h"

ChooseFrog::ChooseFrog(QWidget *parent,int numGame, int WIDTH, int HEIGHT, int OFFSETX, int OFFSETY, int WIDTHP, int HEIGHTP,Resources *resources) :
    QWidget(parent),
    ui(new Ui::ChooseFrog)
{
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
    this->numGame = numGame;

    //Add to the vector all the frog displayed
    QImage * maleFrog = new QImage(resources->getImages().at("frogMF"));
    QImage * femaleFrog = new QImage(resources->getImages().at("frogFF"));
    QImage * femaleFrog2 = new QImage(resources->getImages().at("frogNBF"));
    //Push all in the vector
    allFrontFrogs.push_back(maleFrog);
    allFrontFrogs.push_back(femaleFrog);
    allFrontFrogs.push_back(femaleFrog2);

    //All the frog from the top
    QImage * topM = new QImage(resources->getImages().at("frogM"));
    QImage * topF = new QImage(resources->getImages().at("frogF"));
    QImage * topN = new QImage(resources->getImages().at("frogN"));
    //Push all in the vector
    allMinFrogs.push_back(topM);
    allMinFrogs.push_back(topF);
    allMinFrogs.push_back(topN);


    /*

    //When the frog is choosen switch to the game
    QImage * firstFrog = new QImage(resources->getImages().at("frogMF"));
    //Change the widget that displayed
    game = new GameMode00(parentWidget(),WIDTH,HEIGHT,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,resources,firstFrog);
    //Remove the action/title bar, let the choice to the machine to upgrade the compatibilty and avoir bugs
    game->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
    //Show the current widget (game)
    game->show();
    //Delete this widget after calling the other
    this->deleteLater();


*/

    QTimer * itsTimer = new QTimer(this);
    connect(itsTimer,SIGNAL(timeout()),this,SLOT(timerLoop()));
    itsTimer->start(10);
}

ChooseFrog::~ChooseFrog()
{
    delete ui;
}

void ChooseFrog::paintEvent(QPaintEvent *event)
{
    //Silence the warning
    Q_UNUSED(event);

    //Create the painter and its brush
    QPainter * itsPainter = new QPainter(this);
    itsPainter->setPen(Tools::COLOR_BLACK());
    QBrush brush;
    brush.setColor(Tools::COLOR_BLACK());
    brush.setStyle(Qt::SolidPattern);
    itsPainter->setBrush(brush);

    //Change colors
    itsPainter->setPen(Tools::COLOR_GRASS());
    brush.setColor(Tools::COLOR_GRASS());
    //Reset the brush
    itsPainter->setBrush(brush);
    //Draw the grass on the background
    itsPainter->drawRect(OFFSETX,OFFSETY,WIDTHP,HEIGHTP);
    //Draw the black filter on the background
    QBrush bbrush;
    QColor black50 = Tools::COLOR_BLACK();
    black50.setAlpha(150);
    bbrush.setColor(black50);
    bbrush.setStyle(Qt::SolidPattern);
    itsPainter->setPen(Tools::COLOR_BLACK());
    itsPainter->setBrush(bbrush);
    itsPainter->drawRect(OFFSETX,OFFSETY,WIDTHP,HEIGHTP);
    //Reset the good brush
    itsPainter->setBrush(brush);

    //Paint all the frog at the good pos
    //At the center
    //Set the dimension
    //qDebug() << index;
    //Draw the centered image
    QImage currentImage = allFrontFrogs.at(index)->scaled(QSize(350,350));
    itsPainter->drawImage((WIDTHP-currentImage.width())/2+OFFSETX,(HEIGHTP-currentImage.height())/2+OFFSETY,currentImage);
    //Draw the image at the right
    if(allFrontFrogs.size()>1){
        if(index+1 <= (int)allFrontFrogs.size()-1){
            currentImage = allFrontFrogs.at(index+1)->scaled(QSize(250,250));
            itsPainter->drawImage((WIDTHP-currentImage.width())/2+OFFSETX+WIDTHP/3,(HEIGHTP-currentImage.height())/2+OFFSETY,currentImage);
        }else{
            currentImage = allFrontFrogs.front()->scaled(QSize(250,250));
            itsPainter->drawImage((WIDTHP-currentImage.width())/2+OFFSETX+WIDTHP/3,(HEIGHTP-currentImage.height())/2+OFFSETY,currentImage);
        }
    }
    //Draw the image at the left
    if(allFrontFrogs.size()>2){
        if(index-1 >= 0){
            currentImage = allFrontFrogs.at(index-1)->scaled(QSize(250,250));
            itsPainter->drawImage((WIDTHP-currentImage.width())/2+OFFSETX-WIDTHP/3,(HEIGHTP-currentImage.height())/2+OFFSETY,currentImage);
        }else{
            currentImage = allFrontFrogs.back()->scaled(QSize(250,250));
            itsPainter->drawImage((WIDTHP-currentImage.width())/2+OFFSETX-WIDTHP/3,(HEIGHTP-currentImage.height())/2+OFFSETY,currentImage);
        }
    }



    //Draw the background of the line edit
    //Change the color
    itsPainter->setPen(Tools::COLOR_GRAY80());
    QBrush b = itsPainter->brush();
    b.setColor(Tools::COLOR_GRAY80());
    itsPainter->setBrush(b);
    //Draw it
    itsPainter->drawRect(OFFSETX+200,(HEIGHTP+currentImage.height())/2+OFFSETY+150,WIDTHP-400,50);
    qDebug() << "Text : " << QString::fromStdString(playerName);
    //Set the color to white
    itsPainter->setPen(Tools::COLOR_WHITE());
    //Change the font and the size
    QFont f = itsPainter->font();
    f.setBold(true);
    f.setFamily("8-bit Arcade In");
    f.setPointSize(30);
    itsPainter->setFont(f);
    //Draw the text line edit
    itsPainter->drawText(QRect(OFFSETX+200+20,(HEIGHTP+currentImage.height())/2+OFFSETY+150,WIDTHP-400-40,50),QString::fromStdString(playerName),QTextOption(Qt::AlignLeft));

    //Draw a red text if the name is invalid
    if(errorNameNotValid){
        //Set the pen on red
        itsPainter->setPen(Tools::COLOR_RED());
        //Set the size and font
        QFont f = itsPainter->font();
        f.setFamily("8-bit Arcade In");
        f.setPointSize(25);
        itsPainter->setFont(f);
        //Draw the text
        itsPainter->drawText(QRect(OFFSETX,(HEIGHTP+currentImage.height())/2+OFFSETY+250,WIDTHP,50),"Please enter your name",QTextOption(Qt::AlignHCenter));
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

    itsPainter->end();
}

void ChooseFrog::keyPressEvent(QKeyEvent *event)
{
    Q_UNUSED(event);

    //Add the letter to the string if the letter match with the regex
    QRegExp rexp("^[a-zA-Z0-9-]$");
    if(rexp.exactMatch(QChar(event->key()))){
        //qDebug() << "HERE";
        playerName+=QString(event->key()).toStdString();
    }
    //Delete the last letter
    if(event->key() == Qt::Key_Delete){
        playerName.pop_back();
    }

    if(event->key() == Qt::Key_Right){
        index++;
        if(index>(int)allFrontFrogs.size()-1){
            index=0;
        }
    }
    if(event->key() == Qt::Key_Left){
        index--;
        if(index<0){
            index=allFrontFrogs.size()-1;
        }
    }
    if(event->key() == Qt::Key_Return){
        //Add the letter to the string if the letter match with the regex
        QRegExp rexp("^[[:space:]]*$");
        if(!rexp.exactMatch(QString::fromStdString(playerName))){
            //Launch the good game
            if(numGame==0){
                //When the frog is choosen switch to the game
                QImage * firstFrog = allMinFrogs.at(index);
                //Change the widget that displayed
                game = new GameMode00(parentWidget(),WIDTH,HEIGHT,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,resources,firstFrog,playerName);
                //Remove the action/title bar, let the choice to the machine to upgrade the compatibilty and avoir bugs
                game->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
                //Show the current widget (game)
                game->show();
                //Delete this widget after calling the other
                this->deleteLater();
            }
        }else{
            errorNameNotValid=true;
        }
    }
}

void ChooseFrog::timerLoop()
{
    //Repaint all
    repaint();
}
