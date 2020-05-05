#include "mainwindow.h"
#include "player.h"
#include "box.h"
#include "wall.h"
#include "sokoban.h"
//#include "main.h"
//void initialize_vector();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    //initialize_vector();
    w.resize(one_pixel*(_square_size+2),one_pixel*(_square_size+2));
    w.show();

    return a.exec();
}
/*
void initialize_vector()
{
    //initialize 3d_vector[_square_size+2][_square_size+2][2]
   v_r._vec_record_table.resize(_square_size + 2);
    for (int i = 0; i < (_square_size + 2); ++i)
        v_r._vec_record_table.at(i).resize(_square_size + 2);
    for (int i = 0; i < (_square_size + 2); ++i)
        for (int j = 0; j < (_square_size + 2); ++j)
           v_r._vec_record_table.at(i).at(j).resize(2,'0');
}
*/
