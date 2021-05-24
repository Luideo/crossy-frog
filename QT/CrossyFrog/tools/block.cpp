#include "block.h"
#include "gameMode00.h"

Block::Block(string imagePath, bool crossabilty,string name)
{
    //Create the image from the path
    QImage bck;
    bck.load(QString::fromStdString(imagePath));
    //Verify if its correctly loaded
    Q_ASSERT(!bck.isNull());
    //Resize it
    bck = bck.scaled(QSize(GameMode00::getSizeCase(),GameMode00::getSizeCase()));
    //Set the background image
    this->background = bck;
    //Set the crossabilty
    this->crossable  = crossabilty;
    //Set the name
    this->name = name;
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
