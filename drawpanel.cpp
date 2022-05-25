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


void DrawPanel::start(){

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

/////////////////////////////////////// rotation ///////////////////////////////////

void DrawPanel::rotation(){
    QTransform tr;
    tr.rotate(90);
    drawPanel = drawPanel.transformed(tr);
}

////////////////////////////////////////////////////////////////////////////////////

bool DrawPanel::openImage(){

     QString openImageLocation = QFileDialog::getOpenFileName(this, tr("Open image"), "", tr("PNG (*.png);;JPEG (*.jpg *.jpeg);;BMP (*.bmp)" ));
     if(!openImageLocation.isEmpty())
     {
        drawPanel.load(openImageLocation);
        return true;
     }
     else
     {
         return false;
     }
}

QImage DrawPanel::getImage(){
    return drawPanel;
}

void DrawPanel::setImage(QImage image){
    drawPanel = image;
}

/////////////////////////////////////////////////////////////////////////////

void DrawPanel::resize(int w, int h){
    QPixmap newImage(QSize(w, h));
    newImage.fill(Qt::white);
    QPainter painter(&newImage);
    painter.drawImage(QPoint(0, 0), drawPanel);
    setImage(newImage.toImage());
    update();
}

////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////

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

////////////////////////////////////////////////////////////////////////////////////

void DrawPanel::resizeEvent(QResizeEvent *event)
{
    if (width() != drawPanel.width() || height() != drawPanel.height()){
        int nWidth, nHeight;

        if (width() > drawPanel.width())
            nWidth = width();
        if (width() <= drawPanel.width())
            nWidth = drawPanel.width();
        if (height() > drawPanel.height())
            nHeight = height();
        if (height() <= drawPanel.height())
            nHeight = drawPanel.height();

        resize(nWidth,nHeight);
    }
}


////////////////////////////////////////////////////////////////////////////////////

void DrawPanel::clear()
{
    drawPanel.fill(Qt::white);
    update();
}

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

