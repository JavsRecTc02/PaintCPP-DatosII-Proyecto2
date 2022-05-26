#ifndef FIGURES_H
#define FIGURES_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <drawpanel.h>

class Figures : public QObject
{
    Q_OBJECT
public:
    explicit Figures(QObject *parent = nullptr);

    void paintEvent();

    bool isRectangle;
    bool isCircle;
    bool isTriangle;
    bool isLinerec;

    bool getIsRectangle() const;
    bool getIsCircle() const;
    bool getIsTriangle() const;
    bool getIsLinerec() const;

signals:

};

#endif // FIGURES_H
