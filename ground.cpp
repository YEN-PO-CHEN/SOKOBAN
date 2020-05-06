#include "mainwindow.h"
#include "box.h"
#include "block.h"
#include "end_space.h"
#include "main.h"
#include "ground.h"
#include "player.h"
#include "sokoban.h"
#include "wall.h"
ground::ground(QWidget * here)
{
    QPixmap pix_ground(":/res/PNG/Ground_Sand.png");
    for(int i = 0;i<(_square_size*_square_size);++i){
        int x=(i /_square_size)+1;
        int y=(i %_square_size)+1;
        lab[i] = new QLabel(here);
        lab[i]->lower();
        lab[i]->setGeometry(x*one_pixel,y*one_pixel,one_pixel,one_pixel);
        lab[i]->setPixmap(pix_ground);
        lab[i]->setAutoFillBackground(true);
        lab[i]->setScaledContents(true);
    }
}
