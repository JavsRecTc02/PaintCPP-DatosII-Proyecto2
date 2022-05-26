#include "drawpanel.h"

#include <QImage>
#include <QMessageBox>
#include <QMouseEvent>
#include <QPainter>
#include <QPainterPath>


DrawPanel::DrawPanel(QWidget *parent) : QWidget(parent)
{
    start();
}


DrawPanel::~DrawPanel() {}

//////////////////////////// START APP VOID ////////////////////////////////////////

void DrawPanel::start()
{
    drawPanel = QImage(this->size(), QImage::Format_RGB32);
    drawPanel.fill("white");
    setColor("black");
    setFillColor("white");
    brushWidth = 5;
    setBrushWidth(brushWidth);
    setPenStyle(Qt::SolidLine);
    setCapStyle(Qt::RoundCap);
    setJoinStyle(Qt::RoundJoin);
    setIsFilling(false);
    setIsLine(true);
    isCircle = false;
    isRectangle = false;
    isTriangle = false;
    isLinerec = false;
    mousePressed = false;
}


///////////////////////////////// MOUSE EVENTS //////////////////////////////////

void DrawPanel::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        imagen12 = getImage();
        firstPoint = event->pos();
        lastPoint = event->pos();

        isDrawing = true;
        mousePressed = true;
    }
    update();
}


void DrawPanel::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && isDrawing)
    {
        lastPoint = event->pos();

    }
    update();
}


void DrawPanel::mouseReleaseEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && isDrawing)
    {
        isDrawing = false;
        mousePressed = false;
        //imagen12 = getImage();
    }
    update();
}


//////////////////////////////////// CLEAR WIDGET /////////////////////////////////////////

void DrawPanel::clear()
{
    drawPanel.fill("white");
    update();
}


//////////////////////////////// ASSIGNMENT VOIDS ////////////////////////////////////////

QColor DrawPanel::getPrevColor() const
{
    return prevColor;
}

void DrawPanel::setPrevColor(const QColor &value)
{
    prevColor = value;
}

Qt::PenStyle DrawPanel::getPenStyle() const
{
    return penStyle;
}

void DrawPanel::setPenStyle(const Qt::PenStyle &value)
{
    penStyle = value;
}

Qt::PenCapStyle DrawPanel::getCapStyle() const
{
    return capStyle;
}

void DrawPanel::setCapStyle(const Qt::PenCapStyle &value)
{
    capStyle = value;
}

Qt::PenJoinStyle DrawPanel::getJoinStyle() const
{
    return joinStyle;
}

void DrawPanel::setJoinStyle(const Qt::PenJoinStyle &value)
{
    joinStyle = value;
}


bool DrawPanel::getIsFilling() const
{
    return isFilling;
}

void DrawPanel::setIsFilling(bool value)
{
    isFilling = value;
}

QColor DrawPanel::getFillColor() const
{
    return fillColor;
}

void DrawPanel::setFillColor(QColor setFillColor)
{
    fillColor =  setFillColor;
}

QImage DrawPanel::getCopyDrawing() const
{
    return copyDrawing;
}

void DrawPanel::setCopyDrawing(const QImage &value)
{
    copyDrawing = value;
}

void DrawPanel::setColor(QColor setColor)
{
    currentColor = setColor;
}

void DrawPanel::setBrushWidth(int setBrushWidth)
{
    brushWidth = setBrushWidth;
}

QColor DrawPanel::getColor()
{
    return currentColor;
}

