#include "patern.h"

Patern::Patern(int posX, int posY, int width, int height, int OFFSETX, int OFFSETY, int WIDTHP, int HEIGHTP, int sizeCase,AllGrounds atg,string name,Resources *resources)
{
    //Set all the size and posiiton
    this->posX = posX;
    this->posY = posY;
    this->width = width;
    this->height = height;
    //Set the value passed
    this->name = name;
    this->OFFSETX = OFFSETX;
    this->OFFSETY = OFFSETY;
    this->WIDTHP = WIDTHP;
    this->HEIGHTP = HEIGHTP;
    this->sizeCase = sizeCase;
    //Assign not by reference to avoid collision problems
    this->alls = atg;
    //Assign resources
    this->resources = resources;
    //Assign a random ground
    ground = new Ground(alls.randGround());

    //Assign its item corresponding
    //Detect if a line need an item
    //Clear all items before
    allItems.clear();
    //If a complete line is made of non crossable block the system automatically put the log wood item else do nothing
    setItems();
}

void Patern::randGround()
{
    //Assign a random ground
    ground = new Ground(alls.randGround());

    //Clear all items before
    allItems.clear();
    //Set the items on the map
    setItems();
}

void Patern::defaultGround()
{
    //Assign the ground by default
    ground = new Ground(alls.defaultGround());

    //Clear all items before
    allItems.clear();
    //Set the items on the map
    setItems();

}

void Patern::draw(QPainter *itsPainter)
{
    //Draw all the blocks (in the vector read y then x not x then y)
    for(int x=0; x<17;++x){
        for(int y=0;y<7;++y){
            //Draw the current block
            itsPainter->drawImage((x*sizeCase)+OFFSETX+posX,(y*sizeCase)+OFFSETY+posY,ground->getBlocks()->at(y).at(x).getBackground());
            //Set the pos of the block (the only use is for the interaction element method
            ground->getBlocks()->at(y).at(x).setPosX(x*sizeCase+OFFSETX+posX);
            ground->getBlocks()->at(y).at(x).setPosY(y*sizeCase+OFFSETY+posY);
        }
    }
    //qDebug() << "Block : " << ground->getBlocks()->at(0).at(0).getPosY();

    //Draw all the items on the patern
    for(Item *i : allItems){
        //qDebug() << "Draw item at : " << i->getItsPosx() << " : " << i->getItsPosy();
        itsPainter->drawImage(i->getItsPosx()+posX,i->getItsPosy()+posY,i->getItsBackground());
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
    //Draw the patern name and font size
    QFont font = itsPainter->font();
    font.setPointSize(15);
    itsPainter->setFont(font);
    itsPainter->drawText(OFFSETX+posX+5,OFFSETY+posY+20,QString::fromStdString(name));

    //Draw red on non crossable block
    //Draw all the blocks (in the vector read y then x not x then y)
    for(int x=0; x<17;++x){
        for(int y=0;y<7;++y){
            //Non crossable => red
            if(ground->getBlocks()->at(y).at(x).getCrossable() == false){
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
                //qDebug() << "RED : " << QString::fromStdString(to_string(x*sizeCase+OFFSETX+posX))<< "," << QString::fromStdString(to_string(y*sizeCase+OFFSETY+posY));
            }
            //Crossable => green
            if(ground->getBlocks()->at(y).at(x).getCrossable() == true){
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

Ground *Patern::getGround() const
{
    return ground;
}

string Patern::getName() const
{
    return name;
}

vector<Item *> Patern::getAllItems() const
{
    return allItems;
}

void Patern::setItems()
{
    //Assign its item corresponding
    //Detect if a line need an item
    //If a complete line is made of non crossable block the system automatically put the log wood item else do nothing
    for(int y=0;y<7;++y){
        bool needItem = true;
        for(int x=0; x<17;++x){
            if(ground->getBlocks()->at(y).at(x).getCrossable()==true){
                needItem=false;
            }else{
                //qDebug() << QString::fromStdString(ground->getBlocks()->at(y).at(x).getName());
            }
        }
        //If the needItem still true that mean all the line is non crossable so we put an item on it
        if(needItem){
            //qDebug() << "Create item on this patern";
            //Load the image
            QImage background = resources->getImages().at("log");
            //Create the item
            Item * log1 = new Item(OFFSETX+rand()%WIDTHP,OFFSETY+(y*52),background,"log",true,OFFSETX,OFFSETY,WIDTHP,HEIGHTP);
            Item * log2 = new Item(abs(WIDTHP-log1->getItsPosx()),OFFSETY+(y*52),background,"log",true,OFFSETX,OFFSETY,WIDTHP,HEIGHTP);
            log1->setItsSpeedX(-1);
            log2->setItsSpeedX(-1);
            allItems.push_back(log1);
            allItems.push_back(log2);
        }
    }
}
