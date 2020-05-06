#include "firstwindow.h"
#include "level_1.h"
#include "level_2.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FirstWindow f;
    f.show();


    level_1 l1;
    level_2 l2;

    l1.show();


return a.exec();
}
