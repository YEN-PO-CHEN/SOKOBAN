#include "level_2.h"
#include "ui_level_2.h"
#include "sokoban.h"

level_2::level_2(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::level_2)
{
    ui->setupUi(this);
}

level_2::~level_2()
{
    delete ui;
}
