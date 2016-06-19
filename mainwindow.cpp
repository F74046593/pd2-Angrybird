#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow){
    //init
    ui->setupUi(this);
    ui->graphicsView->setBackgroundBrush(QPixmap(":/background").scaled(960, 540));//set background
    ui->graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//disable scrollbar (horizontal)
    ui->graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);//disable scrollbar (vertical)
    qApp->installEventFilter(this);
    //set scoreboard
    scoreboard = new QLabel(this);
    scoreboard->setStyleSheet("color:black; background-color: transparent; font: bold 25px;");
    scoreboard->setText("Score : 0");
    scoreboard->setGeometry(10, 0, 200, 60);
    scoreboard->show();
}

MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::showEvent(QShowEvent *){
    //set scene
    scene = new QGraphicsScene(0, 0, 960, 540);
    ui->graphicsView->setScene(scene);
    //set world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    //set world global size
    game_item::set_global_size(QSizeF(32, 18), size());
    //create land
    item.push_back(new land(16.0, 1.5, 32.0, 3.0, QPixmap(":/land").scaled(960, 110), world,scene));
    //create shooter
    item.push_back(new shooter(5.0, 4.5, 2.0, 2.0, QPixmap(":/shooter").scaled(50, 105), world, scene));
    ////create bird
    bbird[0] = new bird_1(5.0, 8.5, 1.0, &timer, QPixmap(":/bird_1").scaled(40, 40), world, scene);
    bbird[1] = new bird_2(3.0, 5.5, 1.0, &timer, QPixmap(":/bird_2").scaled(40, 40), world, scene);
    bbird[2] = new bird_3(2.5, 5.5, 1.0, &timer, QPixmap(":/bird_3").scaled(40, 40), world, scene);
    bbird[3] = new bird_4(2.0, 5.5, 1.0, &timer, QPixmap(":/bird_4").scaled(40, 40), world, scene);
    for(int i = 0; i < 4; ++i) item.push_back(bbird[i]);
    ////create pig
    ppig[0] = new pig(23.5, 4.5, 1.0, &timer, QPixmap(":/pig").scaled(40, 40), world, scene);
    ppig[1] = new pig(27.7, 4.5, 1.0, &timer, QPixmap(":/pig").scaled(40, 40), world, scene);
    for(int i = 0; i < 4; ++i) item.push_back(ppig[i]);
    ////create wood
    for(int i = 0; i < 2; ++i) item.push_back(new wood(22.0 + i * 3.5, 5.5, 1.0, 3.5, &timer, QPixmap(":/wood_2").scaled(20, 100), world, scene));
    item.push_back(new wood(23.9, 8.0, 4.0, 0.9, &timer, QPixmap(":/wood_1").scaled(100, 20), world, scene));
    //create exit button
    btn_exit = new QPushButton;
    btn_exit->setText("QUIT");
    btn_exit->setGeometry(850, 10, 100, 50);
    btn_exit->setStyleSheet("color:red; background-color: transparent; font: bold 20px;");
    connect(btn_exit, SIGNAL(clicked(bool)), this, SLOT(exit_game()));
    scene->addWidget(btn_exit);
    //create restart button
    btn_restart = new QPushButton;
    btn_restart->setText("RESTART");
    btn_restart->setGeometry(740, 10, 100, 50);
    btn_restart->setStyleSheet("color:blue; background-color: transparent; font: bold 20px;");
    connect(btn_restart, SIGNAL(clicked(bool)), this, SLOT(restart_game()));
    scene->addWidget(btn_restart);
    //init data
    skill_status = false;
    ready_shoot = true;
    mouse_move = false;
    kill_1 = false;
    kill_2 = false;
    score = 0;
    left_button_count = 0;
    right_button_count = 0;
    num = 0;
    start_1 = 0.0;
    step_1 = 0.0;
    end_1 = 0.0;
    start_2 = 0.0;
    step_2 = 0.0;
    end_2 = 0.0;
    //Timer
    connect(&timer,SIGNAL(timeout()),this,SLOT(tick()));
    connect(this,SIGNAL(quit_game()),this,SLOT(QUITSLOT()));
    timer.start(100/6);
}

