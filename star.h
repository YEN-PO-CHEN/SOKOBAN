#ifndef STAR_H
#define STAR_H
#include "sokoban.h"
#include <QObject>

class star
{
public:
    star();
    star(QWidget *);
    QLabel *lab[_num_box+1];
};

#endif // STAR_H
