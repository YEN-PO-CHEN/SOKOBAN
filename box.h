#ifndef BOX_H
#define BOX_H

#include "sokoban.h"

class box : public QObject
{
    Q_OBJECT

public:
    box(QWidget *);
    box();
    QLabel *lab[_num_box];

signals:

public slots:

};

#endif // BOX_H
