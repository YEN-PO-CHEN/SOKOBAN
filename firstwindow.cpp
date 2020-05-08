#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "sokoban.h"
#include "level_1.h"
#include "level_2.h"
#include "background.h"
FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent),
      _background(this, 0),
      ui(new Ui::FirstWindow)
{
    ui->setupUi(this);

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_start_clicked()));
    connect(ui->theme_1_Button, SIGNAL(clicked()), this, SLOT(on_theme_1_clicked()));
    connect(ui->theme_2_Button, SIGNAL(clicked()), this, SLOT(on_theme_2_clicked()));
    connect(ui->level1Button, SIGNAL(clicked()), this, SLOT(on_level1_clicked()));
    connect(ui->level2Button, SIGNAL(clicked()), this, SLOT(on_level2_clicked()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(on_exit_clicked()));
    ui->level1Button->hide();
    ui->level2Button->hide();
    ui->theme_1_Button->hide();
    ui->theme_2_Button->hide();
}

FirstWindow::~FirstWindow()
{
    delete ui;
}
void FirstWindow::on_exit_clicked()
{
    this->close();
}
void FirstWindow::on_start_clicked()
{
    _background.lab_back->hide();
    ui->theme_1_Button->show();
    ui->theme_2_Button->show();
    ui->startButton->hide();
}
void FirstWindow::on_theme_1_clicked()
{
    _background.theme = 1;
    _background.lab_back->show();
    ui->theme_1_Button->hide();
    ui->theme_2_Button->hide();
    ui->level1Button->show();
    ui->level2Button->show();
}
void FirstWindow::on_theme_2_clicked()
{
    _background.theme = 2;
    _background.lab_back->show();
    ui->theme_1_Button->hide();
    ui->theme_2_Button->hide();
    ui->level1Button->show();
    ui->level2Button->show();
}
void FirstWindow::on_level1_clicked()
{
    this->hide();
    fst_level->resize(one_pixel * (_square_size + 2), one_pixel * (_square_size + 2));

    fst_level->exec();
    tnd_level->close();

    //1.open 1.notfinish 2.close 2.notfinish 1.where am i
    if (_background._1_is_Opened == true &&
        _background._1_is_not_Finished == true &&
        _background._2_is_Opened == false &&
        _background._2_is_not_Finished == true &&
        _background.where_am_i == 1)
        this->show();
    //1.close 1.finish 2.open 2.notfinish 1.where am i 2.is not exec
    if (_background._1_is_Opened == false &&
        _background._1_is_not_Finished == false &&
        _background._2_is_Opened == true &&
        _background._2_is_not_Finished == true &&
        _background.where_am_i == 1 &&
        _background.is_exec_2 == false)
        this->hide();
    //1.close 1.finish 2.open 2.notfinish 2.where am i
    if (_background._1_is_Opened == false &&
        _background._1_is_not_Finished == false &&
        _background._2_is_Opened == true &&
        _background._2_is_not_Finished == true &&
        _background.where_am_i == 2)
        this->show();
    //1.close 1.finish 2.close 2.finish 2.where am i 2.is exec
    if (_background._1_is_Opened == false &&
        _background._1_is_not_Finished == false &&
        _background._2_is_Opened == false &&
        _background._2_is_not_Finished == false &&
        _background.where_am_i == 2 &&
        _background.is_exec_2 == true)
        this->show();
}
void FirstWindow::on_level2_clicked()
{
    this->hide();
    tnd_level->resize(one_pixel * (_square_size + 2), one_pixel * (_square_size + 2));
    tnd_level->show();
    tnd_level->exec();
    this->show();
}
