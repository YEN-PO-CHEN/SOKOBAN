#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    initialize_vector();
    label_player = new QLabel(this);
    player_x_axis = 1;
    player_y_axis = 1;
    label_player->setGeometry(player_x_axis*one_pixel, player_y_axis*one_pixel, one_pixel, one_pixel);

    QPixmap pix_player(":/res/PNG/player.jpg");

    //player
    label_player->setPixmap(pix_player);
    label_player->setScaledContents(true);
    QPixmap pix_wall(":/res/PNG/Wall_Brown.png");

    //wall
    for (int i = 0, j = 0; j < (_square_size + 2) * (_square_size + 2); ++j)
    {
        int x = j / (_square_size + 2);
        int y = j % (_square_size + 2);
        if (x != 0 && x != (_square_size + 1))
            if (y != 0 && y != (_square_size + 1))
                continue;
        label_wall[i] = new QLabel(this);
        label_wall[i]->setGeometry(x * one_pixel, y * one_pixel, one_pixel, one_pixel);
        label_wall[i]->setPixmap(pix_wall);
        label_wall[i]->setScaledContents(true);
        ++i;
        _vec_record_table.at(x).at(y).at(0) = 'W';
    }

    //box
    QPixmap pix_box(":/res/PNG/Crate_Brown.png");
    for (int i = 0; i < _num_box; ++i)
    {
        label_box[i] = new QLabel(this);
        label_box[i]->setGeometry(box_place[i][0] * one_pixel, box_place[i][1] * one_pixel, one_pixel, one_pixel);
        label_box[i]->setPixmap(pix_box);
        label_box[i]->setScaledContents(true);
        _vec_record_table.at(box_place[i][0]).at(box_place[i][1]).at(0) = 'B';
        char now = '0'+i;
        _vec_record_table.at(box_place[i][0]).at(box_place[i][1]).at(1) = now;
    }

    /*覆蓋問題
    QPixmap pix_ground(":/res/PNG/Ground_Sand.png");
    for(int i = 0;i<(_square_size*_square_size);++i){
        int x=(i /_square_size)+1;
        int y=(i %_square_size)+1;
        label_ground[i] = new QLabel(this);
        label_ground[i]->setGeometry(x*one_pixel,y*one_pixel,one_pixel,one_pixel);
        label_ground[i]->setPixmap(pix_ground);
        label_ground[i]->setAutoFillBackground(true);
        label_ground[i]->setScaledContents(true);
    }
    */
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
    if (_vec_record_table.at(player_x_axis).at(player_y_axis-1).at(0)=='W')
        return;
    if(_vec_record_table.at(player_x_axis).at(player_y_axis-1).at(0)=='B'){
        if(_vec_record_table.at(player_x_axis).at(player_y_axis-2).at(0)=='W')
            return;
        else{
            char _which =_vec_record_table.at(player_x_axis).at(player_y_axis-1).at(1);
            int i = _which -'0';
            qDebug() << player_x_axis<< player_y_axis<<i<<endl;

            label_box[i]->move(player_x_axis*one_pixel,(player_y_axis-2)*one_pixel);

            qDebug() << "hello";
            _vec_record_table.at(player_x_axis).at(player_y_axis-1).at(0)='0';
            _vec_record_table.at(player_x_axis).at(player_y_axis-2).at(0)='B';
            _vec_record_table.at(player_x_axis).at(player_y_axis-1).at(1)='0';
            _vec_record_table.at(player_x_axis).at(player_y_axis-2).at(1)=_which;
        }
    }

    player_y_axis -=1;
    label_player->move(player_x_axis*one_pixel, player_y_axis*one_pixel);
}

void MainWindow::down()
{
    if (_vec_record_table.at(player_x_axis).at(player_y_axis+1).at(0)=='W')
        return;
    if(_vec_record_table.at(player_x_axis).at(player_y_axis+1).at(0)=='B'){
        if(_vec_record_table.at(player_x_axis).at(player_y_axis+2).at(0)=='W')
            return;
        else{
            char _which =_vec_record_table.at(player_x_axis).at(player_y_axis+1).at(1);
            int i = _which -'0';
            qDebug() << player_x_axis<< player_y_axis<<i<<endl;

            label_box[i]->move(player_x_axis*one_pixel,(player_y_axis+2)*one_pixel);

            qDebug() << "hello";
            _vec_record_table.at(player_x_axis).at(player_y_axis+1).at(0)='0';
            _vec_record_table.at(player_x_axis).at(player_y_axis+2).at(0)='B';
            _vec_record_table.at(player_x_axis).at(player_y_axis+1).at(1)='0';
            _vec_record_table.at(player_x_axis).at(player_y_axis+2).at(1)=_which;
        }
    }
    player_y_axis += 1;
    label_player->move(player_x_axis*one_pixel, player_y_axis*one_pixel);
}
void MainWindow::right()
{
    if (_vec_record_table.at(player_x_axis+1).at(player_y_axis).at(0)=='W')
        return;
    if(_vec_record_table.at(player_x_axis+1).at(player_y_axis).at(0)=='B'){
        if(_vec_record_table.at(player_x_axis+2).at(player_y_axis).at(0)=='W')
            return;
        else{
            char _which =_vec_record_table.at(player_x_axis+1).at(player_y_axis).at(1);
            int i = _which -'0';
            qDebug() << player_x_axis<< player_y_axis<<i<<endl;

            label_box[i]->move((player_x_axis+2)*one_pixel,player_y_axis*one_pixel);

            qDebug() << "hello";
            _vec_record_table.at(player_x_axis+1).at(player_y_axis).at(0)='0';
            _vec_record_table.at(player_x_axis+2).at(player_y_axis).at(0)='B';
            _vec_record_table.at(player_x_axis+1).at(player_y_axis).at(1)='0';
            _vec_record_table.at(player_x_axis+2).at(player_y_axis).at(1)=_which;
        }
    }
    if (player_x_axis == _square_size)
        return;
    player_x_axis +=1;
    label_player->move(player_x_axis*one_pixel, player_y_axis*one_pixel);
}
void MainWindow::left()
{
    if (_vec_record_table.at(player_x_axis-1).at(player_y_axis).at(0)=='W')
        return;
    if(_vec_record_table.at(player_x_axis-1).at(player_y_axis).at(0)=='B'){
        if(_vec_record_table.at(player_x_axis-2).at(player_y_axis).at(0)=='W')
            return;
        else{
            char _which =_vec_record_table.at(player_x_axis-1).at(player_y_axis).at(1);
            int i = _which -'0';
            qDebug() << player_x_axis<< player_y_axis<<i<<endl;

            label_box[i]->move((player_x_axis-2)*one_pixel,player_y_axis*one_pixel);

            qDebug() << "hello";
            _vec_record_table.at(player_x_axis-1).at(player_y_axis).at(0)='0';
            _vec_record_table.at(player_x_axis-2).at(player_y_axis).at(0)='B';
            _vec_record_table.at(player_x_axis-1).at(player_y_axis).at(1)='0';
            _vec_record_table.at(player_x_axis-2).at(player_y_axis).at(1)=_which;
        }
    }
    player_x_axis -=1;
    label_player->move(player_x_axis*one_pixel, player_y_axis*one_pixel);
}

void MainWindow::initialize_vector()
{
    _vec_record_table.resize(_square_size + 2);
    for (int i = 0; i < (_square_size + 2); ++i)
         _vec_record_table.at(i).resize(_square_size + 2);
    for (int i = 0; i < (_square_size + 2); ++i)
        for (int j = 0; j < (_square_size + 2); ++j)
            _vec_record_table.at(i).at(j).resize(2,'0');
}
