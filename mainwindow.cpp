#include "mainwindow.h"
#include "ui_mainwindow.h"

#include "box.h"
#include "block.h"
#include "end_space.h"
#include "main.h"
#include "ground.h"
#include "player.h"
#include "sokoban.h"
#include "wall.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          _wall(this),
                                          _ground(this),
                                          _block(this),
                                          _end(this),
                                          _box(this),
                                          capoo(this),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize_vector();
    //box
    count_box();
    //wall
    count_wall();
    //block
    count_block();

    connect(this, SIGNAL(up_signal()), this, SLOT(up()));
    connect(this, SIGNAL(down_signal()), this, SLOT(down()));
    connect(this, SIGNAL(right_signal()), this, SLOT(right()));
    connect(this, SIGNAL(left_signal()), this, SLOT(left()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
        emit up_signal();
        break;
    case Qt::Key_Down:
        emit down_signal();
        break;
    case Qt::Key_Right:
        emit right_signal();
        break;
    case Qt::Key_Left:
        emit left_signal();
        break;
    }
}

void MainWindow::up()
{
    if (_vec_record_table.at(capoo.x_axis).at(capoo.y_axis-1).at(0)=='W')
        return;
    if(_vec_record_table.at(capoo.x_axis).at(capoo.y_axis-1).at(0)=='B'){
        if(_vec_record_table.at(capoo.x_axis).at(capoo.y_axis-2).at(0)=='W')
            return;
        else if(_vec_record_table.at(capoo.x_axis).at(capoo.y_axis-2).at(0)=='B'){
            return;
        }
        else{
            char _which =_vec_record_table.at(capoo.x_axis).at(capoo.y_axis-1).at(1);
            int i = _which -'0';
            qDebug() << capoo.x_axis<< capoo.y_axis<<i<<endl;

            _box.lab[i]->move(capoo.x_axis*one_pixel,(capoo.y_axis-2)*one_pixel);

            qDebug() << "hello";
           _vec_record_table.at(capoo.x_axis).at(capoo.y_axis-1).at(0)='0';
           _vec_record_table.at(capoo.x_axis).at(capoo.y_axis-2).at(0)='B';
           _vec_record_table.at(capoo.x_axis).at(capoo.y_axis-1).at(1)='0';
           _vec_record_table.at(capoo.x_axis).at(capoo.y_axis-2).at(1)=_which;
        }
    }

    capoo.y_axis -=1;
    capoo.lab->move(capoo.x_axis*one_pixel, capoo.y_axis*one_pixel);
}

