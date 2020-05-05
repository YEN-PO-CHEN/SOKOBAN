#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPixmap>
#include <QKeyEvent>
#include <QDebug>
#include <QVector>
#define one_pixel 100
#define _square_size 8

#define _num_box 3
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

private:
    Ui::MainWindow *ui;
    QLabel *label_player;
    QLabel *label_ground[(_square_size*_square_size)];
    QLabel *label_wall[(_square_size+1)*4];
    QLabel *label_box[_num_box];
    int player_x_axis;
    int player_y_axis;
    int box_place[_num_box][2]={{2,2},{3,3},{4,4}};
    vector<vector<char>> _vec_record_table;

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
