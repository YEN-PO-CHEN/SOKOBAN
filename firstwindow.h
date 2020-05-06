#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include "sokoban.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FirstWindow; }
QT_END_NAMESPACE

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();
    void close_first();

private:
    Ui::FirstWindow *ui;
};
#endif // FIRSTWINDOW_H
