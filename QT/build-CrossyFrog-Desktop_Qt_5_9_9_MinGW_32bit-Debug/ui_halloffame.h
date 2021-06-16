/********************************************************************************
** Form generated from reading UI file 'halloffame.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HALLOFFAME_H
#define UI_HALLOFFAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HallOfFame
{
public:

    void setupUi(QWidget *HallOfFame)
    {
        if (HallOfFame->objectName().isEmpty())
            HallOfFame->setObjectName(QStringLiteral("HallOfFame"));
        HallOfFame->resize(1200, 800);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(HallOfFame->sizePolicy().hasHeightForWidth());
        HallOfFame->setSizePolicy(sizePolicy);
        HallOfFame->setMinimumSize(QSize(1200, 800));
        HallOfFame->setMaximumSize(QSize(1200, 800));

        retranslateUi(HallOfFame);

        QMetaObject::connectSlotsByName(HallOfFame);
    } // setupUi

    void retranslateUi(QWidget *HallOfFame)
    {
        HallOfFame->setWindowTitle(QApplication::translate("HallOfFame", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class HallOfFame: public Ui_HallOfFame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HALLOFFAME_H
