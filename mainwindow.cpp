#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QScrollArea>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      drawpanel(new DrawPanel(this))
{
    ui->setupUi(this);
    //QMainWindow::showFullScreen();
    //setCentralWidget(drawpanel);
    ui->verticalLayout_2->addWidget(drawpanel);

}

MainWindow::~MainWindow()
{
    delete ui;
    delete drawpanel;
}

///////////////////////////////////////////// COLORS VOID ///////////////////////////////////////////

//Metodos para que el usuario pueda seleccionar los distintos colores
void MainWindow::on_color8_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("violet");
        drawpanel->setColor("violet");
        fill_on = false;
    }

        drawpanel->setColor("violet");
}


void MainWindow::on_color4_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("blue");
        drawpanel->setColor("blue");
        fill_on = false;
    }
    drawpanel->setColor("blue");

}


void MainWindow::on_color2_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("white");
        drawpanel->setColor("white");
        fill_on = false;
    }
    drawpanel->setColor("white");


}


void MainWindow::on_color7_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("orange");
        drawpanel->setColor("orange");
        fill_on = false;
    }

    drawpanel->setColor("orange");

}


void MainWindow::on_color5_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("green");
        drawpanel->setColor("green");
        fill_on = false;
    }
    drawpanel->setColor("green");

}


void MainWindow::on_color3_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("red");
        drawpanel->setColor("red");
        fill_on = false;
    }
    drawpanel->setColor("red");


}


void MainWindow::on_color1_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("black");
        drawpanel->setColor("black");
        fill_on = false;
    }
    drawpanel->setColor("black");
}




void MainWindow::on_color6_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("yellow");
        drawpanel->setColor("yellow");
        fill_on = false;
    }
    drawpanel->setColor("yellow");

}

void MainWindow::on_color9_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("darkGray");
        drawpanel->setColor("darkGray");
        fill_on = false;
    }
    drawpanel->setColor("darkGray");
}

void MainWindow::on_color10_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("lightGray");
        drawpanel->setColor("lightGray");
        fill_on = false;
    }
    drawpanel->setColor("lightGray");
}

void MainWindow::on_color11_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("#880015");
        drawpanel->setColor("#880015");
        fill_on = false;
    }
    drawpanel->setColor("#880015");
}

void MainWindow::on_color12_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("#5f3e2d");
        drawpanel->setColor("#5f3e2d");
        fill_on = false;
    }
    drawpanel->setColor("#5f3e2d");
}

void MainWindow::on_color13_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("#ff00ff");
        drawpanel->setColor("#ff00ff");
        fill_on = false;
    }
    drawpanel->setColor("#ff00ff");
}

void MainWindow::on_color14_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("#ff5500");
        drawpanel->setColor("#ff5500");
        fill_on = false;
    }
    drawpanel->setColor("#ff5500");
}

void MainWindow::on_color15_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("#a69e7a");
        drawpanel->setColor("#a69e7a");
        fill_on = false;
    }
    drawpanel->setColor("#a69e7a");
}

void MainWindow::on_color16_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("#aaff00");
        drawpanel->setColor("#aaff00");
        fill_on = false;
    }
    drawpanel->setColor("#aaff00");
}

void MainWindow::on_color17_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("#00004f");
        drawpanel->setColor("#00004f");
        fill_on = false;
    }
    drawpanel->setColor("#00004f");
}

void MainWindow::on_color18_clicked()
{
    if (fill_on == true){
        drawpanel->setFillColor("#47006b");
        drawpanel->setColor("#47006b");
        fill_on = false;
    }
    drawpanel->setColor("#47006b");
}

//////////////////////////////////////// FIGURES BUTTONS ///////////////////////////////////////////////

//Metodo para que el usuario seleccione el circulo
void MainWindow::on_circle_clicked()
{
    drawpanel->isTriangle = false;
    drawpanel->isRectangle = false;
    drawpanel->isCircle = true;
    drawpanel->isLinerec = false;
    drawpanel->setColor("black");
}

//Metodo para que el usuario seleccione el rectangulo
void MainWindow::on_rectangle_clicked()
{
    drawpanel->isTriangle = false;
    drawpanel->isRectangle = true;
    drawpanel->isCircle = false;
    drawpanel->isLinerec = false;
    drawpanel->setColor("black");
}

//Metodo para que el usuario seleccione el triangulo
void MainWindow::on_triangle_clicked()
{
   drawpanel->isTriangle = true;
   drawpanel->isRectangle = false;
   drawpanel->isCircle = false;
   drawpanel->isLinerec = false;
   drawpanel->setColor("black");
}

//Metodo para que el usuario seleccione la linea recta
void MainWindow::on_line_clicked()
{
    drawpanel->isTriangle = false;
    drawpanel->isRectangle = false;
    drawpanel->isCircle = false;
    drawpanel->isLinerec = true;
    drawpanel->setColor("black");
}

//Metodo para que el usuario seleccione el lapiz
void MainWindow::on_draw_clicked()
{
    drawpanel->isTriangle = false;
    drawpanel->isRectangle = false;
    drawpanel->isCircle = false;
    drawpanel->isLinerec = false;
    drawpanel->setColor("black");

}

//////////////////////////////// FOUNT ADJUST VOID /////////////////////////////////

//Metodo para que el usuario pueda aumentar el ancho del borde o lapiz
void MainWindow::on_increase_clicked()
{
    drawpanel->brushWidth ++;
    int foundsize = drawpanel->brushWidth;
    ui->found_size->setText(QString::number(foundsize));
}

