#ifndef LEVEL_2_H
#define LEVEL_2_H

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
#include "background.h"
#include "star.h"

namespace Ui
{
class level_2;
}

class level_2 : public QDialog
{
    Q_OBJECT

public:
    explicit level_2(QWidget *parent = nullptr);
    ~level_2();
    void keyPressEvent(QKeyEvent *e);
    block _block;
    end_space _end;
    player _player;
    box _box;
    ground _ground;
    wall _wall;
    star _star;
    int count = 0;
    /*
    static bool is_Opened;
    static bool is_not_Finished;
    */
    background _background;
    int step = 0;
    void something_check();

private:
    Ui::level_2 *ui;
    vector<vector<vector<char>>> level2_table = {{{'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}},
                                                 {{'W', 'W'}, {'K', 'K'}, {'O', 'O'}, {'O', 'O'}, {'O', 'O'}, {'O', 'O'}, {'E', 'E'}, {'W', 'W'}},
                                                 {{'W', 'W'}, {'O', 'O'}, {'O', 'O'}, {'O', 'O'}, {'O', 'O'}, {'K', 'K'}, {'K', 'K'}, {'W', 'W'}},
                                                 {{'W', 'W'}, {'O', 'O'}, {'B', '1'}, {'K', 'K'}, {'O', 'O'}, {'O', 'O'}, {'O', 'O'}, {'W', 'W'}},
                                                 {{'W', 'W'}, {'B', '0'}, {'O', 'O'}, {'K', 'K'}, {'O', 'O'}, {'O', 'O'}, {'O', 'O'}, {'W', 'W'}},
                                                 {{'W', 'W'}, {'P', 'P'}, {'O', 'O'}, {'K', 'K'}, {'B', '2'}, {'O', 'O'}, {'O', 'O'}, {'W', 'W'}},
                                                 {{'W', 'W'}, {'E', 'E'}, {'O', 'O'}, {'O', 'O'}, {'O', 'O'}, {'O', 'O'}, {'E', 'E'}, {'W', 'W'}},
                                                 {{'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}, {'W', 'W'}}};
    //int end[_num_box][2]={{5,1},{4,2},{6,5}};
    bool _bool_box[_num_box] = {false, false, false};
    QMainWindow *main;
    void on_Main_Menu_clicked();
public slots:
    void up();
    void down();
    void right();
    void left();
    void restart();
    void end();
    void on_back_clicked();
    void special();
    void back();
    void black_change();
    void brown_change();

signals:
    void up_signal();
    void down_signal();
    void right_signal();
    void left_signal();
    void restart_signal();
    void next_signal();
    void end_signal();
    void special_signal();
};

#endif // LEVEL_2_H
