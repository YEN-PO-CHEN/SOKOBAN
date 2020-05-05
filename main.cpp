#include "mainwindow.h"
#include "player.h"
#include "box.h"
#include "wall.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.resize(one_pixel*_square_size,one_pixel*_square_size);
    w.show();

    return a.exec();
}
