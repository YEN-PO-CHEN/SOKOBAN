#include "player.h"
#include "box.h"
#include "block.h"
#include "main.h"
#include "ground.h"
#include "sokoban.h"

player::player(QWidget * here,int lev)
{
    lab = new QLabel(here);
    if(lev==1){
        x_axis = 2;
        y_axis = 1;
    }
    /*
    if(lev==1){
        x_axis = 2;
        y_axis = 1;
    }
    */
    lab->setGeometry(x_axis*one_pixel, y_axis*one_pixel, one_pixel, one_pixel);
    QPixmap pix_player(":/res/PNG/player.jpg");

    //player
    lab->setPixmap(pix_player);
    lab->show();
    lab->setScaledContents(true);
}
