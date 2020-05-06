#ifndef LEVEL_2_H
#define LEVEL_2_H

#include <QMainWindow>
#include "sokoban.h"
#include "main.h"
namespace Ui {
class level_2;
}

class level_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit level_2(QWidget *parent = nullptr);
    ~level_2();

private:
    Ui::level_2 *ui;
};

#endif // LEVEL_2_H