bool MainWindow::eventFilter(QObject *, QEvent *event){
    if(event->type() == QEvent::MouseButtonPress)
    {//mouse button press
        QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
        if (mouse_event->button() == Qt::LeftButton)
        {
            left_button_count++;
            if (left_button_count >= 5)
            {
                left_button_count = 0;
                if (num <= 3)
                {
                    mouse_move = true;
                    if (bbird[num]->get_position().x >= 10.0)
                    {
                        num++;
                        skill_status = false;
                        if (num <= 3)
                        {
                            delete bbird[num];
                            switch (num)
                            {
                            case 1:
                                bbird[1] = new bird_2(5.0, 8.5, 1.0, &timer, QPixmap(":/bird_2").scaled(40, 40), world, scene);
                                break;
                            case 2:
                                bbird[2] = new bird_3(5.0, 7.5, 1.0, &timer, QPixmap(":/bird_3").scaled(40, 40), world, scene);
                                break;
                            case 3:
                                bbird[3] = new bird_4(5.0, 8.5, 1.0, &timer, QPixmap(":/bird_4").scaled(40, 40), world, scene);
                                break;
                            }
                        }
                    }
                    else {
                        start_1 = QCursor::pos().x();
                        step_1 = QCursor::pos().x();
                        start_2 = QCursor::pos().y();
                        step_2 = QCursor::pos().y();
                    }
                }
            }
        }
        else if (mouse_event->button() == Qt::RightButton)
        {
            if (num <= 3)
            {
                if (skill_status == false)
                {
                    bbird[num]->skill();
                    if (num == 1) ready_shoot = true;
                    skill_status = true;
                }
            }
        }
    }
    else if(event->type() == QEvent::MouseButtonRelease)
    {//mouse button release
        QMouseEvent *mouse_event = static_cast<QMouseEvent*>(event);
        if (mouse_event->button() == Qt::LeftButton)
        {
            left_button_count++;
            if (left_button_count > 1)
            {
                left_button_count = 0;
                mouse_move = false;
                if (num <= 3)
                {
                    if (bbird[num]->get_position().x <= 250)
                    {
                        if (ready_shoot == true)
                        {
                            end_1 = QCursor::pos().x();
                            end_2 = QCursor::pos().y();
                            bbird[num]->set_linear_velocity(b2Vec2(abs(start_1 - end_1) / 15, abs(start_2 - end_2) / 15));
                            ready_shoot = false;
                        }
                        else
                        {
                            ready_shoot = true;
                        }
                    }
                }
            }
        }
    }
    else if(event->type() == QEvent::MouseMove)
    {//mouse move
        if (mouse_move == true)
        {
            if (num < 4)
            {
                bbird[num]->set_transform(b2Vec2(bbird[num]->get_position().x - (step_1 - QCursor::pos().x()) / 450, bbird[num]->get_position().y + (step_2 - QCursor::pos().y()) / 450), 0);
                step_1 = QCursor::pos().x();
                step_2 = QCursor::pos().y();
            }
        }
    }
    return false;
}

void MainWindow::closeEvent(QCloseEvent *)
{
    //exit-ing
    emit quit_game();
}

void MainWindow::tick()
{
    //refresh screen
    world->Step(1.0/60.0,6,2);
    scene->update();
    //kill pig
    if (kill_1 == false)
    {
        pig_1 = ppig[0]->get_linear_velocity().x + ppig[0]->get_linear_velocity().y;
        if (pig_1 > 2.0)
        {
            kill_1 = true;
            score += 100;
            delete ppig[0];
        }
    }
    if (kill_2 == false)
    {
        pig_2 = ppig[1]->get_linear_velocity().x + ppig[1]->get_linear_velocity().y;
        if (pig_2 > 2.0)
        {
            kill_2 = true;
            score += 100;
            delete ppig[1];
        }
    }
    if (kill_1 == true && kill_2 == true)
    {
        switch (num)
        {
        case 1:
            score += 500;
        case 2:
            score += 500;
        }
        num = 3;
    }
    //update scoreboard
    scoreboard->setText("Score :  " + QString::number(score));
}

