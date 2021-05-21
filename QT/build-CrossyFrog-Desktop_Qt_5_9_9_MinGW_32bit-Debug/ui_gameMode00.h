/********************************************************************************
** Form generated from reading UI file 'gameMode00.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEMODE00_H
#define UI_GAMEMODE00_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GameMode00
{
public:

    void setupUi(QWidget *GameMode00)
    {
        if (GameMode00->objectName().isEmpty())
            GameMode00->setObjectName(QStringLiteral("GameMode00"));
        GameMode00->resize(1200, 800);
        GameMode00->setMinimumSize(QSize(1200, 800));
        GameMode00->setMaximumSize(QSize(1200, 800));

        retranslateUi(GameMode00);

        QMetaObject::connectSlotsByName(GameMode00);
    } // setupUi

    void retranslateUi(QWidget *GameMode00)
    {
        GameMode00->setWindowTitle(QApplication::translate("GameMode00", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class GameMode00: public Ui_GameMode00 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEMODE00_H
