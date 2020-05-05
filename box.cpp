#include "mainwindow.h"
#include "player.h"
#include "box.h"
#include "wall.h"
#include "sokoban.h"
#include "main.h"
box::box(QWidget * here)
{
    box_where box;
    QPixmap pix_box(":/res/PNG/Crate_Brown.png");
    for (int i = 0; i < _num_box; ++i)
    {
        lab[i] = new QLabel(here);
        lab[i]->setGeometry(box.place[i][0] * one_pixel, box.place[i][1] * one_pixel, one_pixel, one_pixel);
        lab[i]->setPixmap(pix_box);
        lab[i]->setScaledContents(true);
    }
}
