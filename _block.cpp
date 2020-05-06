#include "block.h"

#include "main.h"

#include "sokoban.h"

block::block(QWidget * here, int lev )
{   
    if(lev==1){
        level1 level;
        QPixmap pix_block(":/res/PNG/WallRound_Beige.png");
        for (int x = 0; x < (_square_size); ++x)
        for (int y = 0; y < (_square_size); ++y){
            if(level.table.at(y).at(x).at(0)!='K')
                continue;
            lab[x*y] = new QLabel(here);
            lab[x*y]->setGeometry(x * one_pixel, y * one_pixel, one_pixel, one_pixel);
            lab[x*y]->setPixmap(pix_block);

            lab[x*y]->setScaledContents(true);
        }
    }

    if(lev ==2){
        level2 level;
        QPixmap pix_block(":/res/PNG/WallRound_Beige.png");
        for (int x = 0; x < (_square_size); ++x)
        for (int y = 0; y < (_square_size); ++y){
            if(level.table.at(y).at(x).at(0)!='K')
                continue;
            lab[x*y] = new QLabel(here);
            lab[x*y]->setGeometry(x * one_pixel, y * one_pixel, one_pixel, one_pixel);
            lab[x*y]->setPixmap(pix_block);

            lab[x*y]->setScaledContents(true);
        }
    }
}
