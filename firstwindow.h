#ifndef FIRSTWINDOW_H
#define FIRSTWINDOW_H

#include <QMainWindow>
#include "level_1.h"
#include "level_2.h"
#include "sokoban.h"
#include "background.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
class FirstWindow;
}
QT_END_NAMESPACE

class FirstWindow : public QMainWindow
{
    Q_OBJECT

public:
    FirstWindow(QWidget *parent = nullptr);
    ~FirstWindow();
    void close_first();
    background _background;
private slots:
    void on_start_clicked();
    void on_theme_1_clicked();
    void on_theme_2_clicked();
    void on_exit_clicked();
    void on_level1_clicked();
    void on_level2_clicked();

private:
    Ui::FirstWindow *ui;
    level_1 *fst_level = new level_1;
    level_2 *tnd_level = new level_2;
    QLabel *lab_table;
};
#endif // FIRSTWINDOW_H
