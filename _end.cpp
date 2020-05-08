#include "end.h"

#include "box.h"
#include "block.h"

#include "main.h"

#include "sokoban.h"

end_space::end_space(QWidget *here, int lev)
{
    QPixmap pix_end(":/res/PNG/EndPoint_Brown.png");
    if (lev == 1)
    {
        level1 level;
        int i = 0;
        for (int x = 0; x < (_square_size); ++x)
            for (int y = 0; y < (_square_size); ++y)
            {
                if (level.table.at(y).at(x).at(0) != 'E')
                    continue;
                lab[i] = new QLabel(here);
                lab[i]->setGeometry((x + 0.35) * one_pixel, (y + 0.35) * one_pixel, 0.3 * one_pixel, 0.3 * one_pixel);
                lab[i]->setPixmap(pix_end);
                lab[i]->setScaledContents(true);
                ++i;
            }
    }
    if (lev == 2)
    {
        level2 level;
        int i = 0;
        for (int x = 0; x < (_square_size); ++x)
            for (int y = 0; y < (_square_size); ++y)
            {
                if (level.table.at(y).at(x).at(0) != 'E')
                    continue;
                lab[i] = new QLabel(here);
                lab[i]->setGeometry((x + 0.35) * one_pixel, (y + 0.35) * one_pixel, 0.3 * one_pixel, 0.3 * one_pixel);
                lab[i]->setPixmap(pix_end);
                lab[i]->setScaledContents(true);
                ++i;
            }
    }
}
