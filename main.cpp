#include "firstwindow.h"
#include "background.h"
#include <QApplication>
bool background::_1_is_Opened = false;
bool background::_1_is_not_Finished = true;
bool background::_2_is_Opened = false;
bool background::_2_is_not_Finished = true;
int background::where_am_i = 0;
bool background::is_exec_2 =false;
int background::x_axis = 0;
int background::y_axis = 0;
int background::theme = 1;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstWindow f;

    f.show();
return a.exec();
}
