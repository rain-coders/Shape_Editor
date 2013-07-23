#ifndef FINALIZE_DIALOG_H
#define FINALIZE_DIALOG_H

#include "scene_image.h"

class FINALIZE_DIALOG : public QDialog
{
    Q_OBJECT
private:
    QComboBox *combo_graphics_engine;
    QComboBox *combo_physics_engine;

    QPushButton *button_process;
    QTextEdit *te_result;

    SCENE_IMAGE *scene_image;

public:
    explicit FINALIZE_DIALOG(SCENE_IMAGE *scene_im, QWidget *parent = 0);

private:
    void init();
    void align();

public slots:
    void slot_process_data();
};

#endif // FINALIZE_DIALOG_H
