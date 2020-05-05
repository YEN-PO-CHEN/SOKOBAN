#include "player.h"
#include "box.h"
#include "wall.h"
#include "sokoban.h"
player::player(QWidget * here)
{
    lab = new QLabel(here);
    x_axis = 1;
    y_axis = 1;
    lab->setGeometry(x_axis*one_pixel, y_axis*one_pixel, one_pixel, one_pixel);
    QPixmap pix_player(":/res/PNG/player.jpg");

    //player
    lab->setPixmap(pix_player);
    lab->show();
    lab->setScaledContents(true);
}
