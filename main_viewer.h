#ifndef MAIN_VIEWER_H
#define MAIN_VIEWER_H

#include "finalize_dialog.h"

class MAIN_VIEWER : public QMainWindow
{
    Q_OBJECT
private:
    QGraphicsView *view;
    QGraphicsScene *scene;

    QToolBar *tool_bar;

    //actions
    QAction *act_open_image;
    QAction *act_open_shape;
    QAction *act_finalize;

    QAction *act_add_points;
    QAction *act_move_points;

    SCENE_IMAGE *item_image;

public:
    explicit MAIN_VIEWER(QWidget *parent = 0);
    ~MAIN_VIEWER();

    void init_toolbar();

    void resizeEvent(QResizeEvent *);
    void wheelEvent(QWheelEvent *we);

public slots:
    void slot_load_image();
    void slot_load_shape();
    void slot_finalize();

    void slot_mode_add_points();
    void slot_mode_move_points();
    
};

#endif // MAIN_VIEWER_H
