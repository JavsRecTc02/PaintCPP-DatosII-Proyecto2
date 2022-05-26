#ifndef RESIZE_H
#define RESIZE_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <drawpanel.h>

class Resize : public QWidget
{
    Q_OBJECT
public:
    explicit Resize(QWidget *parent = nullptr);

    void resize(int w, int h);

signals:

};

#endif // RESIZE_H
