#ifndef SPLASH_H
#define SPLASH_H

#include <QWidget>
#include "tools/includes.h"
#include "menu.h"
#include "resources.h"
#include "mainwindow.h"

namespace Ui {
class Splash;
}

class MainWindow;

class Splash : public QWidget
{
    Q_OBJECT

public:
    explicit Splash(QWidget *parent = nullptr,QTranslator *translator=nullptr);
    ~Splash();

    ///
    /// \brief getResources
    /// \return the resources
    ///
    Resources getResources() const;
    ///
    /// \brief paintEvent
    /// \param event
    ///
    void paintEvent(QPaintEvent *event);

private:
    Ui::Splash *ui;
    ///
    /// \brief The class that contain all the resources
    ///
    Resources *resources;
    ///
    /// \brief backgroundProgress is the qrect of the background of the progress bar
    ///
    QRect backgroundProgress;
    ///
    /// \brief progress bar
    ///
    QRect progress;
    ///
    /// \brief itsTimer
    ///
    QTimer * itsTimer;
    ///
    /// \brief The translator of the game
    ///
    QTranslator *translator;

private slots:
    void gameLoop();
};

#endif // SPLASH_H
