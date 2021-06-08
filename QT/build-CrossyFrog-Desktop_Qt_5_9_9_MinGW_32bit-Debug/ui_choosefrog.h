/********************************************************************************
** Form generated from reading UI file 'choosefrog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHOOSEFROG_H
#define UI_CHOOSEFROG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ChooseFrog
{
public:

    void setupUi(QWidget *ChooseFrog)
    {
        if (ChooseFrog->objectName().isEmpty())
            ChooseFrog->setObjectName(QStringLiteral("ChooseFrog"));
        ChooseFrog->resize(1200, 800);
        ChooseFrog->setMinimumSize(QSize(1200, 800));
        ChooseFrog->setMaximumSize(QSize(1200, 800));

        retranslateUi(ChooseFrog);

        QMetaObject::connectSlotsByName(ChooseFrog);
    } // setupUi

    void retranslateUi(QWidget *ChooseFrog)
    {
        ChooseFrog->setWindowTitle(QApplication::translate("ChooseFrog", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ChooseFrog: public Ui_ChooseFrog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHOOSEFROG_H
