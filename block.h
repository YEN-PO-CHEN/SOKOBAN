#ifndef BLOCK_H
#define BLOCK_H
#include "sokoban.h"
class block : public QObject
{
    Q_OBJECT
public:
    block(QWidget *);
    block();
    QLabel *lab[ _square_size* _square_size];

};

#endif // BLOCK_H

