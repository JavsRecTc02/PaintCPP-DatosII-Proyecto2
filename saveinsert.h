#ifndef SAVEINSERT_H
#define SAVEINSERT_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <drawpanel.h>

class SaveInsert : public QWidget
{
    Q_OBJECT
public:
    explicit SaveInsert(QWidget *parent = nullptr);

    bool openImage();

    QImage getImage();
    void setImage(QImage image);

signals:

};

#endif // SAVEINSERT_H
