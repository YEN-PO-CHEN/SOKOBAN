#include "star.h"

star::star()
{

}
star::star(QWidget *here){
    QPixmap pix_star(":/res/PNG/star_no.png");
    for(int a=0;a<_num_box;++a){
        lab[a] = new QLabel(here);
        lab[a]->setGeometry((0.75+a*0.75)*one_pixel,850,0.75*one_pixel,0.75* one_pixel);
        lab[a]->setPixmap(pix_star);
        lab[a]->setScaledContents(true);
    }
}

