#include "scene_image.h"

SCENE_IMAGE::SCENE_IMAGE(QGraphicsItem *parent) :
    QGraphicsObject(parent)
{
    qsrand(QTime::currentTime().second());

    //create pixmap
    pix = new QPixmap();

    //configure shadow effect
    drop_shadow = new QGraphicsDropShadowEffect();

    drop_shadow->setBlurRadius(20);
    drop_shadow->setOffset(0);

    this->setGraphicsEffect(drop_shadow);

    //create ellipse list
    ellipse_vect = new QVector<ELLIPSE*>();

    this->setFlag(ItemIsFocusable, true);
    this->setZValue(1);

    //Generate_Random_Shape();
}

SCENE_IMAGE::~SCENE_IMAGE()
{
    delete pix;
    delete drop_shadow;
}

void SCENE_IMAGE::Load_Image(QString fName)
{
    this->pix->load(fName);
}

QRectF SCENE_IMAGE::boundingRect() const
{
    return QRectF(0, 0, pix->width(), pix->height());
}

void SCENE_IMAGE::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->save();
    painter->setRenderHint(QPainter::Antialiasing, true);

    painter->drawPixmap(0, 0, *pix);

    painter->setBrush(QBrush(Qt::green));
    painter->setOpacity(0.3);

    painter->drawPolygon(QPolygon(Convert_To_Vect_Points()));

    painter->restore();
}

void SCENE_IMAGE::mousePressEvent(QGraphicsSceneMouseEvent *me)
{
    if(me->button() == Qt::LeftButton && act_last_mode->text().contains("Add Points")){
        ELLIPSE *ellipse = new ELLIPSE(4, this);

        ellipse->setPos(me->pos() - QPoint(ellipse->boundingRect().width()/2, ellipse->boundingRect().height()/2));
        ellipse_vect->append(ellipse);
    }

    if(me->button() == Qt::LeftButton && act_last_mode->text().contains("Move Shape")){
        //QGraphicsPolygonItem::polygon().
    }
}

void SCENE_IMAGE::Generate_Random_Shape()
{
    int num_points = (3 + qrand()%(4));
    QPoint pos = this->pos().toPoint();

    for(int i=0;i<num_points;i++){
        QPoint random_pos;

        int x_min = pos.x() - (20 + qrand()%(49));
        int x_max = pos.x() + (20 + qrand()%(49));

        int y_min = pos.y() - (20 + qrand()%(49));
        int y_max = pos.y() + (20 + qrand()%(49));

        random_pos.setX(x_min + qrand()%(x_max - x_min + 1));
        random_pos.setY(y_min + qrand()%(y_max - y_min + 1));

        ELLIPSE *ellipse = new ELLIPSE(4, this);

        ellipse->setPos(random_pos - QPoint(ellipse->boundingRect().width()/2, ellipse->boundingRect().height()/2));
        ellipse_vect->append(ellipse);
    }
}

void SCENE_IMAGE::Clear_Shape()
{
    foreach (ELLIPSE *item, *ellipse_vect) {
        delete item;
    }

    ellipse_vect->clear();
}

void SCENE_IMAGE::Set_Last_Mode(QAction *act)
{
    this->act_last_mode = act;
}

QVector<QPoint> SCENE_IMAGE::Convert_To_Vect_Points()
{
    QVector<QPoint> vect;

    foreach (ELLIPSE *item, *ellipse_vect) {
        vect.append(item->pos().toPoint() + QPoint(item->boundingRect().width()/2, item->boundingRect().height()/2));
    }

    return vect;
}

vector<POINT> *SCENE_IMAGE::Convert_To_Export_Vect()
{
    vector<POINT> *vect = new vector<POINT>();

    foreach (ELLIPSE *item, *ellipse_vect) {
        vect->push_back(POINT(item->pos().x() + item->boundingRect().width()/2, item->pos().y() + item->boundingRect().height()/2));
    }

    return vect;
}
