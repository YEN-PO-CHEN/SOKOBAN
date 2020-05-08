#include "ground.h"
#include "box.h"
#include "block.h"

#include "main.h"
#include "ground.h"

#include "sokoban.h"

ground::ground(QWidget *here, int)
{
    QPixmap pix_ground(":/res/PNG/Ground_Sand.png");
    for (int i = 0; i < (_square_size * _square_size); ++i)
    {
        int x = i / _square_size;
        int y = i % _square_size;
        lab[i] = new QLabel(here);
        lab[i]->lower();
        lab[i]->setGeometry(x * one_pixel, y * one_pixel, one_pixel, one_pixel);
        lab[i]->setPixmap(pix_ground);
        lab[i]->setAutoFillBackground(true);
        lab[i]->setScaledContents(true);
    }
}
