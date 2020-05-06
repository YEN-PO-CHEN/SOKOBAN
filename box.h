#ifndef BOX_H
#define BOX_H


#include <QObject>
#include "sokoban.h"
#include "main.h"
class box : public QObject
{
    Q_OBJECT
public:

    box(QWidget *,int);
    box();
    QLabel *lab[_num_box];

};

#endif // BOX_H
