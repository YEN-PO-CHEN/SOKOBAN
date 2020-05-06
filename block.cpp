#include "mainwindow.h"
#include "box.h"
#include "block.h"
#include "end_space.h"
#include "main.h"
#include "ground.h"
#include "player.h"
#include "sokoban.h"
#include "wall.h"
block::block(QWidget * here)
{
    block_where block;
    QPixmap pix_block(":/res/PNG/WallRound_Beige.png");
    for (int c = 0; c < _square_size; ++c)
        for (int r = 0; r < _square_size; ++r)
        {
            if(block.block[c][r]==0)
                continue;
            lab[c*r] = new QLabel(here);
            lab[c*r]->setGeometry((r+1) * one_pixel, (c+1) * one_pixel, one_pixel, one_pixel);
            lab[c*r]->setPixmap(pix_block);
            lab[c*r]->setScaledContents(true);
        }
}
