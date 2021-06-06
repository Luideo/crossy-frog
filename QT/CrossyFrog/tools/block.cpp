#include "block.h"
#include "gameMode00.h"

Block::Block(string imageName, bool crossabilty, Resources *resources)
{
    qDebug() << "Creation de : " << QString::fromStdString(imageName);
    //Assign the resources
    this->resources = resources;
    //Create the image from the path
    QImage bck = resources->getImages().at(imageName);
    //Verify if its correctly loaded
    Q_ASSERT(!bck.isNull());
    //Resize it
    bck = bck.scaled(QSize(GameMode00::getSizeCase(),GameMode00::getSizeCase()));
    //Set the background image
    this->background = bck;
    //Set the crossabilty
    this->crossable  = crossabilty;
    //Set the name
    this->name = imageName;
}

QImage Block::getBackground() const
{
    return background;
}

void Block::setBackground(const QImage &value)
{
    background = value;
}

bool Block::getCrossable() const
{
    return crossable;
}

void Block::setCrossable(bool value)
{
    crossable = value;
}

int Block::getPosX() const
{
    return posX;
}

void Block::setPosX(int value)
{
    posX = value;
}

int Block::getPosY() const
{
    return posY;
}

void Block::setPosY(int value)
{
    posY = value;
}

string Block::getName() const
{
    return name;
}

void Block::setName(const string &value)
{
    name = value;
}
