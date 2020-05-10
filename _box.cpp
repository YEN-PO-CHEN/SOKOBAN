#include "box.h"

#include "main.h"

#include "sokoban.h"

box::box(QWidget *here, int lev)
{

    if (lev == 1)
    {
        level1 level;
        QPixmap pix_block(":/res/PNG/Crate_Brown.png");
        int i = 0;
        for (int x = 0; x < (_square_size); ++x)
            for (int y = 0; y < (_square_size); ++y)
            {
                if (level.table.at(y).at(x).at(0) != 'B')
                    continue;
                lab[i] = new QLabel(here);
                lab[i]->setGeometry(x * one_pixel, y * one_pixel, one_pixel, one_pixel);
                lab[i]->setPixmap(pix_block);
                lab[i]->raise();
                lab[i]->setScaledContents(true);

                ++i;
            }
    }

    if (lev == 2)
    {
        level2 level;
        QPixmap pix_block(":/res/PNG/Crate_Brown.png");
        int i = 0;
        for (int x = 0; x < (_square_size); ++x)
            for (int y = 0; y < (_square_size); ++y)
            {
                if (level.table.at(y).at(x).at(0) != 'B')
                    continue;
                lab[i] = new QLabel(here);
                lab[i]->setGeometry(x * one_pixel, y * one_pixel, one_pixel, one_pixel);
                lab[i]->setPixmap(pix_block);
                lab[i]->setScaledContents(true);
                lab[i]->raise();
                ++i;
            }
    }
}
