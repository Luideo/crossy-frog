#include "menu.h"
#include "ui_menu.h"

#include "splash.h"

Menu::Menu(QWidget *parent,Resources *resources)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    //Setup the interface of the widget
    ui->setupUi(this);

    //Set the var resources
    this->resources = resources;


    //Timer of the menu, each 10millis it call mainTimer (private slots method)
    itsTimer = new QTimer();
    //Connect the timer to the mainTimer method
    connect(itsTimer,SIGNAL(timeout()),this,SLOT(mainTimer()));
    //Start and set the timer to 10millis
    itsTimer->start(10);

}

Menu::~Menu()
{
    delete ui;
}

//PaintEvent method (paint all the elements of the widget)
void Menu::paintEvent(QPaintEvent *event)
{
    //Retirer les warnings dues à la non utilisation de l'event
    Q_UNUSED(event);
    //Create the painter
    QPainter * itsPainter = new QPainter(this);
    //Create the brush
    QBrush brush;


    //Set the type of the brush
    brush.setStyle(Qt::SolidPattern);
    //Set the brush of the pen
    itsPainter->setBrush(brush);

    //Change colors
    itsPainter->setPen(Tools::COLOR_CYANSKY());
    brush.setColor(Tools::COLOR_CYANSKY());
    //Reset the brush of the pen
    itsPainter->setBrush(brush);
    //Draw the playground rect
    itsPainter->drawRect(QRect(OFFSETX,OFFSETY,WIDTHP,HEIGHTP));


    //Draw the ui
    //Change colors
    itsPainter->setPen(Tools::COLOR_GRASS());
    brush.setColor(Tools::COLOR_GRASS());
    //Reset the brush
    itsPainter->setBrush(brush);
    //Draw the grass on the bottom
    itsPainter->drawRect(grassRect);
    //Set the font
    QFont fontOut;
    fontOut.setFamily("8-bit Arcade Out");
    fontOut.setPointSize(40);
    QFont fontIn;
    fontIn.setFamily("8-bit Arcade In");
    fontIn.setPointSize(40);
    QFont fontInBig = fontIn;
    fontInBig.setPointSize(fontIn.pointSize()+10);
    //Set the font
    itsPainter->setFont(fontInBig);
    //Draw the title
    itsPainter->drawText(QRect(0,120,WIDTH,120),"CROSSY FROG",QTextOption(Qt::AlignHCenter));
    //Draw the rect of the selected item in the menu
    itsPainter->setFont(fontIn);
    switch (index) {
    case 0: {
        //Redraw all the text with the correct color and font
        itsPainter->setPen(Tools::COLOR_WHITE());
        itsPainter->drawText(QRect(0,300,WIDTH,300),"Play",QTextOption(Qt::AlignHCenter));
        itsPainter->setPen(Tools::COLOR_BLACK());
        itsPainter->setFont(fontOut);
        itsPainter->drawText(QRect(0,300,WIDTH,300),"Play",QTextOption(Qt::AlignHCenter));
        itsPainter->setFont(fontIn);
        itsPainter->drawText(QRect(0,360,WIDTH,360),"Hall Of Fame",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,420,WIDTH,420),"Settings",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,480,WIDTH,480),"Exit",QTextOption(Qt::AlignHCenter));
    }
        break;
    case 1:
    {
        //Redraw all the text with the correct color and font
        itsPainter->setPen(Tools::COLOR_WHITE());
        itsPainter->drawText(QRect(0,360,WIDTH,360),"Hall Of Fame",QTextOption(Qt::AlignHCenter));
        itsPainter->setPen(Tools::COLOR_BLACK());
        itsPainter->setFont(fontOut);
        itsPainter->drawText(QRect(0,360,WIDTH,360),"Hall Of Fame",QTextOption(Qt::AlignHCenter));
        itsPainter->setFont(fontIn);
        itsPainter->drawText(QRect(0,300,WIDTH,300),"Play",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,420,WIDTH,420),"Settings",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,480,WIDTH,480),"Exit",QTextOption(Qt::AlignHCenter));
    }
        break;
    case 2:
    {
        //Redraw all the text with the correct color and font
        itsPainter->setPen(Tools::COLOR_WHITE());
        itsPainter->drawText(QRect(0,420,WIDTH,420),"Settings",QTextOption(Qt::AlignHCenter));
        itsPainter->setPen(Tools::COLOR_BLACK());
        itsPainter->setFont(fontOut);
        itsPainter->drawText(QRect(0,420,WIDTH,420),"Settings",QTextOption(Qt::AlignHCenter));
        itsPainter->setFont(fontIn);
        itsPainter->drawText(QRect(0,300,WIDTH,300),"Play",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,360,WIDTH,360),"Hall Of Fame",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,480,WIDTH,480),"Exit",QTextOption(Qt::AlignHCenter));
    }
        break;
    case 3:
    {
        //Redraw all the text with the correct color and font
        itsPainter->setPen(Tools::COLOR_WHITE());
        itsPainter->drawText(QRect(0,480,WIDTH,480),"Exit",QTextOption(Qt::AlignHCenter));
        itsPainter->setPen(Tools::COLOR_BLACK());
        itsPainter->setFont(fontOut);
        itsPainter->drawText(QRect(0,480,WIDTH,480),"Exit",QTextOption(Qt::AlignHCenter));
        itsPainter->setFont(fontIn);
        itsPainter->drawText(QRect(0,300,WIDTH,300),"Play",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,360,WIDTH,360),"Hall Of Fame",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,420,WIDTH,420),"Settings",QTextOption(Qt::AlignHCenter));
    }
        break;
    default:
    {
        //Redraw all the text with the correct color and font
        itsPainter->setPen(Tools::COLOR_WHITE());
        itsPainter->drawText(QRect(0,300,WIDTH,300),"Play",QTextOption(Qt::AlignHCenter));
        itsPainter->setPen(Tools::COLOR_BLACK());
        itsPainter->setFont(fontOut);
        itsPainter->drawText(QRect(0,300,WIDTH,300),"Play",QTextOption(Qt::AlignHCenter));
        itsPainter->setFont(fontIn);
        itsPainter->drawText(QRect(0,360,WIDTH,360),"Hall Of Fame",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,420,WIDTH,420),"Settings",QTextOption(Qt::AlignHCenter));
        itsPainter->drawText(QRect(0,480,WIDTH,480),"Exit",QTextOption(Qt::AlignHCenter));
    }
    }


    //Draw the rect of the animation on the other text then (just if the variable animate is on true)
    if(animationPlay){
        animatePlayPressed();
        //Change colors
        itsPainter->setPen(Tools::COLOR_GRASS());
        brush.setColor(Tools::COLOR_GRASS());
        //Reset the brush
        itsPainter->setBrush(brush);
        //Draw the grass on the bottom
        itsPainter->drawRect(grassRect2);
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

    //End the painter
    itsPainter->end();
}

