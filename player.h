#ifndef PLAYER_H
#define PLAYER_H
#include "sokoban.h"

class player : public QObject
{
    Q_OBJECT

public:
    player(QWidget *);
    player();
    QLabel *lab;
    int x_axis, y_axis;
signals:

public slots:

};

#endif // PLAYER_H
