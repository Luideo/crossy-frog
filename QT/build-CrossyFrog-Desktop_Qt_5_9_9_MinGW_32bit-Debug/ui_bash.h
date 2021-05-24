/********************************************************************************
** Form generated from reading UI file 'bash.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BASH_H
#define UI_BASH_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Bash
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;

    void setupUi(QWidget *Bash)
    {
        if (Bash->objectName().isEmpty())
            Bash->setObjectName(QStringLiteral("Bash"));
        Bash->resize(400, 300);
        gridLayoutWidget = new QWidget(Bash);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 0, 401, 301));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setSizeConstraint(QLayout::SetMaximumSize);
        gridLayout->setContentsMargins(0, 0, 0, 0);

        retranslateUi(Bash);

        QMetaObject::connectSlotsByName(Bash);
    } // setupUi

    void retranslateUi(QWidget *Bash)
    {
        Bash->setWindowTitle(QApplication::translate("Bash", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Bash: public Ui_Bash {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BASH_H
