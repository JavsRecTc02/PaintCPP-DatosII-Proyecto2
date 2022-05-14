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
    drawpanel->setColor("violet");
}


void MainWindow::on_color4_clicked()
{
    drawpanel->setColor("blue");
}


void MainWindow::on_color2_clicked()
{
    drawpanel->setColor("white");

}


void MainWindow::on_color7_clicked()
{
    drawpanel->setColor("orange");

}


void MainWindow::on_color5_clicked()
{
    drawpanel->setColor("green");

}


void MainWindow::on_color3_clicked()
{
    drawpanel->setColor("red");

}


void MainWindow::on_color1_clicked()
{
    drawpanel->setColor("black");

}


void MainWindow::on_color6_clicked()
{
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
}


void MainWindow::on_decrease_clicked()
{
    drawpanel->brushWidth --;
}

