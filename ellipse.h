#ifndef ELLIPSE_H
#define ELLIPSE_H

#include <QtGui>


//class to draw, select, and move ellipse
class ELLIPSE : public QGraphicsObject
{
private:
    int radius;

public:
    ELLIPSE(int radius, QGraphicsItem *parent = 0);
    ~ELLIPSE();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // ELLIPSE_H
