#pragma once

#include <QtWidgets/QDialog>
#include "ui_qtgui_dectectletterfromimage.h"
#include <opencv2/opencv.hpp>
using namespace cv;

class QtGui_DectectLetterFromImage : public QDialog
{
    Q_OBJECT

public:
    QtGui_DectectLetterFromImage(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
protected:
    void resizeEvent(QResizeEvent *e);
private:
    Ui::QtGui_DectectLetterFromImageClass ui;
private slots:
    void on_inputImageButton_clicked();
};
