#include "firstwindow.h"
#include "ui_firstwindow.h"
#include "sokoban.h"
#include "level_1.h"
FirstWindow::FirstWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FirstWindow)
{
    ui->setupUi(this);
    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(close_first()));
}

FirstWindow::~FirstWindow()
{
    delete ui;
}
void FirstWindow::close_first(){
    this->hide();


}


