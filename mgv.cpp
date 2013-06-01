#include "mgv.h"
#include <QDebug>
#include <QMouseEvent>
#include <QLabel>

// Отрисовка поля для игры
mgv::mgv()
{
    memset(x,0,9*sizeof(int));
    q = true;
    myScene = new QGraphicsScene();
    this->setScene(myScene);

    QPen *blackpen = new QPen(Qt::black);
    myScene->addLine(0,0,0,100,*blackpen);
    myScene->addLine(33,0,33,100,*blackpen);
    myScene->addLine(-33,33,66,33,*blackpen);
    myScene->addLine(-33,66,66,66,*blackpen);

    myLabel = new QLabel(this);
    myLabel->setText(QString::fromLocal8Bit("  Ход зеленых"));
    myLabel->size().setWidth(150);
}

// Обработка события по двойному клику мыши
void mgv::mouseDoubleClickEvent(QMouseEvent *event)
{
    qDebug()<< event->pos();
    QPoint clickedPoint;
    clickedPoint.setX((event->pos().x()-10)/33);
    clickedPoint.setY((event->pos().y()-20)/33);
    qDebug()<<clickedPoint;
    if (x[clickedPoint.x()][clickedPoint.y()]) return;
    QPen* newpen;
    QBrush * newbrush;
    if (q)
    {
        newpen = new QPen(Qt::green);
        newbrush = new QBrush(Qt::green, Qt::SolidPattern);
    }
    else
    {
        newpen = new QPen(Qt::red);
        newbrush = new QBrush(Qt::red, Qt::SolidPattern);
    }

    this->myScene->addEllipse((clickedPoint.x()-1)*33+2,clickedPoint.y()*33+2,30,30,*newpen,*newbrush);
    x[clickedPoint.x()][clickedPoint.y()] = q ? 1 : 2;
    qDebug() << x[clickedPoint.x()][clickedPoint.y()];
    if (check())
        {
            memset(x,3,sizeof(int)*9);
            return;
        }
    q = !q;
    if (q)
        this->myLabel->setText(QString::fromLocal8Bit("  Ход зеленых"));
    else
        this->myLabel->setText(QString::fromLocal8Bit("  Ход красных"));
}

// Проверка на выигрыш красных либо зеленых
bool mgv::check()
{
    for (int i = 0 ; i < 2 ; i++)
        if ((x[i][0] == x[i][1] && x[i][0] == x[i][2] && x[i][0] == 1) ||
            (x[0][i] == x[1][i] && x[0][i] == x[2][i] && x[0][i] == 1))
        {
            this->myLabel->setText(QString::fromLocal8Bit("  Зеленые!"));
            return true;
        }
        if (x[0][0] == x[1][1] && x[0][0] == x[2][2] && x[0][0] == 1)
       {
            this->myLabel->setText(QString::fromLocal8Bit("  Зеленые!"));
            return true;
        }
        if (x[2][0] == x[1][1] && x[2][0] == x[0][2] && x[2][0] == 1)
        {
            this->myLabel->setText(QString::fromLocal8Bit("  Зеленые!"));
            return true;
        }

    for (int i = 0 ; i < 2 ; i++)
        if ((x[i][0] == x[i][1] && x[i][0] == x[i][2] && x[i][0] == 2) ||
            (x[0][i] == x[1][i] && x[0][i] == x[2][i] && x[0][i] == 2))
        {
            this->myLabel->setText(QString::fromLocal8Bit("  Красные!"));
            return true;
        }
        if (x[0][0] == x[1][1] && x[0][0] == x[2][2] && x[0][0] == 2)
        {
            this->myLabel->setText(QString::fromLocal8Bit("  Красные!"));
            return true;
        }
        if (x[2][0] == x[1][1] && x[2][0] == x[0][2] && x[2][0] == 2)
        {
            this->myLabel->setText(QString::fromLocal8Bit("  Красные!"));
            return true;
        }

        return false;
}
