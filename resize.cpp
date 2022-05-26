#include "resize.h"

Resize::Resize(QWidget *parent)
    : QWidget{parent}
{

}

/////////////////////////////////////////////// RESIZE INITIAL WINDOW //////////////////////////////////
//Metodo que define las propiedades de la ventana del widget

void DrawPanel::resizeEvent(QResizeEvent *event)
{
    if (width() != drawPanel.width() || height() != drawPanel.height()){
        int nWidth, nHeight;

        if (width() > drawPanel.width())
            nWidth = width();
        if (width() <= drawPanel.width())
            nWidth = drawPanel.width();
        if (height() > drawPanel.height())
            nHeight = height();
        if (height() <= drawPanel.height())
            nHeight = drawPanel.height();

        resize(nWidth,nHeight);
    }
}

////////////////////////////////////////////////// RESIZE WINDOW ////////////////////////////////////////
//Metodo para modificar los valores de resolucion en ejecucion del widget

void DrawPanel::resize(int w, int h)
{
    QPixmap newImage(QSize(w, h));
    newImage.fill(Qt::white);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), drawPanel);
    setImage(newImage.toImage());
    update();
}

/////////////////////////////////////// rotation ///////////////////////////////////

void DrawPanel::rotation(){
    QTransform tr;
    tr.rotate(90);
    drawPanel = drawPanel.transformed(tr);
}

