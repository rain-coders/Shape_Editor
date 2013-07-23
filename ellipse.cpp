#include "ellipse.h"

ELLIPSE::ELLIPSE(int radius, QGraphicsItem *parent) : QGraphicsObject(parent)
{
    this->radius = radius;

    this->setFlag(ItemIsMovable, true);
    this->setFlag(ItemIsSelectable, true);
    this->setOpacity(0.5);
    this->setZValue(2);
}

ELLIPSE::~ELLIPSE()
{
}

QRectF ELLIPSE::boundingRect() const
{
    return QRectF(0, 0, radius*2, radius*2);
}


void ELLIPSE::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    this->setToolTip(QString(" x : ") + QString::number(this->pos().toPoint().x()) + QString(" y : ") + QString::number(this->pos().toPoint().y()));

    painter->save();

    painter->setRenderHint(QPainter::Antialiasing, true);

    painter->setBrush(QBrush(Qt::red));

    painter->drawEllipse(0, 0, radius*2, radius*2);

    painter->restore();
}
