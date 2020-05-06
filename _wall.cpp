#include "wall.h"
#include "main.h"
#include "sokoban.h"

wall::wall(QWidget * here,int lev)
{
    QPixmap pix_wall(":/res/PNG/Wall_Brown.png");

        level1 level;
        int i=0;
        for (int x = 0; x < (_square_size); ++x)
            for (int y = 0; y < (_square_size); ++y){
                if(level.table.at(y).at(x).at(0)!='W')
                    continue;
                lab[i] = new QLabel(here);
                lab[i]->setGeometry(x* one_pixel, y * one_pixel, one_pixel, one_pixel);
                lab[i]->setPixmap(pix_wall);
                lab[i]->setScaledContents(true);
                ++i;
        }
}
