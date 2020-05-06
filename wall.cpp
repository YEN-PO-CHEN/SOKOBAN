#include "box.h"
#include "block.h"
#include "end_space.h"
#include "main.h"
#include "ground.h"
#include "player.h"
#include "sokoban.h"
#include "wall.h"
//#include "main.h"

wall::wall(QWidget * here)
{
    QPixmap pix_wall(":/res/PNG/Wall_Brown.png");

    //wall
    for (int i = 0, j = 0; j < (_square_size + 2) * (_square_size + 2); ++j)
    {
        int x = j / (_square_size + 2);
        int y = j % (_square_size + 2);
        if (x != 0 && x != (_square_size + 1))
            if (y != 0 && y != (_square_size + 1))
                continue;
        lab[i] = new QLabel(here);
        lab[i]->setGeometry(x * one_pixel, y * one_pixel, one_pixel, one_pixel);
        lab[i]->setPixmap(pix_wall);
        lab[i]->setScaledContents(true);
        ++i;
        //v_r._vec_record_table.at(x).at(y).at(0) = 'W';
    }
}
