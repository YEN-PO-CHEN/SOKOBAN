#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "sokoban.h"
#include "level_1.h"
#include "level_2.h"
#include "background.h"
FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent),
      _background(this),
      ui(new Ui::FirstWindow)
{
    ui->setupUi(this);

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(on_start_clicked()));
    connect(ui->level1Button, SIGNAL(clicked()), this, SLOT(on_level1_clicked()));
    connect(ui->level2Button, SIGNAL(clicked()), this, SLOT(on_level2_clicked()));
    connect(ui->exitButton, SIGNAL(clicked()), this, SLOT(on_exit_clicked()));
    ui->level1Button->hide();
    ui->level2Button->hide();
}

FirstWindow::~FirstWindow()
{
    delete ui;
}
void FirstWindow::on_exit_clicked(){
    this->close();
}
void FirstWindow::on_start_clicked(){
    ui->level1Button->show();
    ui->level2Button->show();
    ui->startButton->hide();


}
void FirstWindow::on_level1_clicked(){
    this->hide();
    fst_level->resize(one_pixel*(_square_size+2),one_pixel*(_square_size+2));
    fst_level->show();
    fst_level->exec();
    if(!fst_level->is_Opened)
        this->show();
    else if(fst_level->is_Opened)
        this->hide();
    else if(!tnd_level->is_Opened)
        this->show();
    else
        this->show();
}
void FirstWindow::on_level2_clicked(){
    this->hide();
    tnd_level->resize(one_pixel*(_square_size+2),one_pixel*(_square_size+2));
    tnd_level->show();
    tnd_level->exec();
    if(tnd_level->is_Opened)
        this->show();
    else
        this->hide();

}


