#ifndef BLOCK_H
#define BLOCK_H

#include <QObject>
#include "sokoban.h"
#include "main.h"
class block : public QObject
{
    Q_OBJECT
public:

    block(QWidget *,int);
    block();
    QLabel *lab[ _square_size* _square_size];

};

#endif // BLOCK_H
