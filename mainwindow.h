#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "player.h"
#include "box.h"
#include "wall.h"
#include "sokoban.h"
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
    player capoo;
    wall _wall;
    box _box;

private:
    Ui::MainWindow *ui;
    QLabel *label_ground[(_square_size*_square_size)];
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
