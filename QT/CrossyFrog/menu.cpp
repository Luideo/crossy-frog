#include "menu.h"
#include "ui_menu.h"

Menu::Menu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Menu)
{
    //Setup the interface of the widget
    ui->setupUi(this);

    //Initialized the title
    name = new QLabel(this);
    //Set the font
    QFont font;
    font.setFamily("8-bit Arcade In");
    font.setPointSize(50);
    name->setFont(font);
    //Set the color
    QPalette palette;
    palette.setColor(name->foregroundRole(),Tools::COLOR_GRASS());
    name->setPalette(palette);
    //Set the text
    name->setText("CROSSY FROG");
    //Set the position
    name->setAlignment(Qt::AlignHCenter);
    name->setGeometry(0,150,WIDTH,150);


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
    //Create the painter
    QPainter * itsPainter = new QPainter(this);
    //Set the color of the painter (the stroke)
    itsPainter->setPen(Tools::COLOR_NIGHT());
    //Create the brush
    QBrush brush;


    //Set the fill color of the brush
    brush.setColor(Tools::COLOR_NIGHT());
    brush.setStyle(Qt::SolidPattern);
    //Set the brush of the pen
    itsPainter->setBrush(brush);
    //Draw the blackground
    itsPainter->drawRect(QRect(0,0,WIDTH,HEIGHT));

    //Change colors
    itsPainter->setPen(Tools::COLOR_WHITE());
    brush.setColor(Tools::COLOR_WHITE());
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
    itsPainter->drawRect(QRect(OFFSETX,OFFSETY+HEIGHTP-150,WIDTHP,150));

    //End the painter
    itsPainter->end();
}

//Private slots method call every 10millis (by the timer)
void Menu::mainTimer()
{
    //Repaint the UI (call the paintEvent method)
    repaint();
}

