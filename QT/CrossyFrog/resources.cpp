#include "resources.h"

Resources::Resources()
{
    //Initialize the index
    index = 0;

    //Load frogs
    QImage frog1;
    frog1.load("../CrossyFrog/res/frog1.png");
    //Verify if the image is loaded
    Q_ASSERT(!frog1.isNull());
    images["frog1"]=frog1;
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
    //Grass
    QImage grass;
    grass.load("../CrossyFrog/res/blocks/grass");
    //Verify if the image is correctly loaded
    Q_ASSERT(!grass.isNull());
    images["grass"]=grass;
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
