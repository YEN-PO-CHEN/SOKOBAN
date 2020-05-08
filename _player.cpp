#include "player.h"
#include "box.h"
#include "block.h"
#include "main.h"
#include "ground.h"
#include "sokoban.h"

player::player(QWidget *here, int lev)
{
    lab = new QLabel(here);
    lab_dog = new QLabel(here);
    int dog_axis[2];
    if (lev == 1)
    {
        x_axis = 2;
        y_axis = 1;
        dog_axis[0] = 6;
        dog_axis[1] = 6;
    }
    if (lev == 2)
    {
        x_axis = 1;
        y_axis = 5;
        dog_axis[0] = 5;
        dog_axis[1] = 6;
    }
    lab->setGeometry(x_axis * one_pixel, y_axis * one_pixel, one_pixel, one_pixel);
    lab_dog->setGeometry(dog_axis[1] * one_pixel, dog_axis[0] * one_pixel, one_pixel, one_pixel);
    QPixmap pix_player(":/res/PNG/player.jpg");
    QPixmap pix_dog(":/res/PNG/dog.png");

    //dog
    lab_dog->setPixmap(pix_dog);
    lab_dog->show();
    lab_dog->setScaledContents(true);
    //player
    lab->setPixmap(pix_player);
    lab->show();
    lab->raise();
    lab->setScaledContents(true);
}
