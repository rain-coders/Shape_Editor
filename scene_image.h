#ifndef SCENE_IMAGE_H
#define SCENE_IMAGE_H

#include "ellipse.h"
#include "import_export_func.h"

class SCENE_IMAGE : public QGraphicsObject
{
    Q_OBJECT
private:
     QPixmap *pix;
     QGraphicsDropShadowEffect *drop_shadow;

     QVector<ELLIPSE*> *ellipse_vect;

     QAction *act_last_mode;

public:
    explicit SCENE_IMAGE(QGraphicsItem *parent = 0);
     ~SCENE_IMAGE();

    void Load_Image(QString fName);

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    
    void mousePressEvent(QGraphicsSceneMouseEvent *me);

    void Generate_Random_Shape();
    void Clear_Shape();
    void Set_Last_Mode(QAction *act);

    QVector<QPoint> Convert_To_Vect_Points();
    vector<POINT> *Convert_To_Export_Vect();

};

#endif // SCENE_IMAGE_H
