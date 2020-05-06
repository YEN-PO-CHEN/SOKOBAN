#ifndef GROUND_H
#define GROUND_H
#include "sokoban.h"
class ground : public QObject
{
    Q_OBJECT

public:
    ground(QWidget *);
    ground();
    QLabel *lab[(_square_size*_square_size)];

signals:

public slots:

};
#endif // GROUND_H
