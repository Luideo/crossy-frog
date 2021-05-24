#include "patern.h"

Patern::Patern(int posX, int posY, int width, int height, int OFFSETX, int OFFSETY, int WIDTHP, int HEIGHTP, int sizeCase)
{
    //Set all the size and posiiton
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    //Set the value passed

    this->OFFSETX = OFFSETX;
    this->OFFSETY = OFFSETY;
    this->WIDTHP = WIDTHP;
    this->HEIGHTP = HEIGHTP;
    this->sizeCase = sizeCase;
    //Set all the ground
    AllGrounds *allsTheGround = new AllGrounds;
    alls = allsTheGround;
    //Get a random gorund
    ground = alls->randGround();
}

void Patern::randGround()
{
    ground = alls->randGround();
}

void Patern::defaultGround()
{
    ground = alls->defaultGround();
}

void Patern::draw(QPainter *itsPainter)
{
    //Draw all the blocks (in the vector read y then x not x then y)
    for(int x=0; x<17;++x){
        for(int y=0;y<7;++y){
            itsPainter->drawImage((x*sizeCase)+OFFSETX+posX,(y*sizeCase)+OFFSETY+posY,ground->getBlocks().at(y).at(x)->getBackground());
            //Set the pos of the block (the only use is for the interaction element method
            ground->getBlocks().at(y).at(x)->setPosX(x*sizeCase+OFFSETX+posX);
            ground->getBlocks().at(y).at(x)->setPosY(y*sizeCase+OFFSETY+posY);
        }
    }
}

void Patern::drawGrid(QPainter *itsPainter)
{
    //Draw the patern border
    //Change the color and the thickness
    QPen p;
    p.setColor(Tools::COLOR_RED());
    p.setWidth(3);
    itsPainter->setPen(p);
    //Draw the 4 lines
    //Top
    itsPainter->drawLine(OFFSETX+posX,OFFSETY+posY,OFFSETX+posX+WIDTHP,OFFSETY+posY);
    //Left
    itsPainter->drawLine(OFFSETX+posX+2,OFFSETY+posY+2,OFFSETX+posX+2,OFFSETY+HEIGHTP/2+posY+2);
    //Right
    itsPainter->drawLine(OFFSETX+WIDTHP+posX-2,OFFSETY+posY-2,OFFSETX+posX+WIDTHP-2,OFFSETY+HEIGHTP/2+posY-2);
    //Bottom
    itsPainter->drawLine(OFFSETX+posX,OFFSETY+posY+HEIGHTP/2,OFFSETX+posX+WIDTHP,OFFSETY+HEIGHTP/2+posY);

    //Draw red on non crossable block
    //Draw all the blocks (in the vector read y then x not x then y)
    for(int x=0; x<17;++x){
        for(int y=0;y<7;++y){
            //Non crossable => red
            if(ground->getBlocks().at(y).at(x)->getCrossable() == false){
                //Change the color and the opacity
                QColor c = Tools::COLOR_RED();
                c.setAlpha(100);
                itsPainter->setPen(c);
                QBrush b;
                b.setColor(c);
                b.setStyle(Qt::SolidPattern);
                itsPainter->setBrush(b);
                //Draw red rectangle on it
                itsPainter->drawRect(QRect((x*sizeCase)+OFFSETX+posX,(y*sizeCase)+OFFSETY+posY,sizeCase,sizeCase));
            }
            //Crossable => green
            if(ground->getBlocks().at(y).at(x)->getCrossable() == true){
                //Change the color and the opacity
                QColor c = Tools::COLOR_GREEN();
                c.setAlpha(100);
                itsPainter->setPen(c);
                QBrush b;
                b.setColor(c);
                b.setStyle(Qt::SolidPattern);
                itsPainter->setBrush(b);
                //Draw red rectangle on it
                itsPainter->drawRect(QRect((x*sizeCase)+OFFSETX+posX,(y*sizeCase)+OFFSETY+posY,sizeCase,sizeCase));
            }
        }
    }

    //Change the color to black
    itsPainter->setPen(Tools::COLOR_BLACK());
    QBrush b;
    b.setColor(Tools::COLOR_BLACK());
    b.setStyle(Qt::SolidPattern);
    itsPainter->setBrush(b);

    //Draw all the line
    //Vettically
    for(int y=0; y<14;++y){
        //Draw lines
        itsPainter->drawLine(OFFSETX+posX,y*sizeCase+OFFSETY+posY,OFFSETX+posX+WIDTHP,y*sizeCase+OFFSETY+posY);
    }
    //Horizontally
    for(int x=0; x<17;++x){
        //Draw lines
        itsPainter->drawLine(x*sizeCase+OFFSETX+posX,OFFSETY+posY,x*sizeCase+OFFSETX+posX,OFFSETY+posY+HEIGHTP);
    }
}

int Patern::getPosY() const
{
    return posY;
}

void Patern::setPosY(int value)
{
    posY = value;
}

void Patern::moveBottom(int speed)
{
    posY+=speed;
    if(posY>=HEIGHTP){
        posY=-HEIGHTP/2;
        randGround();
    }
}

Ground* Patern::getGround() const
{
    return ground;
}
