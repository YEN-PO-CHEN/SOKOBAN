#include "background.h"
#include "player.h"
#include "box.h"
#include "block.h"
#include "main.h"
#include "ground.h"
#include "sokoban.h"



background::background(QWidget * here)
{
    lab_back = new QLabel(here);

    lab_back->setGeometry(10,30,1080,276);
    QPixmap pix_sokoban(":/res/PNG/sokoban.png");

    //player
    lab_back->setPixmap(pix_sokoban);
    lab_back->setScaledContents(true);
}
