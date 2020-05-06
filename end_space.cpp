#include "box.h"
#include "block.h"
#include "end_space.h"
#include "main.h"
#include "ground.h"
#include "player.h"
#include "sokoban.h"
#include "wall.h"
end_space::end_space(QWidget * here)
{
    end_where end;
    QPixmap pix_end(":/res/PNG/EndPoint_Brown.png");
    for (int i = 0; i < _num_box; ++i)
    {
        lab[i] = new QLabel(here);
        lab[i]->setGeometry((end.place[i][0]+0.35) * one_pixel, (end.place[i][1]+0.35) * one_pixel, 0.3*one_pixel, 0.3*one_pixel);
        lab[i]->setPixmap(pix_end);
        lab[i]->setScaledContents(true);
    }
}
