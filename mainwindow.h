#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "box.h"
#include "block.h"
#include "end_space.h"
#include "main.h"
#include "ground.h"
#include "player.h"
#include "sokoban.h"
#include "wall.h"
#include <QMainWindow>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *e);
    void initialize_vector();
    void count_box();
    void count_wall();
    void count_block();
    wall _wall;
    ground _ground;
    block _block;
    end_space _end;
    box _box;
    //end_space _end_space;
    player capoo;




private:
    Ui::MainWindow *ui;

    vector<vector<vector<char>>> _vec_record_table;


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

#endif // MAINWINDOW_H
