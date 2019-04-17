#include "stdafx.h"
#include "qtgui_dectectletterfromimage.h"

QtGui_DectectLetterFromImage::QtGui_DectectLetterFromImage(QWidget *parent, Qt::WindowFlags f)
    : QDialog(parent, f)
{
    ui.setupUi(this);
}
void QtGui_DectectLetterFromImage::on_inputImageButton_clicked()
{
    QFileDialog inputDlg(NULL, "Open Image", "E:/MyProject/OpenCV_ConsoleApp/OpenCV_ConsoleApp", "Image Files (*.jpg *.png)");
    if (inputDlg.exec())
    {
        // Load image
        m_qImage.load(inputDlg.selectedFiles()[0]);
        QImage tempImage = m_qImage;
        QSize newImgSize;
        // Calculate scale to fit with graphics view width or height
        float fScale, fWidthScale, fHeightScale;
        fWidthScale = (float)ui.graphicsView->size().width() / tempImage.size().width();
        fHeightScale = (float)ui.graphicsView->size().height() / tempImage.size().height();
        fScale = (fWidthScale < fHeightScale) ? fWidthScale : fHeightScale;

        // Calculate new image size
        newImgSize.setWidth(fScale * tempImage.size().width() * 0.995);
        newImgSize.setHeight(fScale * tempImage.size().height() * 0.995);

        // Scale image to new size
        tempImage = tempImage.scaled(newImgSize);
        
        QGraphicsScene* scene = new QGraphicsScene();
        // Set scene
        ui.graphicsView->setScene(scene);
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(tempImage));
        scene->addItem(item);
        ui.graphicsView->show();
        ui.inputImageEdit->setText(inputDlg.selectedFiles()[0]);
        // Process: Detect text here
        //

    }
}

void QtGui_DectectLetterFromImage::resizeEvent(QResizeEvent *event)
{
    // If this is not initiation
    if (event->oldSize().width() != 0xffffffff)
    {
        // [Resize graphics view]
        QSize oldDlgSize, newDlgSize;
        // Dialog old size and new size
        oldDlgSize = event->oldSize();
        newDlgSize = event->size();

        QSize graphicsViewNewSize;
        // Calculate new size for graphics view
        int newWidth = ui.graphicsView->size().width() + newDlgSize.width() - oldDlgSize.width();
        int newHeight = ui.graphicsView->size().height() + newDlgSize.height() - oldDlgSize.height();

        graphicsViewNewSize.setWidth(newWidth);
        graphicsViewNewSize.setHeight(newHeight);

        // Resize graphics view
        ui.graphicsView->resize(graphicsViewNewSize);
        __trace("newsize = %dx%d\n\n", ui.graphicsView->size().width(), ui.graphicsView->size().height());

        // [Resize image]
        QImage tempImage = m_qImage;
        QSize newImgSize;
        // Calculate scale to fit with graphics view width or height
        float fScale, fWidthScale, fHeightScale;
        fWidthScale = (float)ui.graphicsView->size().width() / tempImage.size().width();
        fHeightScale = (float)ui.graphicsView->size().height() / tempImage.size().height();
        fScale = (fWidthScale < fHeightScale) ? fWidthScale : fHeightScale;

        // Calculate new image size
        newImgSize.setWidth(fScale * tempImage.size().width() * 0.995);
        newImgSize.setHeight(fScale * tempImage.size().height() * 0.995);

        // Scale image to new size
        tempImage = tempImage.scaled(newImgSize);

        QGraphicsScene* scene = new QGraphicsScene();
        // Set scene
        ui.graphicsView->setScene(scene);
        QGraphicsPixmapItem* item = new QGraphicsPixmapItem(QPixmap::fromImage(tempImage));
        scene->addItem(item);
        ui.graphicsView->show();
    }
}
