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

int MainWindow::openDialog()
{
    QMessageBox dialog(QMessageBox::Question, tr("PaintQT"), tr("Do you want to save changes?"), QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel, this);
    dialog.setButtonText(QMessageBox::Yes, tr("Yes"));
    dialog.setButtonText(QMessageBox::No, tr("No"));
    dialog.setButtonText(QMessageBox::Cancel, tr("Cancel"));
    dialog.setDefaultButton(QMessageBox::Yes);

    return dialog.exec();
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

