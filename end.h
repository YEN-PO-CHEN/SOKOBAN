#ifndef END_H
#define END_H
#include <QObject>
#include "sokoban.h"
#include "main.h"
class end_space : public QObject
{
    Q_OBJECT
public:
    end_space(QWidget *,int);
    end_space();
    QLabel *lab[_num_box];

};

#endif // END_H
