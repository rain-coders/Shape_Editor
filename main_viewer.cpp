#include "main_viewer.h"

MAIN_VIEWER::MAIN_VIEWER(QWidget *parent) :
    QMainWindow(parent)
{
    //init view framework
    view = new QGraphicsView(this);

    scene = new QGraphicsScene(view);
    scene->setBackgroundBrush(QBrush(QPixmap(":/bg")));

    view->setScene(scene);

    //add view to main window
    this->setCentralWidget(view);

    //init actions and tools bar
    init_toolbar();

    //init start image
    item_image = new SCENE_IMAGE();
    item_image->Load_Image(":images/start");

    scene->addItem(item_image);
    scene->setFocusItem(item_image);

    connect(act_open_image, SIGNAL(triggered()), this, SLOT(slot_load_image()));
    connect(act_open_shape, SIGNAL(triggered()), this, SLOT(slot_load_shape()));
    connect(act_finalize, SIGNAL(triggered()), this, SLOT(slot_finalize()));

    connect(act_add_points, SIGNAL(triggered()), this, SLOT(slot_mode_add_points()));
    connect(act_move_points, SIGNAL(triggered()), this, SLOT(slot_mode_move_points()));

    slot_mode_add_points();
}

MAIN_VIEWER::~MAIN_VIEWER()
{
    delete view;
    delete scene;
    delete tool_bar;

    delete act_open_image;
    delete act_open_shape;
    delete act_finalize;

    delete act_add_points;
    delete act_move_points;

    delete item_image;
}

void MAIN_VIEWER::init_toolbar()
{
    //init tool_bar
    tool_bar = new QToolBar("tools", this);
    this->addToolBar(Qt::TopToolBarArea, tool_bar);

    //init actions
    act_open_image = new QAction(QIcon(":icons/open_image"), "Open Image", this);
    act_open_shape = new QAction(QIcon(":icons/open_shape"), "Open Shape", this);
    act_finalize = new QAction(QIcon(":icons/finalize"), "Finilize Shape", this);

    act_add_points = new QAction(QIcon(":icons/add_points"), "Add Points", this);
    act_move_points = new QAction(QIcon(":icons/move_points"), "Move Points", this);

    QHBoxLayout *hlayout = new QHBoxLayout();
    hlayout->addStretch(1);

    QWidget *wgt = new QWidget(this);
    wgt->setLayout(hlayout);

    tool_bar->addAction(act_open_image);
    tool_bar->addAction(act_open_shape);
    tool_bar->addAction(act_finalize);

    tool_bar->addWidget(wgt);

    tool_bar->addAction(act_add_points);
    tool_bar->addAction(act_move_points);
}

void MAIN_VIEWER::resizeEvent(QResizeEvent *)
{
    scene->setSceneRect(this->rect());
    view->setSceneRect(scene->sceneRect());

    item_image->setPos(this->width()/2 - item_image->boundingRect().width()/2, this->height()/2 - item_image->boundingRect().height()/2);
}

void MAIN_VIEWER::wheelEvent(QWheelEvent *we)
{
    if(we->modifiers() == Qt::CTRL){
        if(we->delta() > 0){
            view->scale(1.1, 1.1);
        }else{
            view->scale(0.9, 0.9);
        }
    }
}

void MAIN_VIEWER::slot_load_image()
{
    QString fName = QFileDialog::getOpenFileName(this, "Open Image", "/", tr("Images (*.png *.jpg)"));

    item_image->Load_Image(fName);
    item_image->Clear_Shape();
}

void MAIN_VIEWER::slot_load_shape()
{
    QString fName = QFileDialog::getOpenFileName(this, "Open Shape", "/", tr("Shape Files (*.poly *.plist)"));
}

void MAIN_VIEWER::slot_finalize()
{
    FINALIZE_DIALOG *dialog = new FINALIZE_DIALOG(this->item_image, this);
    dialog->exec();
}

void MAIN_VIEWER::slot_mode_add_points()
{
    act_add_points->setEnabled(false);
    act_move_points->setEnabled(true);

    item_image->Set_Last_Mode(act_add_points);
}

void MAIN_VIEWER::slot_mode_move_points()
{
    act_add_points->setEnabled(true);
    act_move_points->setEnabled(false);

    item_image->Set_Last_Mode(act_move_points);
}