void Menu::keyPressEvent(QKeyEvent *event)
{
    //Down
    if(event->key() == Qt::Key_S && !animationPlay){
        //+1 index to go down
        index++;
        //Reset to the first
        if(index>3){
            index=0;
        }
    }
    //Up
    if(event->key() == Qt::Key_Z && !animationPlay){
        // -1 index to go up
        index--;
        //Reset to the last
        if(index<0){
            index=3;
        }
    }
    //Jump into the selected intem (play/settings/...)
    if(event->key() == Qt::Key_Return && !animationPlay){
        switch (index) {
        case 0:
        {
            //Set to true the animation of the layout
            animationPlay=true;
        }
            break;
        case 1:
        {

        }
            break;
        case 2:
        {
        }
            break;
        case 3:
        {
            this->deleteLater();
        }
            break;
        default:
        {
        }
        }
    }
}

void Menu::animatePlayPressed()
{
    //Launch new widget only if the anim is finished (rect on the top)
    if(grassRect2.y()<=OFFSETY && animationPlay){
        animationPlay = false;
        //Change the widget that displayed
        game = new GameMode00(parentWidget(),WIDTH,HEIGHT,OFFSETX,OFFSETY,WIDTHP,HEIGHTP,resources);
        //Remove the action/title bar, let the choice to the machine to upgrade the compatibilty and avoir bugs
        game->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);
        //Show the current widget (game)
        game->show();
        //Delete this widget after calling the other
        this->deleteLater();
    }else{ //Else animate the rect (firstly goDown and after Go up)
        if(grassRect.y()<OFFSETY+HEIGHTP-50){ //Down the first rectangle 1px per 1px
            //Set the pos of the two rects
            grassRect.setY(grassRect.y()+2);
            grassRect2.setY(grassRect.y());
        }else{ //When the first put the second up
            //Up the pos of the second rect
            //Do an interpolator accelerator move
            //The basis is the base speed of the rect
            int basis=4;
            if(grassRect2.y()>650){
                grassRect2.setY(grassRect2.y()-(basis));
            }else if(grassRect2.y()>500){
                grassRect2.setY(grassRect2.y()-(basis+1));
            }else if(grassRect2.y()>350){
                grassRect2.setY(grassRect2.y()-(basis+2));
            }else if(grassRect2.y()>200){
                grassRect2.setY(grassRect2.y()-(basis+3));
            }else{
                grassRect2.setY(grassRect2.y()-(basis+4));
            }
            grassRect2.setHeight(grassRect2.height());
        }
    }
}

//Private slots method call every 10millis (by the timer)
void Menu::mainTimer()
{
    //Repaint the UI (call the paintEvent method)
    repaint();
}

