#ifndef WALL_H
#define WALL_H
#include <sokoban.h>

class wall : public QObject
{
    Q_OBJECT

public:
    wall(QWidget *);
    wall();
    QLabel *lab[(_square_size+1)*4];

signals:

public slots:

};
#endif // WALL_H
