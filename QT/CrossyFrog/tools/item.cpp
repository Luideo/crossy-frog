#include "item.h"

Item::Item(int posx, int posy, QImage background, string name, bool crossable, int OFFSETX, int OFFSETY, int WIDTHP, int HEIGHTP,Resources *resources)
{
    //Set all the variables
    itsPosx = posx;
    itsPosy = posy;
    itsBackground = background;
    itsName = name;
    itsCrossability = crossable;
    this->OFFSETX = OFFSETX;
    this->OFFSETY = OFFSETY;
    this->WIDTHP = WIDTHP;
    this->HEIGHTP = HEIGHTP;
    this->resources = resources;
}

int Item::getItsSpeedX() const
{
    return itsSpeedX;
}

void Item::setItsSpeedX(int value)
{
    itsSpeedX = value;
}

int Item::getItsSpeedY() const
{
    return itsSpeedY;
}

void Item::setItsSpeedY(int value)
{
    itsSpeedY = value;
}

int Item::getItsPosx() const
{
    return itsPosx;
}

int Item::getItsPosy() const
{
    return itsPosy;
}

QImage Item::getItsBackground() const
{
    return itsBackground;
}

void Item::moveFrame()
{
    //qDebug() <<itsPosx << ":" << itsSpeedX << ":" << itsBackground.width();
    //if(itsPosx+itsSpeedX+itsBackground.width() >=OFFSETX && itsPosx+itsSpeedX <= OFFSETX+WIDTHP){
    if(itsName=="car"){
        if(itsSpeedX>0){
            if(itsPosx+itsSpeedX<OFFSETX+WIDTHP){
                itsPosx+=itsSpeedX;
                itsPosy+=itsSpeedY;
                //qDebug() << "Move frame : " << itsPosy;
            }else{
                itsPosx = OFFSETX-itsBackground.width();
                int r = rand()%5+1;
                itsBackground = resources->getImages().at("car"+to_string(r));
            }
        }if(itsSpeedX<0){
            if(itsPosx+itsSpeedX+itsBackground.width()>OFFSETX){
                itsPosx+=itsSpeedX;
                itsPosy+=itsSpeedY;
                //qDebug() << "Move frame : " << itsPosy;
            }else{
                itsPosx = OFFSETX+WIDTHP;
                int r = rand()%5+1;
                itsBackground = resources->getImages().at("car"+to_string(r));
            }
        }
    }
    else if(itsName!="train"){
        if(itsSpeedX>0){
            if(itsPosx+itsSpeedX<OFFSETX+WIDTHP){
                itsPosx+=itsSpeedX;
                itsPosy+=itsSpeedY;
                //qDebug() << "Move frame : " << itsPosy;
            }else{
                itsPosx = OFFSETX-itsBackground.width();
            }
        }if(itsSpeedX<0){
            if(itsPosx+itsSpeedX+itsBackground.width()>OFFSETX){
                itsPosx+=itsSpeedX;
                itsPosy+=itsSpeedY;
                //qDebug() << "Move frame : " << itsPosy;
            }else{
                itsPosx = OFFSETX+WIDTHP;
            }
        }
    }else{
        if(itsSpeedX>0){
            if(itsPosx+itsSpeedX<OFFSETX+WIDTHP){
                itsPosx+=itsSpeedX;
                itsPosy+=itsSpeedY;
                //qDebug() << "Move frame : " << itsPosy;
            }else{
                itsPosx = OFFSETX-itsBackground.width()-3000;
            }
        }if(itsSpeedX<0){
            if(itsPosx+itsSpeedX+itsBackground.width()>OFFSETX){
                itsPosx+=itsSpeedX;
                itsPosy+=itsSpeedY;
                //qDebug() << "Move frame : " << itsPosy;
            }else{
                itsPosx = OFFSETX+WIDTHP+3000;
            }
        }
    }
}

bool Item::getItsCrossability() const
{
    return itsCrossability;
}
