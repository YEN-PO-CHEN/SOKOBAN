#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QObject>
#include <sokoban.h>
class background
{
public:
    background();
    background(QWidget * here,int);
    QLabel *lab_back;
    static bool _1_is_Opened;
    static bool _1_is_not_Finished;
    static bool _2_is_Opened;
    static bool _2_is_not_Finished;
    static int where_am_i;
    static bool is_exec_2;
    static int x_axis;
    static int y_axis;
    static int theme;
private:

};


#endif // BACKGROUND_H
