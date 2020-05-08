#ifndef MAIN_H
#define MAIN_H
#include "sokoban.h"
#include "QVector"
using namespace std;
class level1{
public:

    vector<vector<vector<char>>> table ={{{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'}},
                                         {{'W','W'},{'K','K'},{'P','P'},{'O','O'},{'K','K'},{'K','K'},{'K','K'},{'W','W'}},
                                         {{'W','W'},{'K','K'},{'O','O'},{'B','1'},{'O','O'},{'O','O'},{'K','K'},{'W','W'}},
                                         {{'W','W'},{'K','K'},{'K','K'},{'O','O'},{'K','K'},{'O','O'},{'K','K'},{'W','W'}},
                                         {{'W','W'},{'E','E'},{'K','K'},{'O','O'},{'K','K'},{'O','O'},{'O','O'},{'W','W'}},
                                         {{'W','W'},{'E','E'},{'B','0'},{'O','O'},{'O','O'},{'K','K'},{'O','O'},{'W','W'}},
                                         {{'W','W'},{'E','E'},{'O','O'},{'O','O'},{'O','O'},{'B','2'},{'O','O'},{'W','W'}},
                                         {{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'}}};
    int end[_num_box][2]={{4,1},{5,1},{6,1}};
    int box[_num_box][2]={{5,2},{2,3},{6,5}};
    bool _bool_box[_num_box]={false,false,false};
    int special_end[2]={5,1};
    int _where_player[2]={1,2};

};

class level2{
public:
    vector<vector<vector<char>>> table ={{{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'}},
                                         {{'W','W'},{'K','K'},{'O','O'},{'O','O'},{'O','O'},{'O','O'},{'E','E'},{'W','W'}},
                                         {{'W','W'},{'O','O'},{'O','O'},{'O','O'},{'O','O'},{'K','K'},{'K','K'},{'W','W'}},
                                         {{'W','W'},{'O','O'},{'B','1'},{'K','K'},{'O','O'},{'O','O'},{'O','O'},{'W','W'}},
                                         {{'W','W'},{'B','0'},{'O','O'},{'K','K'},{'O','O'},{'O','O'},{'O','O'},{'W','W'}},
                                         {{'W','W'},{'P','P'},{'O','O'},{'K','K'},{'B','2'},{'O','O'},{'O','O'},{'W','W'}},
                                         {{'W','W'},{'E','E'},{'O','O'},{'O','O'},{'O','O'},{'O','O'},{'E','E'},{'W','W'}},
                                         {{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'}}};
    int end[_num_box][2]={{6,1},{1,6},{6,6}};
    int box[_num_box][2]={{4,1},{3,2},{5,4}};
    int special_end[2]={1,6};
    bool _bool_box[_num_box]={false,false,false};
    int _where_player[2]={5,1};

};

#endif // MAIN_H
