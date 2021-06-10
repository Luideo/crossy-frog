#include "resources.h"

Resources::Resources()
{
    //Initialize the index
    index = 0;

    //Load frogs
    QImage frogM;
    frogM.load("../CrossyFrog/res/Frog/top/frogM.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogM.isNull());
    images["frogM"]=frogM;
    //Increase the index
    index++;
    QImage frogF;
    frogF.load("../CrossyFrog/res/Frog/top/frogF.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogF.isNull());
    images["frogF"]=frogF;
    //Increase the index
    index++;
    QImage frogN;
    frogN.load("../CrossyFrog/res/Frog/top/frogN.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogN.isNull());
    images["frogN"]=frogN;
    //Increase the index
    index++;

    //Load the front of the frog
    QImage frogMF;
    frogMF.load("../CrossyFrog/res/Frog/full/frogM.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogMF.isNull());
    images["frogMF"]=frogMF;
    //Increase the index
    index++;
    QImage frogFF;
    frogFF.load("../CrossyFrog/res/Frog/full/frogF.png");
    //Verify if the image is loaded
    Q_ASSERT(!frogFF.isNull());
    images["frogFF"]=frogFF;
    //Increase the index
    index++;

    //Load all blocks
    //Dirt
    QImage dirt;
    dirt.load("../CrossyFrog/res/blocks/dirt");
    //Verify if the image is correctly loaded
    Q_ASSERT(!dirt.isNull());
    images["dirt"]=dirt;
    //Increase the index
    index++;
    //Grasses
    QImage grass1;
    grass1.load("../CrossyFrog/res/blocks/grass1");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass1.isNull());
    images["grass1"]=grass1;
    //Increase the index
    index++;
    QImage grass2;
    grass2.load("../CrossyFrog/res/blocks/grass2");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass2.isNull());
    images["grass2"]=grass2;
    //Increase the index
    index++;
    QImage grass3;
    grass3.load("../CrossyFrog/res/blocks/grass3");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass3.isNull());
    images["grass3"]=grass3;
    //Increase the index
    index++;
    QImage grass4;
    grass4.load("../CrossyFrog/res/blocks/grass4");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass4.isNull());
    images["grass4"]=grass4;
    //Increase the index
    index++;
    //Water
    QImage water;
    water.load("../CrossyFrog/res/blocks/water");
    //Verify if the image is correctly loaded
    Q_ASSERT(!water.isNull());
    images["water"]=water;
    //Increase the index
    index++;
    //Road
    QImage road;
    road.load("../CrossyFrog/res/blocks/road.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!road.isNull());
    images["road"]=road;
    //Increase the index
    index++;

    //Both animation of frog at the menu selection
    QImage frogMenu1;
    frogMenu1.load("../CrossyFrog/res/Menu/1.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!frogMenu1.isNull());
    frogMenu1 = frogMenu1.scaled(QSize(128,128));
    images["frogMenu1"]=frogMenu1;
    //Increase the index
    index++;
    QImage frogMenu2;
    frogMenu2.load("../CrossyFrog/res/Menu/2.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!frogMenu2.isNull());
    frogMenu2 = frogMenu2.scaled(QSize(128,128));
    images["frogMenu2"]=frogMenu2;
    //Increase the index
    index++;
    QImage cloud;
    cloud.load("../CrossyFrog/res/Menu/cloud.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!cloud.isNull());
    cloud = cloud.scaled(QSize(128,128));
    images["cloud"]=cloud;
    //Increase the index
    index++;

    //All items are loaded here
    QImage woodLog;
    woodLog.load("../CrossyFrog/res/Items/woodlog.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!woodLog.isNull());
    woodLog = woodLog.scaled(QSize(104,52));
    images["log"]=woodLog;
    //Increase the index
    index++;
    QImage car;
    car.load("../CrossyFrog/res/Items/car.png");
    //Verify if the image is correctly loaded
    Q_ASSERT(!car.isNull());
    car = car.scaled(QSize(104,60));
    images["car"]=car;
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
