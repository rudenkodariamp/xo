// Описание класса mgv

#ifndef MGV_H
#define MGV_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QLabel>

class mgv : public QGraphicsView
{
public:
    mgv();
    virtual void mouseDoubleClickEvent(QMouseEvent *event);
    int x[3][3];
    bool q;
    bool check();
    QGraphicsScene* myScene;
    QLabel*myLabel;
};

#endif // MGV_H
