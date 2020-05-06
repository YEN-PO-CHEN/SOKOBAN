#ifndef LEVEL_1_H
#define LEVEL_1_H

#include <QMainWindow>
#include "sokoban.h"
#include "main.h"
#include "block.h"
#include "box.h"
#include "end.h"
#include "ground.h"
#include "player.h"
#include "wall.h"
namespace Ui {
class level_1;
}

class level_1 : public QMainWindow
{
    Q_OBJECT

public:
    explicit level_1(QWidget *parent = nullptr);
    ~level_1();
    void keyPressEvent(QKeyEvent *e);
    block _block;
    end_space _end;
    box _box;
    ground _ground;
    player _player;
    wall _wall;
    int count =0;
    void hider();

private:
    Ui::level_1 *ui;
    vector<vector<vector<char>>> level1_table ={{{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'}},
                                                {{'W','W'},{'K','K'},{'P','P'},{'O','O'},{'K','K'},{'K','K'},{'K','K'},{'W','W'}},
                                                {{'W','W'},{'K','K'},{'O','O'},{'B','1'},{'O','O'},{'O','O'},{'K','K'},{'W','W'}},
                                                {{'W','W'},{'K','K'},{'K','K'},{'O','O'},{'K','K'},{'O','O'},{'K','K'},{'W','W'}},
                                                {{'W','W'},{'E','E'},{'K','K'},{'O','O'},{'K','K'},{'O','O'},{'O','O'},{'W','W'}},
                                                {{'W','W'},{'E','E'},{'B','0'},{'O','O'},{'O','O'},{'K','K'},{'O','O'},{'W','W'}},
                                                {{'W','W'},{'E','E'},{'O','O'},{'O','O'},{'O','O'},{'B','2'},{'O','O'},{'W','W'}},
                                                {{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'},{'W','W'}}};
    int end[_num_box][2]={{5,1},{6,1},{7,1}};



public slots:
    void up();
    void down();
    void right();
    void left();

signals:
    void up_signal();
    void down_signal();
    void right_signal();
    void left_signal();
};

#endif // LEVEL_1_H
