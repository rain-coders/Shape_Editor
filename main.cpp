#include "main_viewer.h"


int main(int c, char **v)
{
    QApplication app(c, v);

    MAIN_VIEWER view;
    view.setMinimumSize(700, 500);
    view.show();

    return app.exec();
}
