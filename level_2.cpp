#include "level_2.h"
#include "ui_level_2.h"

level_2::level_2(QWidget *parent) : QDialog(parent),
                                    _block(this, 2),
                                    _end(this, 2),
                                    _player(this, 2),
                                    _box(this, 2),
                                    _ground(this, 2),
                                    _wall(this),
                                    _star(this),
                                    _background(this, 2),
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
    connect(this, SIGNAL(restart_signal()), this, SLOT(restart()));
    connect(this, SIGNAL(end_signal()), this, SLOT(back()));
    connect(this, SIGNAL(special_signal()), this, SLOT(special()));
    connect(ui->menuButton, SIGNAL(clicked()), this, SLOT(on_back_clicked()));
    connect(ui->restartButton, SIGNAL(clicked()), this, SLOT(restart()));
    connect(ui->backButton, SIGNAL(clicked()), this, SLOT(end()));
    connect(ui->specialButton, SIGNAL(clicked()), this, SLOT(end()));
    connect(ui->blackButton, SIGNAL(clicked()), this, SLOT(black_change()));
    connect(ui->brownButton, SIGNAL(clicked()), this, SLOT(brown_change()));
    ui->backButton->hide();
    ui->restartButton->hide();
    ui->specialButton->hide();
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
void level_2::up()
{
    ui->restartButton->show();
    level2 level;
    char xy = level2_table.at(_player.y_axis - 1).at(_player.x_axis).at(0);
    QPixmap pix_d_t_1(":/res/PNG/CrateDark_Brown.png");
    QPixmap pix_d_t_2(":/res/PNG/CrateDark_Black.png");

    if (xy == 'W' || xy == 'K')
        return;
    if (xy == 'B')
    {
        char xy_minus_1 = level2_table.at(_player.y_axis - 2).at(_player.x_axis).at(0);
        if (xy_minus_1 == 'W' || xy_minus_1 == 'K' || xy_minus_1 == 'B')
            return;
        else
        {
            char _which = level2_table.at(_player.y_axis - 1).at(_player.x_axis).at(1);
            int i = _which - '0';
            _box.lab[i]->move((_player.x_axis) * one_pixel, (_player.y_axis - 2) * one_pixel);

            level2_table.at(_player.y_axis - 1).at(_player.x_axis).at(0) = '0';
            level2_table.at(_player.y_axis - 2).at(_player.x_axis).at(0) = 'B';
            level2_table.at(_player.y_axis - 1).at(_player.x_axis).at(1) = '0';
            level2_table.at(_player.y_axis - 2).at(_player.x_axis).at(1) = _which;
            for (int m = 0; m < _num_box; ++m)
                if ((_player.y_axis - 2) == level.end[m][0] && _player.x_axis == level.end[m][1])
                {
                    if (_background.theme == 1)
                        _box.lab[i]->setPixmap(pix_d_t_1);
                    if (_background.theme == 2)
                        _box.lab[i]->setPixmap(pix_d_t_2);
                    if (!_bool_box[i])
                    {
                        QPixmap pix_star(":/res/PNG/star_yes.png");
                        _star.lab[i]->setPixmap(pix_star);
                        ++count;
                        _bool_box[i] = true;
                    }
                    if (count == _num_box)
                        emit end_signal();
                    break;
                }
        }
    }

    _player.y_axis -= 1;
    something_check();
}
void level_2::down()
{
    ui->restartButton->show();
    level2 level;
    char xy = level2_table.at(_player.y_axis + 1).at(_player.x_axis).at(0);
    QPixmap pix_d_t_1(":/res/PNG/CrateDark_Brown.png");
    QPixmap pix_d_t_2(":/res/PNG/CrateDark_Black.png");

    if (xy == 'W' || xy == 'K')
        return;
    if (xy == 'B')
    {
        char xy_plus_1 = level2_table.at(_player.y_axis + 2).at(_player.x_axis).at(0);
        if (xy_plus_1 == 'W' || xy_plus_1 == 'K' || xy_plus_1 == 'B')
            return;
        else
        {
            char _which = level2_table.at(_player.y_axis + 1).at(_player.x_axis).at(1);
            int i = _which - '0';
            _box.lab[i]->move((_player.x_axis) * one_pixel, (_player.y_axis + 2) * one_pixel);

            level2_table.at(_player.y_axis + 1).at(_player.x_axis).at(0) = '0';
            level2_table.at(_player.y_axis + 2).at(_player.x_axis).at(0) = 'B';
            level2_table.at(_player.y_axis + 1).at(_player.x_axis).at(1) = '0';
            level2_table.at(_player.y_axis + 2).at(_player.x_axis).at(1) = _which;
            for (int m = 0; m < _num_box; ++m)
                if ((_player.y_axis + 2) == level.end[m][0] && _player.x_axis == level.end[m][1])
                {
                    if (_background.theme == 1)
                        _box.lab[i]->setPixmap(pix_d_t_1);
                    if (_background.theme == 2)
                        _box.lab[i]->setPixmap(pix_d_t_2);
                    if (!_bool_box[i])
                    {
                        QPixmap pix_star(":/res/PNG/star_yes.png");
                        _star.lab[i]->setPixmap(pix_star);
                        ++count;
                        _bool_box[i] = true;
                    }
                    if (count == _num_box)
                        emit end_signal();
                    break;
                }
        }
    }

    _player.y_axis += 1;
    something_check();
}
void level_2::left()
{
    ui->restartButton->show();
    level2 level;
    char xy = level2_table.at(_player.y_axis).at(_player.x_axis - 1).at(0);
    QPixmap pix_d_t_1(":/res/PNG/CrateDark_Brown.png");
    QPixmap pix_d_t_2(":/res/PNG/CrateDark_Black.png");
    if (_background.eaten_level_2)
    {
        QPixmap pix_eaten(":/res/PNG/capoo_dog.png");
        _player.lab->setPixmap(pix_eaten);
    }
    else
    {
        QPixmap pix_pl_right(":/res/PNG/player.jpg");
        _player.lab->setPixmap(pix_pl_right);
    }

    if (xy == 'W' || xy == 'K')
        return;
    if (xy == 'B')
    {
        char x_minus_1_y = level2_table.at(_player.y_axis).at(_player.x_axis - 2).at(0);
        if (x_minus_1_y == 'W' || x_minus_1_y == 'K' || x_minus_1_y == 'B')
            return;
        else
        {
            char _which = level2_table.at(_player.y_axis).at(_player.x_axis - 1).at(1);
            int i = _which - '0';
            _box.lab[i]->move((_player.x_axis - 2) * one_pixel, (_player.y_axis) * one_pixel);

            level2_table.at(_player.y_axis).at(_player.x_axis - 1).at(0) = '0';
            level2_table.at(_player.y_axis).at(_player.x_axis - 2).at(0) = 'B';
            level2_table.at(_player.y_axis).at(_player.x_axis - 1).at(1) = '0';
            level2_table.at(_player.y_axis).at(_player.x_axis - 2).at(1) = _which;
            for (int m = 0; m < _num_box; ++m)
                if ((_player.y_axis) == level.end[m][0] && (_player.x_axis - 2) == level.end[m][1])
                {
                    if (_background.theme == 1)
                        _box.lab[i]->setPixmap(pix_d_t_1);
                    if (_background.theme == 2)
                        _box.lab[i]->setPixmap(pix_d_t_2);
                    if (!_bool_box[i])
                    {
                        QPixmap pix_star(":/res/PNG/star_yes.png");
                        _star.lab[i]->setPixmap(pix_star);
                        ++count;
                        _bool_box[i] = true;
                    }
                    if (count == _num_box)
                        emit end_signal();
                    break;
                }
        }
    }

    _player.x_axis -= 1;
    something_check();
}
void level_2::right()
{
    ui->restartButton->show();
    level2 level;
    char xy = level2_table.at(_player.y_axis).at(_player.x_axis + 1).at(0);
    QPixmap pix_d_t_1(":/res/PNG/CrateDark_Brown.png");
    QPixmap pix_d_t_2(":/res/PNG/CrateDark_Black.png");
    if (_background.eaten_level_2)
    {
        QPixmap pix_eaten(":/res/PNG/capoo_dog_r.png");
        _player.lab->setPixmap(pix_eaten);
    }
    else
    {
        QPixmap pix_pl_right(":/res/PNG/player_r.png");
        _player.lab->setPixmap(pix_pl_right);
    }

    if (xy == 'W' || xy == 'K')
        return;
    if (xy == 'B')
    {
        char x_plus_1_y = level2_table.at(_player.y_axis).at(_player.x_axis + 2).at(0);
        if (x_plus_1_y == 'W' || x_plus_1_y == 'K' || x_plus_1_y == 'B')
            return;
        else
        {
            char _which = level2_table.at(_player.y_axis).at(_player.x_axis + 1).at(1);
            int i = _which - '0';
            _box.lab[i]->move((_player.x_axis + 2) * one_pixel, (_player.y_axis) * one_pixel);

            level2_table.at(_player.y_axis).at(_player.x_axis + 1).at(0) = '0';
            level2_table.at(_player.y_axis).at(_player.x_axis + 2).at(0) = 'B';
            level2_table.at(_player.y_axis).at(_player.x_axis + 1).at(1) = '0';
            level2_table.at(_player.y_axis).at(_player.x_axis + 2).at(1) = _which;
            for (int m = 0; m < _num_box; ++m)
                if ((_player.y_axis) == level.end[m][0] && (_player.x_axis + 2) == level.end[m][1])
                {
                    if (_background.theme == 1)
                        _box.lab[i]->setPixmap(pix_d_t_1);
                    if (_background.theme == 2)
                        _box.lab[i]->setPixmap(pix_d_t_2);
                    if (!_bool_box[i])
                    {
                        if (!_bool_box[i])
                        {
                            QPixmap pix_star(":/res/PNG/star_yes.png");
                            _star.lab[i]->setPixmap(pix_star);
                            ++count;
                            _bool_box[i] = true;
                        }
                        _bool_box[i] = true;
                    }
                    if (count == _num_box)
                        emit end_signal();
                    break;
                }
        }
    }

    _player.x_axis += 1;
    something_check();
}
void level_2::on_back_clicked()
{
    _background._2_is_Opened = true;
    _background._2_is_not_Finished = true;
    _background.where_am_i = 2;
    hide();
}
void level_2::end()
{

    _background._2_is_Opened = false;
    _background._2_is_not_Finished = false;
    _background.where_am_i = 2;
    ui->specialButton->hide();
    hide();
    //++step;
}
void level_2::restart()
{
    ui->restartButton->hide();
    level2 level;

    //reset count
    count = 0;
    //reset player
    _player.lab->setGeometry(level._where_player[1] * one_pixel, level._where_player[0] * one_pixel, one_pixel, one_pixel);
    //reset x_axis y_axis
    _player.x_axis = 1;
    _player.y_axis = 5;

    //reset vector
    level2_table = level.table;

    //reset box
    //reset box color
    if (_background.theme == 1)
        for (int a = 0; a < _num_box; ++a)
        {
            QPixmap pix_box(":/res/PNG/Crate_Brown.png");
            _box.lab[a]->setGeometry(level.box[a][1] * one_pixel, level.box[a][0] * one_pixel, one_pixel, one_pixel);
            _box.lab[a]->setPixmap(pix_box);
            _box.lab[a]->setScaledContents(true);
            _box.lab[a]->raise();
        }

    if (_background.theme == 2)
        for (int a = 0; a < _num_box; ++a)
        {
            QPixmap pix_box(":/res/PNG/Crate_Black.png");
            _box.lab[a]->setGeometry(level.box[a][1] * one_pixel, level.box[a][0] * one_pixel, one_pixel, one_pixel);
            _box.lab[a]->setPixmap(pix_box);
            _box.lab[a]->setScaledContents(true);
        }

    //reset _bool_box
    for (int i = 0; i < _num_box; ++i)
        _bool_box[i] = false;
    //reset step
    step = 0;
    ui->lcdNumber->display(step);
    //reset star
    QPixmap pix_star(":/res/PNG/star_no.png");
    for (int i = 0; i <= _num_box; ++i)
        _star.lab[i]->setPixmap(pix_star);
    //reset you win
    _background.you_win_level_2 = false;
    _background.sp_win_level_2 = false;
    //eaten_level_1
    _background.eaten_level_2 = false;
    //reset player
    QPixmap pix_pl_right(":/res/PNG/player.jpg");
    _player.lab->setPixmap(pix_pl_right);
    _player.lab_dog->show();
    //hide you win
    _background.lab_you_win->hide();
    _background.lab_special_win->hide();
}
void level_2::back()
{
    ++step;
    _background.you_win_level_2 = true;
    _background.stop_step = step;
    ui->lcdNumber->display(_background.stop_step);
    if (!_background.sp_win_level_2)
        _background.lab_you_win->show();
    else
        _background.lab_you_win->hide();
    ui->backButton->show();
}
void level_2::special()
{
    ui->specialButton->show();
    QPixmap pix_star(":/res/PNG/star_sp.png");
    _star.lab[3]->setPixmap(pix_star);
    _background.sp_win_level_2 = true;
    _background.lab_special_win->show();
}
void level_2::something_check()
{
    level2 level;
    _player.lab->move(_player.x_axis * one_pixel, _player.y_axis * one_pixel);
    ++step;
    if (_player.x_axis == level.dog[1] && _player.y_axis == level.dog[0])
    {
        QPixmap pix_eaten(":/res/PNG/capoo_dog.png");
        _player.lab->setPixmap(pix_eaten);
        _player.lab_dog->hide();
        _background.eaten_level_2 = true;
    }
    if (!_background.you_win_level_2)
        ui->lcdNumber->display(step);
    if (_player.x_axis == level.special_end[1] && _player.y_axis == level.special_end[0])
        emit special_signal();
    return;
}
void level_2::black_change()
{
    _background.theme = 2;
    QPixmap pix_block(":/res/PNG/WallRound_Gray.png");
    QPixmap pix_box(":/res/PNG/Crate_Black.png");
    QPixmap pix_end(":/res/PNG/EndPoint_Gray.png");
    QPixmap pix_ground(":/res/PNG/Ground_Concrete.png");
    QPixmap pix_wall(":/res/PNG/Wall_Black.png");
    QPixmap pix_box_Dark(":/res/PNG/CrateDark_Black.png");
    level2 level;
    //block
    for (int x = 0; x < (_square_size); ++x)
    {
        for (int y = 0; y < (_square_size); ++y)
        {
            if (level.table.at(y).at(x).at(1) != 'K')
                continue;
            _block.lab[y * _square_size + x]->setPixmap(pix_block);
            _block.lab[y * _square_size + x]->show();
        }
    }

    //box
    for (int m = 0; m < _num_box; ++m)
    {
        if (_bool_box[m])
            _box.lab[m]->setPixmap(pix_box_Dark);
        else
            _box.lab[m]->setPixmap(pix_box);
        _box.lab[m]->show();
        _box.lab[m]->raise();
    }

    //end
    for (int m = 0; m < _num_box; ++m)
    {
        _end.lab[m]->setPixmap(pix_end);
        _end.lab[m]->show();
    }

    //ground
    for (int m = 0; m < (_square_size * _square_size); ++m)
    {
        _ground.lab[m]->setPixmap(pix_ground);
        _ground.lab[m]->show();
    }

    //wall
    for (int m = 0; m < ((_square_size - 1) * 4); ++m)
    {
        _wall.lab[m]->setPixmap(pix_wall);
        _wall.lab[m]->show();
    }
}
void level_2::brown_change()
{
    _background.theme = 1;
    QPixmap pix_block(":/res/PNG/WallRound_Beige.png");
    QPixmap pix_end(":/res/PNG/EndPoint_Brown.png");
    QPixmap pix_ground(":/res/PNG/Ground_Sand.png");
    QPixmap pix_wall(":/res/PNG/Wall_Brown.png");
    QPixmap pix_box(":/res/PNG/Crate_Brown.png");
    QPixmap pix_box_Dark(":/res/PNG/CrateDark_Brown.png");

    level2 level;
    //block
    for (int x = 0; x < (_square_size); ++x)
    {
        for (int y = 0; y < (_square_size); ++y)
        {
            if (level.table.at(y).at(x).at(0) != 'K')
                continue;

            _block.lab[y * _square_size + x]->setPixmap(pix_block);
            _block.lab[y * _square_size + x]->show();
        }
    }

    //box
    for (int m = 0; m < _num_box; ++m)
    {
        if (_bool_box[m])
            _box.lab[m]->setPixmap(pix_box_Dark);
        else
            _box.lab[m]->setPixmap(pix_box);
        _box.lab[m]->show();
        _box.lab[m]->raise();
    }

    //end
    for (int m = 0; m < _num_box; ++m)
    {
        _end.lab[m]->setPixmap(pix_end);
        _end.lab[m]->show();
    }

    //ground
    for (int m = 0; m < (_square_size * _square_size); ++m)
    {
        _ground.lab[m]->setPixmap(pix_ground);
        _ground.lab[m]->show();
    }

    //wall
    for (int m = 0; m < ((_square_size - 1) * 4); ++m)
    {
        _wall.lab[m]->setPixmap(pix_wall);
        _wall.lab[m]->show();
    }
}
