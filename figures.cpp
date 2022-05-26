#include "figures.h"
#include <QPainter>
#include <QPainterPath>

Figures::Figures(QObject *parent)
    : QObject{parent}
{

}

/////////////////////////////////////////////////// INSERT FIGURES ///////////////////////////////////////////
//Metodo que verifica si se tiene que realizar alguna de las figuras geometricas

void DrawPanel::paintEvent(QPaintEvent *event)
{
    static bool wasMousePressed = false;

    QRect dirtyRect = event->rect();
    QPainter painter(this);
    painter.drawImage(dirtyRect, drawPanel, dirtyRect);

    if(mousePressed)
    {
        wasMousePressed = true;

        if (getIsCircle())
        {
            QRect circle = QRect(firstPoint, lastPoint);
            QPainter circlePainter(this);
            circlePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            circlePainter.drawEllipse(circle);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addEllipse(circle);
                painter.fillPath(path, fillbrush);
            }
        }
        else if (getIsRectangle())
        {
            QRect rect = QRect(firstPoint, lastPoint);
            QPainter rectanglePainter(this);
            rectanglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            rectanglePainter.drawRect(rect);
            if (isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addRoundedRect(rect,brushWidth, brushWidth);
                painter.fillPath(path,fillbrush);
            }
        }
        else if (getIsTriangle())
        {
            QPainter trianglePainter(this);
            trianglePainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            QPoint *points = new QPoint[3];
            points[0] = QPoint(firstPoint.x(), lastPoint.y());
            points[1] = QPoint(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[2] = QPoint(lastPoint);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2];
            trianglePainter.drawPolygon(polygon);
            if (isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if (getIsLinerec())
        {
            QLine rect1 = QLine(firstPoint, lastPoint);
            painter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            painter.drawLine(rect1);
        }
        else
        {
            QPainter pencilPainter(&drawPanel);
            pencilPainter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            pencilPainter.drawLine(lastPoint, firstPoint);

            firstPoint = lastPoint;
        }
    }
    else if(wasMousePressed)
    {
        QPainter painter(&drawPanel);
        painter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));

        if (getIsCircle())
        {
            QRect circle = QRect(firstPoint, lastPoint);
            painter.drawEllipse(circle);
            if(isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addEllipse(circle);
                painter.fillPath(path, fillbrush);
            }
        }
        else if (getIsRectangle())
        {
            QRect rect = QRect(firstPoint, lastPoint);
            painter.drawRect(rect);
            if (isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addRoundedRect(rect,brushWidth, brushWidth);
                painter.fillPath(path,fillbrush);
            }
        }
        else if (getIsTriangle())
        {
            QPoint *points = new QPoint[3];
            points[0] = QPoint(firstPoint.x(), lastPoint.y());
            points[1] = QPoint(((firstPoint.x() + lastPoint.x()) / 2), firstPoint.y());
            points[2] = QPoint(lastPoint);

            QPolygon polygon;
            polygon<<points[0]<<points[1]<<points[2];
            painter.drawPolygon(polygon);
            if (isFilling)
            {
                QBrush fillbrush(fillColor);
                QPainterPath path;
                path.addPolygon(polygon);
                painter.fillPath(path,fillbrush);
            }
        }
        else if (getIsLinerec())
        {
            QLine rect1 = QLine(firstPoint, lastPoint);
            painter.setPen(QPen(currentColor,brushWidth,penStyle,capStyle,joinStyle));
            painter.drawLine(rect1);
        }
        else
        {
            painter.drawImage(dirtyRect, drawPanel, dirtyRect);
        }

        wasMousePressed = false;
    }
    update();
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//Metodo para condicionar si se trata de una figura o funcion en especifico

bool DrawPanel::getIsRectangle() const
{
    return isRectangle;
}

bool DrawPanel::getIsCircle() const
{
    return isCircle;
}

bool DrawPanel::getIsTriangle() const
{
    return isTriangle;

}

bool DrawPanel::getIsLinerec() const
{
    return isLinerec;

}

bool DrawPanel::getIsLine() const
{
    return isLine;
}

void DrawPanel::setIsLine(bool value)
{
    isLine = value;
}
