#include "box.h"
#include "block.h"
#include "end_space.h"
#include "main.h"
#include "ground.h"
#include "player.h"
#include "sokoban.h"
#include "wall.h"
player::player(QWidget * here)
{
    lab = new QLabel(here);
    x_axis = 2;
    y_axis = 1;
    lab->setGeometry(x_axis*one_pixel, y_axis*one_pixel, one_pixel, one_pixel);
    QPixmap pix_player(":/res/PNG/player.jpg");

    //player
    lab->setPixmap(pix_player);
    lab->show();
    lab->setScaledContents(true);
}
