#ifndef STAR_H
#define STAR_H
#include "sokoban.h"
#include <QObject>

class star
{
public:
    star();
    star(QWidget *);
    QLabel *lab[_num_box];
};

#endif // STAR_H
