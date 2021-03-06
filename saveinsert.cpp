#include "saveinsert.h"

SaveInsert::SaveInsert(QWidget *parent)
    : QWidget{parent}
{

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Metodo para guardar y abrir la carpeta de destino de la imagen
bool DrawPanel::openImage()
{
     QString openImageLocation = QFileDialog::getOpenFileName(this, tr("Open Image"),QDir::currentPath() + ".png",tr("Images Files (*.bmp)"),0,QFileDialog::DontUseNativeDialog);
     if(!openImageLocation.isEmpty())
     {
        drawPanel.load(openImageLocation);
        return true;
     }
     else
     {
         return false;
     }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Metodo que devuelve la imagen actual del widget
QImage DrawPanel::getImage()
{
    return drawPanel;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Metodo que define y cambia la imagen actual del widget
void DrawPanel::setImage(QImage image)
{
    drawPanel = image;
}
