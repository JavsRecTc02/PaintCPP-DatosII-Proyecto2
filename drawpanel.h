#ifndef DRAWPANEL_H
#define DRAWPANEL_H

#include <QWidget>
#include <QMouseEvent>
#include <QPainter>
#include <QFileDialog>
#include <iostream>

class DrawPanel : public QWidget
{
    Q_OBJECT
public:
    explicit DrawPanel(QWidget *parent = nullptr);
    ~DrawPanel() override;

    virtual void mousePressEvent(QMouseEvent *event) override;
    virtual void mouseMoveEvent(QMouseEvent *event) override;
    virtual void mouseReleaseEvent(QMouseEvent *event) override;
    virtual void paintEvent(QPaintEvent *event) override;
    virtual void resizeEvent(QResizeEvent *event) override;

    void start();

    bool isRectangle;
    bool isCircle;
    bool isTriangle;
    bool isLinerec;
    QImage drawPanel;
    QImage imagen12;


    bool openImage();

    QImage getImage();
    void setImage(QImage image);

    void resize(int w, int h);

    void clear();


    void setBrushWidth (int setBrushWidth);
    int brushWidth;


    QColor getFillColor() const;
    void setFillColor(QColor setFillColor);

    void setColor(QColor setColor);
    QColor getColor();

    QColor getPrevColor() const;
    void setPrevColor(const QColor &value);

    Qt::PenStyle getPenStyle() const;
    void setPenStyle(const Qt::PenStyle &value);

    Qt::PenCapStyle getCapStyle() const;
    void setCapStyle(const Qt::PenCapStyle &value);

    Qt::PenJoinStyle getJoinStyle() const;
    void setJoinStyle(const Qt::PenJoinStyle &value);


    bool getIsRectangle() const;
    bool getIsCircle() const;
    bool getIsTriangle() const;
    bool getIsLinerec() const;


    bool getIsLine() const;
    void setIsLine(bool value);

    bool getIsFilling() const;
    void setIsFilling(bool value);


    QImage getCopyDrawing() const;
    void setCopyDrawing(const QImage &value);

private:

    QImage copyDrawing;
    QPoint lastPoint;
    QPoint firstPoint;
    QColor currentColor;
    QColor prevColor;
    QColor fillColor;
    Qt::PenStyle penStyle;
    Qt::PenCapStyle capStyle;
    Qt::PenJoinStyle joinStyle;

    bool isDrawing;

    bool isLine;
    bool isFilling;

    bool mousePressed;
};

#endif // DRAWPANEL_H
