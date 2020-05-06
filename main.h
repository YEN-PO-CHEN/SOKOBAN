#ifndef MAIN_H
#define MAIN_H
#include <QVector>
#include "sokoban.h"
using namespace std;
/*
class v_r{
public:
     vector<vector<vector<char>>> _vec_record_table;
}v_r;
*/
class box_where{
public:
    int place[_num_box][2]={{3,2},{2,5},{5,6}};

};
class block_where{
public:
    int block[_square_size][_square_size]={{1,0,0,1,1,1},
                                           {1,0,0,0,0,1},
                                           {1,1,0,1,0,1},
                                           {0,1,0,1,0,0},
                                           {0,0,0,0,1,0},
                                           {0,0,0,0,0,0}};
};
class end_where{
public:
    int place[_num_box][2]={{1,4},{1,5},{1,6}};
};

#endif // MAIN_H
