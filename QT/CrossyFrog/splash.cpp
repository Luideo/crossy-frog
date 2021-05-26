#include "splash.h"
#include "ui_splash.h"

Splash::Splash(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Splash)
{
    ui->setupUi(this);

    //Set the background of the loading progress bar
    backgroundProgress = QRect(100,800-100,1000,20);
    //Set the load progress bar
    progress = QRect(100,800-100,0,20);

    //Set the timer counter
    QElapsedTimer *timer = new QElapsedTimer;
    timer->start();
    //Set the timer that call the game loop
    itsTimer = new QTimer;
    itsTimer->start(10);
    //Call the game loop on timeout
    connect(itsTimer,SIGNAL(timeout()),this,SLOT(gameLoop()));

    //Loading all the resources
    resources = new Resources();

    qDebug() << "Chargement des ressources en : " << timer->elapsed() << "ms";

    //Creation of the menu widget
    Menu *menu = new Menu(parentWidget(),resources);
    //Remove the action/title bar, let the choice to the machine to upgrade the compatibilty and avoir bugs
    menu->setWindowFlags(Qt::Window | Qt::FramelessWindowHint);

    //Show the current widget (menu)
    menu->show();

    //Delete this
    this->deleteLater();
}

Splash::~Splash()
{
    delete ui;
}

Resources Splash::getResources() const
{
    return *resources;
}

void Splash::paintEvent(QPaintEvent *event)
{
    //Create the painter
    QPainter *itsPainter = new QPainter(this);
    //Ignorer le warning
    Q_UNUSED(event);
    //Change colors
    itsPainter->setPen(Tools::COLOR_BLACK());
    QBrush brush;
    brush.setColor(Tools::COLOR_BLACK());
    brush.setStyle(Qt::SolidPattern);
    itsPainter->setBrush(brush);
    //Draw the bg of the loading bar
    itsPainter->drawRect(backgroundProgress);
    //Draw the loading bar
    resources->draw(itsPainter,progress);

    //end the painter
    itsPainter->end();
}

void Splash::gameLoop()
{
    repaint();
}
