#include "level_2.h"
#include "ui_level_2.h"

level_2::level_2(QWidget *parent) :
    QDialog(parent),
    _block(this,2),
    _end(this,2),
    _box(this,2),
    _ground(this,2),
    _player(this,2),
    _wall(this,2),
    _star(this),
    _background(this,2),
    ui(new Ui::level_2)
{
    ui->setupUi(this);

    _background._2_is_Opened = true;
    _background._2_is_not_Finished = true;
    _background.where_am_i = 2;


    connect(this, SIGNAL(up_signal()), this, SLOT(up()));
    connect(this, SIGNAL(down_signal()), this, SLOT(down()));
    connect(this, SIGNAL(right_signal()), this, SLOT(right()));
    connect(this, SIGNAL(left_signal()), this, SLOT(left()));
    connect(this, SIGNAL(restart_signal()),this,SLOT(restart()));
    connect(this,SIGNAL(end_signal()),this,SLOT(back()));
    connect(ui->menuButton, SIGNAL(clicked()), this, SLOT(on_back_clicked()));
    connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(restart()));
    connect(ui->backButton,SIGNAL(clicked()), this, SLOT(end()));
    ui->backButton->hide();
    ui->restartButton->hide();
}

level_2::~level_2()
{
    delete ui;
}
void level_2::keyPressEvent(QKeyEvent *event)
{
    switch (event->key())
    {
    case Qt::Key_Up:
    case Qt::Key_W:
        emit up_signal();
        break;
    case Qt::Key_Down:
    case Qt::Key_S:
        emit down_signal();
        break;
    case Qt::Key_Right:
    case Qt::Key_D:
        emit right_signal();
        break;
    case Qt::Key_Left:
    case Qt::Key_A:
        emit left_signal();
        break;
    case Qt::Key_R:
        emit restart_signal();
        break;
    }
}
void level_2::up(){
    ui->restartButton->show();
    level2 level;
    char xy = level2_table.at(_player.y_axis-1).at(_player.x_axis).at(0);
    QPixmap pix_dark(":/res/PNG/CrateDark_Brown.png");

    if (xy=='W'||xy=='K')
        return;
    if(xy=='B'){
        char xy_minus_1 = level2_table.at(_player.y_axis-2).at(_player.x_axis).at(0);
        if(xy_minus_1=='W'||xy_minus_1=='K'||xy_minus_1=='B')
            return;
        else{
            char _which =level2_table.at(_player.y_axis-1).at(_player.x_axis).at(1);
            int i = _which -'0';
            _box.lab[i]->move((_player.x_axis)*one_pixel,(_player.y_axis-2)*one_pixel);

            level2_table.at(_player.y_axis-1).at(_player.x_axis).at(0)='0';
            level2_table.at(_player.y_axis-2).at(_player.x_axis).at(0)='B';
            level2_table.at(_player.y_axis-1).at(_player.x_axis).at(1)='0';
            level2_table.at(_player.y_axis-2).at(_player.x_axis).at(1)=_which;
            for(int m=0;m<_num_box;++m)
                if((_player.y_axis-2)==level.end[m][0]&&_player.x_axis ==level.end[m][1]){
                    _box.lab[i]->setPixmap(pix_dark);
                    if(!_bool_box[i]){
                        QPixmap pix_star(":/res/PNG/star_yes.png");
                        _star.lab[i]->setPixmap(pix_star);
                        ++count;
                        _bool_box[i]=true;
                    }
                    if(count == _num_box)
                        emit end_signal();
                    break;
                }
        }
    }

    _player.y_axis -=1;
    _player.lab->move(_player.x_axis*one_pixel, _player.y_axis*one_pixel);
    ++step;
    ui->lcdNumber->display(step);
}
void level_2::down(){
    ui->restartButton->show();
    level2 level;
    char xy = level2_table.at(_player.y_axis+1).at(_player.x_axis).at(0);
    QPixmap pix_dark(":/res/PNG/CrateDark_Brown.png");

    if (xy=='W'||xy=='K')
        return;
    if(xy=='B'){
        char xy_plus_1 = level2_table.at(_player.y_axis+2).at(_player.x_axis).at(0);
        if(xy_plus_1=='W'||xy_plus_1=='K'||xy_plus_1=='B')
            return;
        else{
            char _which =level2_table.at(_player.y_axis+1).at(_player.x_axis).at(1);
            int i = _which -'0';
            _box.lab[i]->move((_player.x_axis)*one_pixel,(_player.y_axis+2)*one_pixel);

            level2_table.at(_player.y_axis+1).at(_player.x_axis).at(0)='0';
            level2_table.at(_player.y_axis+2).at(_player.x_axis).at(0)='B';
            level2_table.at(_player.y_axis+1).at(_player.x_axis).at(1)='0';
            level2_table.at(_player.y_axis+2).at(_player.x_axis).at(1)=_which;
            for(int m=0;m<_num_box;++m)
                if((_player.y_axis+2)==level.end[m][0]&&_player.x_axis ==level.end[m][1]){
                    _box.lab[i]->setPixmap(pix_dark);
                    if(!_bool_box[i]){
                        QPixmap pix_star(":/res/PNG/star_yes.png");
                        _star.lab[i]->setPixmap(pix_star);
                        ++count;
                        _bool_box[i]=true;
                    }
                    if(count == _num_box)
                        emit end_signal();
                    break;
                }
        }
    }

    _player.y_axis +=1;
    _player.lab->move(_player.x_axis*one_pixel, _player.y_axis*one_pixel);
    ++step;
    ui->lcdNumber->display(step);
}
void level_2::left(){
    ui->restartButton->show();
    level2 level;
    char xy = level2_table.at(_player.y_axis).at(_player.x_axis-1).at(0);
    QPixmap pix_dark(":/res/PNG/CrateDark_Brown.png");
    QPixmap pix_pl_right(":/res/PNG/player.jpg");
    _player.lab->setPixmap(pix_pl_right);

    if (xy=='W'||xy=='K')
        return;
    if(xy=='B'){
        char x_minus_1_y = level2_table.at(_player.y_axis).at(_player.x_axis-2).at(0);
        if(x_minus_1_y=='W'||x_minus_1_y=='K'||x_minus_1_y=='B')
            return;
        else{
            char _which =level2_table.at(_player.y_axis).at(_player.x_axis-1).at(1);
            int i = _which -'0';
            _box.lab[i]->move((_player.x_axis-2)*one_pixel,(_player.y_axis)*one_pixel);

            level2_table.at(_player.y_axis).at(_player.x_axis-1).at(0)='0';
            level2_table.at(_player.y_axis).at(_player.x_axis-2).at(0)='B';
            level2_table.at(_player.y_axis).at(_player.x_axis-1).at(1)='0';
            level2_table.at(_player.y_axis).at(_player.x_axis-2).at(1)=_which;
            for(int m=0;m<_num_box;++m)
                if((_player.y_axis)==level.end[m][0]&&(_player.x_axis-2) ==level.end[m][1]){
                    _box.lab[i]->setPixmap(pix_dark);
                    if(!_bool_box[i]){
                        QPixmap pix_star(":/res/PNG/star_yes.png");
                        _star.lab[i]->setPixmap(pix_star);
                        ++count;
                        _bool_box[i]=true;
                    }
                    if(count == _num_box)
                        emit end_signal();
                    break;
                }
        }
    }

    _player.x_axis -=1;
    _player.lab->move(_player.x_axis*one_pixel, _player.y_axis*one_pixel);
    ++step;
    ui->lcdNumber->display(step);
}
void level_2::right(){
    ui->restartButton->show();
    level2 level;
    char xy = level2_table.at(_player.y_axis).at(_player.x_axis+1).at(0);
    QPixmap pix_dark(":/res/PNG/CrateDark_Brown.png");
    QPixmap pix_pl_right(":/res/PNG/player_r.png");
    _player.lab->setPixmap(pix_pl_right);

    if (xy=='W'||xy=='K')
        return;
    if(xy=='B'){
        char x_plus_1_y = level2_table.at(_player.y_axis).at(_player.x_axis+2).at(0);
        if(x_plus_1_y=='W'||x_plus_1_y=='K'||x_plus_1_y=='B')
            return;
        else{
            char _which =level2_table.at(_player.y_axis).at(_player.x_axis+1).at(1);
            int i = _which -'0';
            _box.lab[i]->move((_player.x_axis+2)*one_pixel,(_player.y_axis)*one_pixel);

            level2_table.at(_player.y_axis).at(_player.x_axis+1).at(0)='0';
            level2_table.at(_player.y_axis).at(_player.x_axis+2).at(0)='B';
            level2_table.at(_player.y_axis).at(_player.x_axis+1).at(1)='0';
            level2_table.at(_player.y_axis).at(_player.x_axis+2).at(1)=_which;
            for(int m=0;m<_num_box;++m)
                if((_player.y_axis)==level.end[m][0]&&(_player.x_axis+2) ==level.end[m][1]){
                    _box.lab[i]->setPixmap(pix_dark);
                    if(!_bool_box[i]){
                        if(!_bool_box[i]){
                            QPixmap pix_star(":/res/PNG/star_yes.png");
                            _star.lab[i]->setPixmap(pix_star);
                        ++count;
                        _bool_box[i]=true;
                    }
                        _bool_box[i]=true;
                    }
                    if(count == _num_box)
                        emit end_signal();
                    break;
                }
        }
    }

    _player.x_axis += 1;
    _player.lab->move(_player.x_axis*one_pixel, _player.y_axis*one_pixel);
    ++step;
    ui->lcdNumber->display(step);
}

