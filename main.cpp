#include "firstwindow.h"
#include "background.h"
#include <QApplication>
bool background::_1_is_Opened = false;
bool background::_1_is_not_Finished = true;
bool background::_2_is_Opened = false;
bool background::_2_is_not_Finished = true;
bool background::is_exec_2 = false;
bool background::you_win_level_1 = false;
bool background::you_win_level_2 = false;
bool background::eaten_level_1 = false;
bool background::eaten_level_2 = false;

int background::where_am_i = 0;
int background::x_axis = 0;
int background::y_axis = 0;
int background::theme = 1;
int background::stop_step = 0;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstWindow f;

    f.show();
    return a.exec();
}
