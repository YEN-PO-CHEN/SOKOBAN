#ifndef END_SPACE_H
#define END_SPACE_H
#include "sokoban.h"
class end_space : public QObject
{
    Q_OBJECT
public:
    end_space(QWidget *);
    end_space();
    QLabel *lab[_num_box];

};
#endif // END_SPACE_H
