#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QColorDialog>
#include <QScrollArea>

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


void MainWindow::on_circle_clicked()
{
    drawpanel->isTriangle = false;
    drawpanel->isRectangle = false;
    drawpanel->isCircle = true;
}


void MainWindow::on_rectangle_clicked()
{
    drawpanel->isTriangle = false;
    drawpanel->isRectangle = true;
    drawpanel->isCircle = false;
}


void MainWindow::on_triangle_clicked()
{
   drawpanel->isTriangle = true;
   drawpanel->isRectangle = false;
   drawpanel->isCircle = false;
}


void MainWindow::on_draw_clicked()
{
    drawpanel->isTriangle = false;
    drawpanel->isRectangle = false;
    drawpanel->isCircle = false;
}


void MainWindow::on_increase_clicked()
{
    drawpanel->brushWidth ++;
    int foundsize = drawpanel->brushWidth;
    ui->found_size->setText(QString::number(foundsize));
}


void MainWindow::on_decrease_clicked()
{
    drawpanel->brushWidth --;
    int foundsize = drawpanel->brushWidth;
    ui->found_size->setText(QString::number(foundsize));
}


void MainWindow::on_fill_clicked()
{
    fill_on = true;
    drawpanel->setIsFilling(true);
}


int MainWindow::openDialog()
{
    QMessageBox dialog(QMessageBox::Question, tr("PaintQT"), tr("Do you want to save changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
    dialog.setButtonText(QMessageBox::Yes, tr("Yes"));
    dialog.setButtonText(QMessageBox::No, tr("No"));
    dialog.setButtonText(QMessageBox::Cancel, tr("Cancel"));
    dialog.setDefaultButton(QMessageBox::Yes);

    return dialog.exec();
}


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


void MainWindow::on_save_clicked()
{
    QImage saveDrawing = drawpanel->getImage();
    QString filePath = QFileDialog::getSaveFileName(this, "Save Image", "", "PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)");
    saveDrawing.save(filePath);
}


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

