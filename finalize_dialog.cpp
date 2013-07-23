#include "finalize_dialog.h"

FINALIZE_DIALOG::FINALIZE_DIALOG(SCENE_IMAGE *scene_im, QWidget *parent) :
    QDialog(parent)
{
    this->scene_image = scene_im;

    init();
    align();

    connect(button_process, SIGNAL(clicked()), this, SLOT(slot_process_data()));
}

void FINALIZE_DIALOG::init()
{
    combo_graphics_engine = new QComboBox();

    QStringList list_graphics_engines;
    list_graphics_engines << "Qt Graphics Framework" << "Cocos 2D X";

    combo_graphics_engine->addItems(list_graphics_engines);

    combo_physics_engine = new QComboBox();

    QStringList list_physics_engines;
    list_physics_engines << "Qt Graphics Framework Physics" << "ChipMunk";

    combo_physics_engine->addItems(list_physics_engines);

    button_process = new QPushButton("Process");
    te_result = new QTextEdit();
}

void FINALIZE_DIALOG::align()
{
    QVBoxLayout *vlayout = new QVBoxLayout();

    vlayout->addWidget(combo_graphics_engine);
    vlayout->addWidget(combo_physics_engine);

    vlayout->addWidget(button_process);
    vlayout->addWidget(te_result);

    this->setLayout(vlayout);
}

void FINALIZE_DIALOG::slot_process_data()
{
    if(combo_graphics_engine->currentText().contains("Qt Graphics Framework")){


        if(combo_physics_engine->currentText().contains("ChipMunk")){
            te_result->setPlainText(QString(func_export_cpVect(scene_image->Convert_To_Export_Vect())));
        }

    }
}