void MainWindow::QUITSLOT(){
    //send output signal
    std::cout << "Quit Game Signal receive !" << std::endl ;
}

void MainWindow::deleter(){
    item.clear();
}

void MainWindow::restart_game()
{
    deleter();
    //set scene
    scene = new QGraphicsScene(0, 0, 960, 540);
    ui->graphicsView->setScene(scene);
    //set world
    world = new b2World(b2Vec2(0.0f, -9.8f));
    //set world global size
    game_item::set_global_size(QSizeF(32, 18), size());
    //create land
    item.push_back(new land(16.0, 1.5, 32.0, 3.0, QPixmap(":/land").scaled(960, 110), world,scene));
    //create shooter
    item.push_back(new shooter(5.0, 4.5, 2.0, 2.0, QPixmap(":/shooter").scaled(50, 105), world, scene));
    ////create bird
    bbird[0] = new bird_1(5.0, 8.5, 1.0, &timer, QPixmap(":/bird_1").scaled(40, 40), world, scene);
    bbird[1] = new bird_2(3.0, 6.5, 1.0, &timer, QPixmap(":/bird_2").scaled(40, 40), world, scene);
    bbird[2] = new bird_3(2.0, 6.5, 1.0, &timer, QPixmap(":/bird_3").scaled(40, 40), world, scene);
    bbird[3] = new bird_4(1.0, 6.5, 1.0, &timer, QPixmap(":/bird_4").scaled(40, 40), world, scene);
    for(int i = 0; i < 4; ++i) item.push_back(bbird[i]);
    ////create pig
    ppig[0] = new pig(23.7, 4.5, 1.0, &timer, QPixmap(":/pig").scaled(40, 40), world, scene);
    ppig[1] = new pig(27.7, 4.5, 1.0, &timer, QPixmap(":/pig").scaled(40, 40), world, scene);
    for(int i = 0; i < 4; ++i) item.push_back(ppig[i]);
    ////create wood
    for(int i = 0; i < 2; ++i) item.push_back(new wood(22.0 + i * 3.5, 5.5, 1.0, 3.5, &timer, QPixmap(":/wood_2").scaled(20, 100), world, scene));
    item.push_back(new wood(23.9, 8.0, 4.0, 0.9, &timer, QPixmap(":/wood_1").scaled(100, 20), world, scene));
    //create exit button
    btn_exit = new QPushButton;
    btn_exit->setText("EXIT");
    btn_exit->setGeometry(850, 10, 100, 50);
    btn_exit->setStyleSheet("color:red; background-color: transparent; font: bold 20px;");
    connect(btn_exit, SIGNAL(clicked(bool)), this, SLOT(exit_game()));
    scene->addWidget(btn_exit);
    //create restart button
    btn_restart = new QPushButton;
    btn_restart->setText("RESTART");
    btn_restart->setGeometry(740, 10, 100, 50);
    btn_restart->setStyleSheet("color:blue; background-color: transparent; font: bold 20px;");
    connect(btn_restart, SIGNAL(clicked(bool)), this, SLOT(restart_game()));
    scene->addWidget(btn_restart);
    //init data
    skill_status = false;
    ready_shoot = true;
    mouse_move = false;
    kill_1 = false;
    kill_2 = false;
    score = 0;
    left_button_count = 0;
    right_button_count = 0;
    num = 0;
    start_1 = 0.0;
    step_1 = 0.0;
    end_1 = 0.0;
    start_2 = 0.0;
    step_2 = 0.0;
    end_2 = 0.0;
}

void MainWindow::exit_game()
{
    close();
}
