#include "resources.h"

Resources::Resources(QTranslator *translator)
{
    //Initialize the index
    index = 0;

    loadSettings();

    //Set the translator
    this->translator = translator;

    //Load frogs
    QImage frogM;
    frogM.load(":/resources/blocks/res/Frog/top/frogM.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogM.isNull());
    images["frogM"]=frogM;
    //Increase the index
    index++;
    QImage frogF;
    frogF.load(":/resources/blocks/res/Frog/top/frogF.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogF.isNull());
    images["frogF"]=frogF;
    //Increase the index
    index++;
    QImage frogN;
    frogN.load(":/resources/blocks/res/Frog/top/frogN.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogN.isNull());
    images["frogN"]=frogN;
    //Increase the index
    index++;

    //Load the front of the frog
    QImage frogMF;
    frogMF.load(":/resources/blocks/res/Frog/full/frogM.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogMF.isNull());
    images["frogMF"]=frogMF;
    //Increase the index
    index++;
    QImage frogFF;
    frogFF.load(":/resources/blocks/res/Frog/full/frogF.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogFF.isNull());
    images["frogFF"]=frogFF;
    //Increase the index
    index++;
    QImage frogNBF;
    frogNBF.load(":/resources/blocks/res/Frog/full/frogNB.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogNBF.isNull());
    images["frogNBF"]=frogNBF;
    //Increase the index
    index++;

    //Load all blocks
    //Dirts
    QImage dirt1;
    dirt1.load(":/resources/blocks/res/blocks/dirt1.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!dirt1.isNull());
    images["dirt1"]=dirt1;
    //Increase the index
    index++;
    QImage dirt2;
    dirt2.load(":/resources/blocks/res/blocks/dirt2.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!dirt2.isNull());
    images["dirt2"]=dirt2;
    //Increase the index
    index++;
    //Grasses
    QImage grass1;
    grass1.load(":/resources/blocks/res/blocks/grass1.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass1.isNull());
    images["grass1"]=grass1;
    //Increase the index
    index++;
    QImage grass2;
    grass2.load(":/resources/blocks/res/blocks/grass2.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass2.isNull());
    images["grass2"]=grass2;
    //Increase the index
    index++;
    QImage grass3;
    grass3.load(":/resources/blocks/res/blocks/grass3.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass3.isNull());
    images["grass3"]=grass3;
    //Increase the index
    index++;
    QImage grass4;
    grass4.load(":/resources/blocks/res/blocks/grass4.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass4.isNull());
    images["grass4"]=grass4;
    //Increase the index
    index++;
    QImage grass5;
    grass5.load(":/resources/blocks/res/blocks/grass5.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass5.isNull());
    images["grass5"]=grass5;
    //Increase the index
    index++;
    //Water
    QImage water1;
    water1.load(":/resources/blocks/res/blocks/water1.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!water1.isNull());
    images["water1"]=water1;
    //Increase the index
    index++;
    QImage water2;
    water2.load(":/resources/blocks/res/blocks/water2.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!water2.isNull());
    images["water2"]=water2;
    //Increase the index
    index++;
    QImage water3;
    water3.load(":/resources/blocks/res/blocks/water3.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!water3.isNull());
    images["water3"]=water3;
    //Increase the index
    index++;
    //Road
    QImage road;
    road.load(":/resources/blocks/res/blocks/road.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!road.isNull());
    images["road"]=road;
    //Increase the index
    index++;
    QImage trainwail;
    trainwail.load(":/resources/blocks/res/blocks/rail.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!trainwail.isNull());
    images["rail"]=trainwail;
    //Increase the index
    index++;
    QImage bush;
    bush.load(":/resources/blocks/res/blocks/bush.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!bush.isNull());
    images["bush"]=bush;
    //Increase the index
    index++;


    QImage Rec1;
    Rec1.load(":/resources/blocks/res/Menu/Rec1.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!Rec1.isNull());
    Rec1 = Rec1.scaled(QSize(884-400,50));
    images["Rec1"]=Rec1;
    //Increase the index
    index++;
    QImage arrowLeft;
    arrowLeft.load(":/resources/blocks/res/Menu/leftArrow.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!arrowLeft.isNull());
    images["arrowLeft"]=arrowLeft;
    //Increase the index
    index++;
    QImage arrowRight;
    arrowRight.load(":/resources/blocks/res/Menu/rightArrow.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!arrowRight.isNull());
    images["arrowRight"]=arrowRight;
    //Increase the index
    index++;

    //Both animation of frog at the menu selection
    QImage frogMenu1;
    frogMenu1.load(":/resources/blocks/res/Menu/1.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!frogMenu1.isNull());
    frogMenu1 = frogMenu1.scaled(QSize(128,128));
    images["frogMenu1"]=frogMenu1;
    //Increase the index
    index++;
    QImage frogMenu2;
    frogMenu2.load(":/resources/blocks/res/Menu/2.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!frogMenu2.isNull());
    frogMenu2 = frogMenu2.scaled(QSize(128,128));
    images["frogMenu2"]=frogMenu2;
    //Increase the index
    index++;
    QImage cloud;
    cloud.load(":/resources/blocks/res/Menu/cloud.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!cloud.isNull());
    cloud = cloud.scaled(QSize(128,128));
    images["cloud"]=cloud;
    //Increase the index
    index++;
    QImage sign;
    sign.load(":/resources/blocks/res/Menu/sign.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!sign.isNull());
    images["sign"]=sign;
    //Increase the index
    index++;

    //All items are loaded here
    QImage woodLog;
    woodLog.load(":/resources/blocks/res/Items/woodlog.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!woodLog.isNull());
    woodLog = woodLog.scaled(QSize(104,52));
    images["log"]=woodLog;
    //Increase the index
    index++;
    QImage train;
    train.load(":/resources/blocks/res/Items/train.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!train.isNull());
        train = train.scaled(QSize(1200,52));
    images["train"]=train;
    //Increase the index
    index++;
    //All the cars
    QImage car1;
    car1.load(":/resources/blocks/res/Items/car1.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!car1.isNull());
    car1 = car1.scaled(QSize(104,60));
    images["car1"]=car1;
    //Increase the index
    index++;
    QImage car2;
    car2.load(":/resources/blocks/res/Items/car2.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!car2.isNull());
    car2 = car2.scaled(QSize(104,60));
    images["car2"]=car2;
    //Increase the index
    index++;
    QImage car3;
    car3.load(":/resources/blocks/res/Items/car3.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!car3.isNull());
    car3 = car3.scaled(QSize(104,60));
    images["car3"]=car3;
    //Increase the index
    index++;
    QImage car4;
    car4.load(":/resources/blocks/res/Items/car4.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!car4.isNull());
    car4 = car4.scaled(QSize(104,60));
    images["car4"]=car4;
    //Increase the index
    index++;
    QImage car5;
    car5.load(":/resources/blocks/res/Items/car5.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!car5.isNull());
    car5 = car5.scaled(QSize(104,60));
    images["car5"]=car5;
    //Increase the index
    index++;
}

map<string, QImage> Resources::getImages()
{
    return images;
}

void Resources::setImages(const map<string, QImage> &value)
{
    images = value;
}

void Resources::draw(QPainter *itsPainter, QRect progress)
{
    //Change the color
    itsPainter->setPen(Tools::COLOR_RED());
    QBrush brush;
    brush.setColor(Tools::COLOR_RED());
    brush.setStyle(Qt::SolidPattern);
    itsPainter->setBrush(brush);
    //Move the rectangle
    progress.setRect(progress.x(),progress.y(),progress.width()+index*1000/total,progress.height()); //1000 is the width of the progress bar
    //Draw the progress rectangle
    itsPainter->drawRect(progress);
}

QTranslator *Resources::getTranslator() const
{
    return translator;
}

string Resources::getLanguage() const
{
    return language;
}

void Resources::setLanguage(const string &value)
{
    language = value;
}

void Resources::loadSettings()
{
    //Load the settings
    ifstream load;
    load.open("../CrossyFrog/settings.txt");
    //Test is it's open
    if(load){
        //First line is the language
        string languageBuffer;
        getline(load,languageBuffer);
        if(languageBuffer=="US"){
            language="../CrossyFrog/en_US.qm";
        }else if(languageBuffer=="FR"){
            language="../CrossyFrog/fr_FR.qm";
        }else{
            language="../CrossyFrog/en_US.qm";
        }

        //Cose it
        load.close();
    }else{
        qDebug() << "Canno't open the settings";
        //Put the default value
        language="../CrossyFrog/en_US.qm";
    }
}
