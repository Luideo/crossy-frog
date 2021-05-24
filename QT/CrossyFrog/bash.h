#ifndef BASH_H
#define BASH_H

#include <QWidget>
#include "tools/includes.h"

class GameMode00;

namespace Ui {
class Bash;
}

class Bash : public QWidget
{
    Q_OBJECT

public:
    explicit Bash(QWidget *parent = nullptr, GameMode00 *w = nullptr);
    ~Bash();

private:
    Ui::Bash *ui;
    ///
    /// \brief The parent widget used to do command
    ///
    GameMode00 *w;

private slots:
    void displayGrid();
    void pauseGame();
    void displayUi();
};

#endif // BASH_H
