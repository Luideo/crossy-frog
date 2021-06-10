#include "frog.h"

Frog::Frog(int width, int height,Resources *resources,QImage shape)
{
    //Set the width of the frog
    this->width = width;
    //Set the hight of the frog
    this->height = height;
    //Resize
    shape = shape.scaled(QSize(width,height));
    //Set the shape to the frog
    this->shape = shape;
    this->originalShape = shape;
}

QImage Frog::getShape() const
{
    return shape;
}

void Frog::setShape(const QImage &value)
{
    shape = value;
}

int Frog::getPosX() const
{
    return posX;
}

void Frog::setPosX(int value)
{
    posX = value;
}

int Frog::getPosY() const
{
    return posY;
}

void Frog::setPosY(int value)
{
    posY = value;
}

int Frog::getWidth() const
{
    return width;
}

void Frog::setWidth(int value)
{
    width = value;
}

int Frog::getHeight() const
{
    return height;
}

void Frog::setHeight(int value)
{
    height = value;
}

int Frog::getRotation() const
{
    return rotation;
}

void Frog::setRotation(int value)
{
    if(value>0){ //Positive value
    rotation = value%360; // Set a modulo 360 because the value cant be more than this
    }else{
        rotation = 360 + value%360; //If the value is negative return the rotation like -10° -> 350°
    }
}

void Frog::moveBottom(int speed)
{
    posY+=speed;
}

bool Frog::getInvicible() const
{
    return invicible;
}

void Frog::setInvicible(bool value)
{
    invicible = value;
}

QImage Frog::getOriginalShape() const
{
    return originalShape;
}
