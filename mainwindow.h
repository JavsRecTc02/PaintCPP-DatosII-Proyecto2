#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <drawpanel.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
//#include <resize.h>
//#include <about.h>
//#include <zoom.h>

#include <QDebug>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    int openDialog();

private:
    Ui::MainWindow *ui;
    DrawPanel *drawpanel;

private slots:
    void on_color8_clicked();

    void on_color4_clicked();

    void on_color2_clicked();

    void on_color7_clicked();

    void on_color5_clicked();

    void on_color3_clicked();

    void on_color1_clicked();
    void on_color6_clicked();
};
#endif // MAINWINDOW_H