void level_2::on_back_clicked(){
    _background._2_is_Opened = true;
    _background._2_is_not_Finished = true;
    _background.where_am_i =2;
    close();
}
void level_2::end(){

    _background._2_is_Opened = false;
    _background._2_is_not_Finished = false;
    _background.where_am_i = 2;
    close();
    ++step;
}
void level_2::restart(){
    ui->restartButton->hide();
    level2 level;

    //reset count
    count = 0;
    //reset player
        _player.lab->setGeometry(level._where_player[1]* one_pixel,level._where_player[0] * one_pixel, one_pixel, one_pixel);
        //reset x_axis y_axis
        _player.x_axis = 1;
        _player.y_axis = 5;

    //reset vector
    level2_table = level.table;

    //reset box
        //reset box color
    QPixmap pix_block(":/res/PNG/Crate_Brown.png");
    for (int a=0;a<_num_box;++a) {

        _box.lab[a]->setGeometry(level.box[a][1] * one_pixel, level.box[a][0] * one_pixel, one_pixel, one_pixel);
        _box.lab[a]->setPixmap(pix_block);
        _box.lab[a]->setScaledContents(true);
    }


    //reset _bool_box
    for(int i =0;i<_num_box;++i)
        _bool_box[i] = false;
    //reset step
        step = 0;
        ui->lcdNumber->display(step);
    //reset star
        QPixmap pix_star(":/res/PNG/star_no.png");
        for (int i =0;i<_num_box;++i) {
           _star.lab[i]->setPixmap(pix_star);
        }


}
void level_2::back(){
    ui->backButton->show();
}





