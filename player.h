#ifndef PLAYER_H
#define PLAYER_H
#include "sokoban.h"

class player : public QObject
{
    Q_OBJECT

public:
    player(QWidget *,int);
    player();
    QLabel *lab;
    int x_axis, y_axis;


};
#endif // PLAYER_H
