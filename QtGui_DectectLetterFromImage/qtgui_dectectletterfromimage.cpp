#include "stdafx.h"
#include "qtgui_dectectletterfromimage.h"

QtGui_DectectLetterFromImage::QtGui_DectectLetterFromImage(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    ui.setupUi(this);
}
void QtGui_DectectLetterFromImage::on_inputImageButton_clicked()
{
    QFileDialog inputDlg(NULL, "Open Image", "E:/MyProject/OpenCV_ConsoleApp/OpenCV_ConsoleApp", " Image Files (*.jpg *.png)");
    if (inputDlg.exec())
    {
        QImage image(inputDlg.selectedFiles()[0]);
        QSize newImgSize(ui.graphicsView->size().width() - 10, ui.graphicsView->size().height() - 10 );
        // Scale image to new size
        image = image.scaled(newImgSize);
        QGraphicsScene* scene = new QGraphicsScene();
        // Set scene
        ui.graphicsView->setScene(scene);
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(image));
        scene->addItem(item);
        ui.graphicsView->show();
        ui.inputImageEdit->setText(inputDlg.selectedFiles()[0]);
        // Process: Detect text here
        //

    }
}

void QtGui_DectectLetterFromImage::resizeEvent(QResizeEvent *e)
{
    // If this is not initiation
    if (e->oldSize().width() != 0xffffffff)
    {
        float widthScale = (float)e->size().width() / e->oldSize().width();
        float heightScale = (float)e->size().height() / e->oldSize().height();
        QSize graphicsViewNewSize;
        graphicsViewNewSize.setWidth((int)(widthScale * ui.graphicsView->size().width()));
        graphicsViewNewSize.setHeight((int)(heightScale * ui.graphicsView->size().height()));
        ui.graphicsView->resize(graphicsViewNewSize);
    }
}
