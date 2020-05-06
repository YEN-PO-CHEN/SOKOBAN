#ifndef GROUND_H
#define GROUND_H

#include <QObject>
#include "sokoban.h"
class ground : public QObject
{
    Q_OBJECT

public:
    ground(QWidget *,int);
    ground();
    QLabel *lab[(_square_size*_square_size)];


};

#endif // GROUND_H
