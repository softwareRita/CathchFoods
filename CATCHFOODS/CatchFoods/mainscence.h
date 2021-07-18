#ifndef MAINSCENCE_H
#define MAINSCENCE_H

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include <QMouseEvent>
#include "config.h"
#include "food.h"
#include "box.h"
#include "background.h"
#include "mushroom.h"
#include "aid.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainScence; }
QT_END_NAMESPACE

class MainScence : public QMainWindow
{
    Q_OBJECT

public:
    MainScence(QWidget *parent = nullptr);
    ~MainScence();
public:
    void initScene();

    //启动游戏，用于启动定时器对象
    void playGame();
    //更新坐标
    void updatePosition();
    //绘图事件
    void paintEvent(QPaintEvent *event);
    //鼠标移动事件
    void mouseMoveEvent(QMouseEvent *event);

    //食物出场
    void FoodToScene();

    //毒蘑菇出场
    void MushroomToScene();
    //毒蘑菇出场
    void AidToScene();

    //入盒子检测
    void collisonDetection();

    //分数
    int score;
    //级别
    int level;

    int life;




    void updateScore();

public:
    QTimer b_Timer;
    Background b_Background;

    //飞机对象
    Box b_Box;

    //食物数组
    Food b_foods[FOOD_NUM];
    //食物出场间隔记录
    int b_recorder;
    //毒蘑菇数组
    Mushroom b_mushrooms[MUSHROOM_NUM];
    //毒蘑菇出场间隔记录
    int b_recorder_bs;
    //血包数组
    Aid b_aids[AID_NUM];
    //血包出场间隔记录
    int b_recorder_aid;

private:
    Ui::MainScence *ui;
};
#endif // MAINSCENCE_H