void MainWindow::down()
{
    if (_vec_record_table.at(capoo.x_axis).at(capoo.y_axis+1).at(0)=='W')
        return;
    if(_vec_record_table.at(capoo.x_axis).at(capoo.y_axis+1).at(0)=='B'){
        if(_vec_record_table.at(capoo.x_axis).at(capoo.y_axis+2).at(0)=='W')
            return;
        else if(_vec_record_table.at(capoo.x_axis).at(capoo.y_axis+2).at(0)=='B')
            return;
        else{
            char _which =_vec_record_table.at(capoo.x_axis).at(capoo.y_axis+1).at(1);
            int i = _which -'0';
            qDebug() << capoo.x_axis<< capoo.y_axis<<i<<endl;

            _box.lab[i]->move(capoo.x_axis*one_pixel,(capoo.y_axis+2)*one_pixel);

            qDebug() << "hello";
           _vec_record_table.at(capoo.x_axis).at(capoo.y_axis+1).at(0)='0';
           _vec_record_table.at(capoo.x_axis).at(capoo.y_axis+2).at(0)='B';
           _vec_record_table.at(capoo.x_axis).at(capoo.y_axis+1).at(1)='0';
           _vec_record_table.at(capoo.x_axis).at(capoo.y_axis+2).at(1)=_which;
        }
    }
    capoo.y_axis += 1;
    capoo.lab->move(capoo.x_axis*one_pixel, capoo.y_axis*one_pixel);
}
void MainWindow::right()
{
    if (_vec_record_table.at(capoo.x_axis+1).at(capoo.y_axis).at(0)=='W')
        return;
    if(_vec_record_table.at(capoo.x_axis+1).at(capoo.y_axis).at(0)=='B'){
        if(_vec_record_table.at(capoo.x_axis+2).at(capoo.y_axis).at(0)=='W')
            return;
        else if(_vec_record_table.at(capoo.x_axis+2).at(capoo.y_axis).at(0)=='B')
            return;
        else{
            char _which =_vec_record_table.at(capoo.x_axis+1).at(capoo.y_axis).at(1);
            int i = _which -'0';
            qDebug() << capoo.x_axis<< capoo.y_axis<<i<<endl;

            _box.lab[i]->move((capoo.x_axis+2)*one_pixel,capoo.y_axis*one_pixel);

            qDebug() << "hello";
           _vec_record_table.at(capoo.x_axis+1).at(capoo.y_axis).at(0)='0';
           _vec_record_table.at(capoo.x_axis+2).at(capoo.y_axis).at(0)='B';
           _vec_record_table.at(capoo.x_axis+1).at(capoo.y_axis).at(1)='0';
           _vec_record_table.at(capoo.x_axis+2).at(capoo.y_axis).at(1)=_which;
        }
    }
    if (capoo.x_axis == _square_size)
        return;
    capoo.x_axis +=1;
    capoo.lab->move(capoo.x_axis*one_pixel, capoo.y_axis*one_pixel);
}
void MainWindow::left()
{
    if (_vec_record_table.at(capoo.x_axis-1).at(capoo.y_axis).at(0)=='W')
        return;
    if(_vec_record_table.at(capoo.x_axis-1).at(capoo.y_axis).at(0)=='B'){
        if(_vec_record_table.at(capoo.x_axis-2).at(capoo.y_axis).at(0)=='W')
            return;
        else if(_vec_record_table.at(capoo.x_axis-2).at(capoo.y_axis).at(0)=='B')
            return;
        else{
            char _which =_vec_record_table.at(capoo.x_axis-1).at(capoo.y_axis).at(1);
            int i = _which -'0';
            qDebug() << capoo.x_axis<< capoo.y_axis<<i<<endl;

            _box.lab[i]->move((capoo.x_axis-2)*one_pixel,capoo.y_axis*one_pixel);

            qDebug() << "hello";
           _vec_record_table.at(capoo.x_axis-1).at(capoo.y_axis).at(0)='0';
           _vec_record_table.at(capoo.x_axis-2).at(capoo.y_axis).at(0)='B';
           _vec_record_table.at(capoo.x_axis-1).at(capoo.y_axis).at(1)='0';
           _vec_record_table.at(capoo.x_axis-2).at(capoo.y_axis).at(1)=_which;
        }
    }
    capoo.x_axis -=1;
    capoo.lab->move(capoo.x_axis*one_pixel, capoo.y_axis*one_pixel);
}
void MainWindow::initialize_vector()
{
    //initialize 3d_vector[_square_size+2][_square_size+2][2]
    _vec_record_table.resize(_square_size + 2);
    for (int i = 0; i < (_square_size + 2); ++i)
    _vec_record_table.at(i).resize(_square_size + 2);
    for (int i = 0; i < (_square_size + 2); ++i)
        for (int j = 0; j < (_square_size + 2); ++j)
           _vec_record_table.at(i).at(j).resize(2,'0');
}
void MainWindow::count_box(){
    box_where box;
    for (int i = 0; i < _num_box; ++i)
    {
        _vec_record_table.at(box.place[i][0]).at(box.place[i][1]).at(0) = 'B';
        char now = '0'+i;
        _vec_record_table.at(box.place[i][0]).at(box.place[i][1]).at(1) = now;
    }

}
void MainWindow::count_wall(){
    for (int i = 0, j = 0; j < (_square_size + 2) * (_square_size + 2); ++j)
    {
        int x = j / (_square_size + 2);
        int y = j % (_square_size + 2);
        if (x != 0 && x != (_square_size + 1))
            if (y != 0 && y != (_square_size + 1))
                continue;
        ++i;
        _vec_record_table.at(x).at(y).at(0) = 'W';
    }
}

void MainWindow::count_block(){
    block_where block;
    for (int c = 0; c <= _square_size; ++c)
        for (int r = 0; r <= _square_size; ++r)
        {
            if(block.block[c][r]==0)
                continue;
            _vec_record_table.at(r+1).at(c+1).at(0) = 'W';
        }
}


