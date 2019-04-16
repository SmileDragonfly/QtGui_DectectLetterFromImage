/********************************************************************************
** Form generated from reading UI file 'qtgui_dectectletterfromimage.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTGUI_DECTECTLETTERFROMIMAGE_H
#define UI_QTGUI_DECTECTLETTERFROMIMAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtGui_DectectLetterFromImageClass
{
public:
    QGraphicsView *graphicsView;
    QWidget *widget;
    QGridLayout *gridLayout;
    QPushButton *inputImageButton;
    QLineEdit *inputImageEdit;

    void setupUi(QDialog *QtGui_DectectLetterFromImageClass)
    {
        if (QtGui_DectectLetterFromImageClass->objectName().isEmpty())
            QtGui_DectectLetterFromImageClass->setObjectName(QString::fromUtf8("QtGui_DectectLetterFromImageClass"));
        QtGui_DectectLetterFromImageClass->resize(988, 413);
        graphicsView = new QGraphicsView(QtGui_DectectLetterFromImageClass);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(20, 70, 551, 321));
        widget = new QWidget(QtGui_DectectLetterFromImageClass);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(20, 20, 551, 25));
        gridLayout = new QGridLayout(widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        inputImageButton = new QPushButton(widget);
        inputImageButton->setObjectName(QString::fromUtf8("inputImageButton"));

        gridLayout->addWidget(inputImageButton, 0, 0, 1, 1);

        inputImageEdit = new QLineEdit(widget);
        inputImageEdit->setObjectName(QString::fromUtf8("inputImageEdit"));

        gridLayout->addWidget(inputImageEdit, 0, 1, 1, 1);


        retranslateUi(QtGui_DectectLetterFromImageClass);

        QMetaObject::connectSlotsByName(QtGui_DectectLetterFromImageClass);
    } // setupUi

    void retranslateUi(QDialog *QtGui_DectectLetterFromImageClass)
    {
        QtGui_DectectLetterFromImageClass->setWindowTitle(QApplication::translate("QtGui_DectectLetterFromImageClass", "QtGui_DectectLetterFromImage", nullptr));
        inputImageButton->setText(QApplication::translate("QtGui_DectectLetterFromImageClass", "Image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtGui_DectectLetterFromImageClass: public Ui_QtGui_DectectLetterFromImageClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTGUI_DECTECTLETTERFROMIMAGE_H