//Metodo para que el usuario pueda dismunuir el ancho del borde o lapiz
void MainWindow::on_decrease_clicked()
{
    drawpanel->brushWidth --;
    int foundsize = drawpanel->brushWidth;
    ui->found_size->setText(QString::number(foundsize));
}

///////////////////////////// FILL CHECKER VOID ////////////////////////////////////

//Metodo para que el usuario utilize la funcion de pintar
void MainWindow::on_fill_clicked()
{
    fill_on = true;
    drawpanel->setIsFilling(true);
}


////////////////////////////////// IMAGES FUNCTIONS /////////////////////////////////

//Metodo que crea la caja de texto indicadora para guardar/cargar imagenes o salir del programa
int MainWindow::openDialog()
{
    QMessageBox dialog(QMessageBox::Question, tr("PaintQT"), tr("Do you want to save changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
    dialog.setButtonText(QMessageBox::Yes, tr("Yes"));
    dialog.setButtonText(QMessageBox::No, tr("No"));
    dialog.setButtonText(QMessageBox::Cancel, tr("Cancel"));
    dialog.setDefaultButton(QMessageBox::Yes);

    return dialog.exec();
}

//Metodo para insetar una imagen al widget
void MainWindow::on_insert_clicked()
{
    int dialog = openDialog();
        if(dialog == QMessageBox::Yes)
        {
           on_save_clicked();
           drawpanel->openImage();
        }
        else if(dialog == QMessageBox::No)
        {
            drawpanel->openImage();
        }
        else if(dialog == QMessageBox::Cancel)
        {
            return;
        }
}

//Metodo para guardar la imagen actual del widget
void MainWindow::on_save_clicked()
{
    QImage saveDrawing = drawpanel->getImage();
    QString filePath = QFileDialog::getSaveFileName(this, tr("Save Image"),QDir::currentPath() + ".bmp",tr(".bmp"),0,QFileDialog::DontUseNativeDialog);
    saveDrawing.save(filePath);
}

//Metodo para cerrar el programa
void MainWindow::on_close_clicked()
{
    int dialog = openDialog();
        if(dialog == QMessageBox::Yes)
        {
           on_save_clicked();
           QApplication::quit();
        }
        else if(dialog == QMessageBox::No)
        {
            QApplication::quit();
        }
        else if(dialog == QMessageBox::Cancel)
        {
            return;
        }
}

////////////////////////////////////////////// ZOOM VOIDS /////////////////////////////////////////////
//Metodos configurar el zoom insertado por el usuario

int MainWindow::getZoom() const
{
    return ui->zoom_edit->text().toInt();
}

//Metodo para incrementar el zoom
//value 100-200
void MainWindow::on_zoom_clicked()
{
    int zoom = getZoom();

    int newW = drawpanel->getImage().width() * zoom / 100;
    int newH = drawpanel->getImage().height() * zoom / 100;
    QImage zoomedImage = drawpanel->getImage();
    drawpanel->clear();
    drawpanel->resize(newW, newH);
    drawpanel->setImage(zoomedImage.scaled(newW, newH));

}
//, Qt::IgnoreAspectRatio, Qt::SmoothTransformation)
//Metodo para dismunuir el zoom
// value 20-100
void MainWindow::on_no_zoom_clicked()
{
    int zoom = getZoom();

    int newW = drawpanel->getImage().width() * zoom / 100;
    int newH = drawpanel->getImage().height() * zoom / 100;
    QImage zoomedImage = drawpanel->getImage();
    drawpanel->clear();
    drawpanel->resize(newW, newH);
    drawpanel->setImage(zoomedImage.scaled(newW, newH));
}


/////////////////////////////////////////////////////  RESIZE VOIDS   ///////////////////////////////////////////////

//Metodos para configurar el ancho y altura dado por el usuario
void MainWindow::setHeight(int value)
{
    ui->height_edit->setText(QString::number(value));
}

void MainWindow::setWidth(int value)
{
    ui->weight_edit->setText(QString::number(value));
}

int MainWindow::getHeight() const
{
    return ui->height_edit->text().toInt();
}

int MainWindow::getWidth() const
{
    return ui->weight_edit->text().toInt();
}

//Metodo para cambiar la resolucion actual
void MainWindow::on_resize_edit_clicked()
{
    int nWidth = getWidth();

    int nHeight = getHeight();

    ui->verticalLayout_2->setSpacing(20);
    drawpanel->resize(nWidth, nHeight);

}


//////////////////////////////////////// UNDO-REDO VOIDS  //////////////////////////////////////////

//Metodo para que el usuario pueda regresar al paso anterior
void MainWindow::on_undo_clicked()
{
    imageredo = drawpanel->drawPanel;
    QImage backnw = drawpanel->imagen12;
    drawpanel->drawPanel = backnw;
}

//Metodo para que el usuario pueda regresar al paso siguiente
void MainWindow::on_redo_clicked()
{
    drawpanel->drawPanel = imageredo;
}

///////////////////////////////// DELETE VOID ////////////////////////////////////////////////

//Metodo para que el mouse funcione en forma de borrador
void MainWindow::on_deleteAcc_clicked()
{
    drawpanel->isTriangle = false;
    drawpanel->isRectangle = false;
    drawpanel->isCircle = false;
    drawpanel->isLinerec = false;
    drawpanel->setColor("white");

}


////////////////////////////////// ROTATE VOID ////////////////////////////////////////////
//Metodo para activar la rotacion de imagen
void MainWindow::on_rotation_clicked()
{
    drawpanel->rotation();
}

