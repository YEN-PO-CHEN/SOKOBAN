#include "level_1.h"
#include "ui_level_1.h"
#include <QMainWindow>
#include <QWidget>

level_1::level_1(QWidget *parent) :
    QDialog(parent),
    _block(this,1),
    _end(this,1),
    _box(this,1),
    _ground(this,1),
    _player(this,1),
    _wall(this,1),
    ui(new Ui::level_1)
{
    ui->setupUi(this);
    is_Opened = true;
    connect(this, SIGNAL(up_signal()), this, SLOT(up()));
    connect(this, SIGNAL(down_signal()), this, SLOT(down()));
    connect(this, SIGNAL(right_signal()), this, SLOT(right()));
    connect(this, SIGNAL(left_signal()), this, SLOT(left()));
    connect(this, SIGNAL(restart_signal()),this,SLOT(restart()));
    connect(this, SIGNAL(next_signal()), this, SLOT(next_level()));
    //connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(restart()));
    connect(ui->menuButton, SIGNAL(clicked()), this, SLOT(on_back_clicked()));
}

level_1::~level_1()
{
    delete ui;
}
void level_1::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {

    case Qt::Key_W:
        emit up_signal();
        break;
    case Qt::Key_S:
        emit down_signal();
        break;
    case Qt::Key_D:
        emit right_signal();
        break;
    case Qt::Key_A:
        emit left_signal();
        break;
    case Qt::Key_R:
        emit restart_signal();
        break;
    }
}
void level_1::up(){
    level1 level;
    char xy = level1_table.at(_player.y_axis-1).at(_player.x_axis).at(0);
    QPixmap pix_dark(":/res/PNG/CrateDark_Brown.png");

    if (xy=='W'||xy=='K')
        return;
    if(xy=='B'){
        char xy_minus_1 = level1_table.at(_player.y_axis-2).at(_player.x_axis).at(0);
        if(xy_minus_1=='W'||xy_minus_1=='K'||xy_minus_1=='B')
            return;
        else{
            char _which =level1_table.at(_player.y_axis-1).at(_player.x_axis).at(1);
            int i = _which -'0';
            _box.lab[i]->move((_player.x_axis)*one_pixel,(_player.y_axis-2)*one_pixel);

            level1_table.at(_player.y_axis-1).at(_player.x_axis).at(0)='0';
            level1_table.at(_player.y_axis-2).at(_player.x_axis).at(0)='B';
            level1_table.at(_player.y_axis-1).at(_player.x_axis).at(1)='0';
            level1_table.at(_player.y_axis-2).at(_player.x_axis).at(1)=_which;
            for(int m=0;m<_num_box;++m)
                if((_player.y_axis-2)==level.end[m][0]&&_player.x_axis ==level.end[m][1]){
                    _box.lab[i]->setPixmap(pix_dark);
                    ++count;
                    if(count == _num_box)
                        emit next_signal();
                    break;
                }
        }
    }

    _player.y_axis -=1;
    _player.lab->move(_player.x_axis*one_pixel, _player.y_axis*one_pixel);
}
void level_1::down(){
    level1 level;
    char xy = level1_table.at(_player.y_axis+1).at(_player.x_axis).at(0);
    QPixmap pix_dark(":/res/PNG/CrateDark_Brown.png");

    if (xy=='W'||xy=='K')
        return;
    if(xy=='B'){
        char xy_plus_1 = level1_table.at(_player.y_axis+2).at(_player.x_axis).at(0);
        if(xy_plus_1=='W'||xy_plus_1=='K'||xy_plus_1=='B')
            return;
        else{
            char _which =level1_table.at(_player.y_axis+1).at(_player.x_axis).at(1);
            int i = _which -'0';
            _box.lab[i]->move((_player.x_axis)*one_pixel,(_player.y_axis+2)*one_pixel);

            level1_table.at(_player.y_axis+1).at(_player.x_axis).at(0)='0';
            level1_table.at(_player.y_axis+2).at(_player.x_axis).at(0)='B';
            level1_table.at(_player.y_axis+1).at(_player.x_axis).at(1)='0';
            level1_table.at(_player.y_axis+2).at(_player.x_axis).at(1)=_which;
            for(int m=0;m<_num_box;++m)
                if((_player.y_axis+2)==level.end[m][0]&&_player.x_axis ==level.end[m][1]){
                    _box.lab[i]->setPixmap(pix_dark);
                    ++count;
                    if(count == _num_box)
                        emit next_signal();
                    break;
                }
        }
    }

    _player.y_axis +=1;
    _player.lab->move(_player.x_axis*one_pixel, _player.y_axis*one_pixel);
}
void level_1::left(){
    level1 level;
    char xy = level1_table.at(_player.y_axis).at(_player.x_axis-1).at(0);
    QPixmap pix_dark(":/res/PNG/CrateDark_Brown.png");

    if (xy=='W'||xy=='K')
        return;
    if(xy=='B'){
        char x_minus_1_y = level1_table.at(_player.y_axis).at(_player.x_axis-2).at(0);
        if(x_minus_1_y=='W'||x_minus_1_y=='K'||x_minus_1_y=='B')
            return;
        else{
            char _which =level1_table.at(_player.y_axis).at(_player.x_axis-1).at(1);
            int i = _which -'0';
            _box.lab[i]->move((_player.x_axis-2)*one_pixel,(_player.y_axis)*one_pixel);

            level1_table.at(_player.y_axis).at(_player.x_axis-1).at(0)='0';
            level1_table.at(_player.y_axis).at(_player.x_axis-2).at(0)='B';
            level1_table.at(_player.y_axis).at(_player.x_axis-1).at(1)='0';
            level1_table.at(_player.y_axis).at(_player.x_axis-2).at(1)=_which;
            for(int m=0;m<_num_box;++m)
                if((_player.y_axis)==level.end[m][0]&&(_player.x_axis-2) ==level.end[m][1]){
                    _box.lab[i]->setPixmap(pix_dark);
                    ++count;
                    if(count == _num_box)
                        emit next_signal();
                    break;
                }
        }
    }

    _player.x_axis -=1;
    _player.lab->move(_player.x_axis*one_pixel, _player.y_axis*one_pixel);
}
void level_1::right(){
    level1 level;
    char xy = level1_table.at(_player.y_axis).at(_player.x_axis+1).at(0);
    QPixmap pix_dark(":/res/PNG/CrateDark_Brown.png");

    if (xy=='W'||xy=='K')
        return;
    if(xy=='B'){
        char x_plus_1_y = level1_table.at(_player.y_axis).at(_player.x_axis+2).at(0);
        if(x_plus_1_y=='W'||x_plus_1_y=='K'||x_plus_1_y=='B')
            return;
        else{
            char _which =level1_table.at(_player.y_axis).at(_player.x_axis+1).at(1);
            int i = _which -'0';
            _box.lab[i]->move((_player.x_axis+2)*one_pixel,(_player.y_axis)*one_pixel);

            level1_table.at(_player.y_axis).at(_player.x_axis+1).at(0)='0';
            level1_table.at(_player.y_axis).at(_player.x_axis+2).at(0)='B';
            level1_table.at(_player.y_axis).at(_player.x_axis+1).at(1)='0';
            level1_table.at(_player.y_axis).at(_player.x_axis+2).at(1)=_which;
            for(int m=0;m<_num_box;++m)
                if((_player.y_axis)==level.end[m][0]&&(_player.x_axis+2) == level.end[m][1]){
                    _box.lab[i]->setPixmap(pix_dark);
                    ++count;
                    if(count == _num_box)
                        emit next_signal();
                    qDebug() <<"here";
                    break;
                }
        }
    }

    _player.x_axis += 1;
    _player.lab->move(_player.x_axis*one_pixel, _player.y_axis*one_pixel);
}
void level_1::restart(){

}
void level_1::on_Main_Menu_clicked(){
    main->show();
    close();
}

void level_1::next_level(){
    this->hide();
    is_Opened = false;
    tnd_level->resize(one_pixel*(_square_size+2),one_pixel*(_square_size+2));
    tnd_level->show();
}
void level_1::on_back_clicked(){
    close();
}


