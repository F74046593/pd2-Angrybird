#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <Box2D/Box2D.h>
#include <QMainWindow>
#include <QGraphicsScene>
#include <QList>
#include <QCursor>
#include <QDesktopWidget>
#include <QTimer>
#include <QMouseEvent>
#include <QPushButton>
#include <QWidget>
#include <QLabel>
#include <QString>
#include <iostream>

#include "game_item.h"
#include "land.h"
#include "shooter.h"
#include "bird.h"
#include "bird_1.h"
#include "bird_2.h"
#include "bird_3.h"
#include "bird_4.h"
#include "wood.h"
#include "pig.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showEvent(QShowEvent *);
    bool eventFilter(QObject *,QEvent *event);
    void closeEvent(QCloseEvent *);
signals:
    void quit_game();
private slots:
    void tick();
    void QUITSLOT();
    void restart_game();
    void exit_game();
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    b2World *world;
    QList<game_item *> item;
    QTimer timer;
    QLabel *scoreboard;
    QPushButton *btn_exit, *btn_restart;
    bird *bbird[4];
    pig *ppig[2];
    int left_button_count, right_button_count, num, score;
    float start_1, step_1, end_1, start_2, step_2, end_2, pig_1, pig_2;
    bool skill_status, ready_shoot, mouse_move, kill_1, kill_2;
    void deleter();
};

#endif // MAINWINDOW_H
