#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <drawpanel.h>
#include <QMainWindow>
#include <QFileDialog>
#include <QInputDialog>
#include <QMessageBox>
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

    bool fill_on;

    int getZoom() const;

    int width;
    int height;

    //int zoom;

private:
    Ui::MainWindow *ui;
    DrawPanel *drawpanel;

private slots:

    int getWidth() const;
    int getHeight() const;

    void setWidth(int value);
    void setHeight(int value);


    int openDialog();

    void on_color8_clicked();

    void on_color4_clicked();

    void on_color2_clicked();

    void on_color7_clicked();

    void on_color5_clicked();

    void on_color3_clicked();

    void on_color1_clicked();

    void on_color6_clicked();


    void on_circle_clicked();

    void on_rectangle_clicked();

    void on_triangle_clicked();

    void on_draw_clicked();
    void on_increase_clicked();
    void on_decrease_clicked();

    void on_fill_clicked();
    void on_insert_clicked();
    void on_save_clicked();
    void on_close_clicked();
    void on_zoom_clicked();

    void on_resize_edit_clicked();
    void on_no_zoom_clicked();
};
#endif // MAINWINDOW_H
