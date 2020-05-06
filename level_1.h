#ifndef LEVEL_1_H
#define LEVEL_1_H

#include <QDialog>
#include <QMainWindow>
#include "sokoban.h"
#include "main.h"
#include "block.h"
#include "box.h"
#include "end.h"
#include "ground.h"
#include "player.h"
#include "wall.h"
#include "level_2.h"


namespace Ui {
class level_1;
}

class level_1 : public QDialog
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
    bool is_Opened = false;
    int step = 0;

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
    //int end[_num_box][2]={{5,1},{6,1},{7,1}};
    QMainWindow *main;
    void on_Main_Menu_clicked();
    level_2 *tnd_level=new level_2;
public slots:
    void up();
    void down();
    void right();
    void left();
    void restart();
    void next_level();
    void on_back_clicked();

signals:
    void up_signal();
    void down_signal();
    void right_signal();
    void left_signal();
    void restart_signal();
    void next_signal();



};

#endif // LEVEL_1_H
