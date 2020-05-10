#include "block.h"

#include "main.h"

#include "sokoban.h"

block::block(QWidget *here, int lev)
{
    if (lev == 1)
    {
        level1 level;
        QPixmap pix_block(":/res/PNG/WallRound_Beige.png");
        for (int x = 0; x < (_square_size); ++x)
            for (int y = 0; y < (_square_size); ++y)
            {

                lab[y * _square_size + x] = new QLabel(here);
                lab[y * _square_size + x]->setGeometry(x * one_pixel, y * one_pixel, one_pixel, one_pixel);
                lab[y * _square_size + x]->setPixmap(pix_block);

                lab[y * _square_size + x]->setScaledContents(true);
                if (level.table.at(y).at(x).at(0) != 'K')
                    lab[y * _square_size + x]->hide();
            }
    }

    if (lev == 2)
    {
        level2 level;
        QPixmap pix_block(":/res/PNG/WallRound_Beige.png");
        for (int x = 0; x < (_square_size); ++x)
            for (int y = 0; y < (_square_size); ++y)
            {
                lab[y * _square_size + x] = new QLabel(here);
                lab[y * _square_size + x]->setGeometry(x * one_pixel, y * one_pixel, one_pixel, one_pixel);
                lab[y * _square_size + x]->setPixmap(pix_block);
                lab[y * _square_size + x]->setScaledContents(true);
                if (level.table.at(y).at(x).at(0) != 'K')
                {
                    lab[y * _square_size + x]->hide();
                }
            }
    }
}
