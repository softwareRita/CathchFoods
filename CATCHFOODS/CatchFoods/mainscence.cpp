#include "mainscence.h"
#include "ui_mainscence.h"
#include "config.h"
#include <ctime>
#include <QIcon>
#include <QPainter>
#include <QGuiApplication>


MainScence::MainScence(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScence)
{
    ui->setupUi(this);

    life=5000;

    score=0;

    //初始化场景
    initScene();

    //启动游戏
    playGame();
}

MainScence::~MainScence()
{
    delete ui;
}
void MainScence::initScene()
{
    //初始化窗口大小
        this->setFixedSize(GAME_WIDTH,GAME_HEIGHT);


        //设置窗口标题
        this->setWindowTitle(GAME_TITLE);
        //设置图标资源
        setWindowIcon(QIcon(GAME_ICON));

        //定时器设置
        b_Timer.setInterval(GAME_RATE);

        b_recorder = 0;
         life=20000;
         level=1;

        //随机数种子
        srand((unsigned int)time(NULL));

}

void MainScence::playGame()
{
    //启动背景音乐
        //QSound::play(SOUND_BACKGROUND);
        //启动定时器
        b_Timer.start();

        //监听定时器
        connect(&b_Timer,&QTimer::timeout,[=]()
        {
            updateScore();
            //食物出场
            FoodToScene();
            //毒蘑菇出场；
            MushroomToScene();
            //血包出场；
            AidToScene();

            //更新游戏中元素的坐标
            updatePosition();
            //重新绘制图片
            update();
            //碰撞检测
            collisonDetection();
         });

}

void MainScence::updatePosition()
{

        //食物坐标计算
        for(int i = 0 ; i< FOOD_NUM;i++)
        {
            //非空闲食物    更新坐标
            if(b_foods[i].b_Free == false)
            {
               b_foods[i].updatePosition();
            }
        }
        //毒蘑菇坐标计算
        for(int i = 0 ; i< MUSHROOM_NUM;i++)
        {
            //非空闲毒蘑菇    更新坐标
            if(b_mushrooms[i].b_Free == false)
            {
               b_mushrooms[i].updatePosition();
            }
        }
        //血包坐标计算
        for(int i = 0 ; i< AID_NUM;i++)
        {
            //非空闲血包    更新坐标
            if(b_aids[i].b_Free == false)
            {
               b_aids[i].updatePosition();
            }
        }

}

void MainScence::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

        //绘制地图背景
        painter.drawPixmap(0,b_Background.b_background_posY,this->width(),this->height(),b_Background.b_background);
        //painter.drawPixmap(0,m_map.m_map2_posY,m_map.m_map2);

        //绘制盒子
        painter.drawPixmap(b_Box.b_X,b_Box.b_Y,b_Box.b_box);


        //绘制食物
        for(int i = 0 ; i< FOOD_NUM;i++)
        {
            if(b_foods[i].b_Free == false)
            {
                painter.drawPixmap(b_foods[i].b_X,b_foods[i].b_Y,b_foods[i].b_food);
            }
        }
        //绘制毒蘑菇
        for(int i = 0 ; i< MUSHROOM_NUM;i++)
        {
            if(b_mushrooms[i].b_Free == false)
            {
                painter.drawPixmap(b_mushrooms[i].b_X,b_mushrooms[i].b_Y,b_mushrooms[i].b_mushroom);
            }
        }

        //绘制血包
        for(int i = 0 ; i< AID_NUM;i++)
        {
            if(b_aids[i].b_Free == false)
            {
                painter.drawPixmap(b_aids[i].b_X,b_aids[i].b_Y,b_aids[i].b_aid);
            }
        }


}

void MainScence::mouseMoveEvent(QMouseEvent *event)
{
    int x = event->x() - b_Box.b_Rect.width()*0.5; //鼠标位置    - 飞机矩形的一半
    int y = event->y() - b_Box.b_Rect.height()*0.5;

    if(x <= 0 )
    {
        x = 0;
    }
    if(x >= GAME_WIDTH - b_Box.b_Rect.width())
    {
        x = GAME_WIDTH - b_Box.b_Rect.width();
    }
    if(y <= 0)
    {
        y = 0;
    }
    if(y >= GAME_HEIGHT - b_Box.b_Rect.height())
    {
        y = GAME_HEIGHT - b_Box.b_Rect.height();
    }


    b_Box.setPosition(x,y );

}

void MainScence::FoodToScene()
{

        b_recorder++;
        if(b_recorder < FOOD_INTERVAL)
        {
            return;
        }
        b_recorder = 0;
        for(int i = 0 ; i< FOOD_NUM;i++)
        {
            if(b_foods[i].b_Free)
            {
                //食物空闲状态改为false
                b_foods[i].b_Free = false;
                //达到一定分数，升级，加速
                if(score/GAME_LEVELUP_SCORE==level){
                    level+=1;
                    life+=20000;
                    b_foods[i].b_Speed+=1;
                }

                //设置坐标
                b_foods[i].b_X = rand() % (GAME_WIDTH - b_foods[i].b_Rect.width());
                b_foods[i].b_Y = -b_foods[i].b_Rect.height();
                break;
            }
        }
}

void MainScence::MushroomToScene()
{
    b_recorder_bs++;
    if(b_recorder_bs < MUSHROOM_INTERVAL)
    {
        return;
    }
    b_recorder_bs = 0;
    for(int i = 0 ; i< MUSHROOM_NUM;i++)
    {
        if(b_mushrooms[i].b_Free)
        {
            //毒蘑菇空闲状态改为false
            b_mushrooms[i].b_Free = false;
            //如果升级，则加速
            if(level>b_mushrooms[i].level){
                b_mushrooms[i].b_Speed+=1;
                b_mushrooms[i].level=level;
            }
            //设置坐标
            b_mushrooms[i].b_X = rand() % (GAME_WIDTH - b_mushrooms[i].b_Rect.width());
            b_mushrooms[i].b_Y = -b_mushrooms[i].b_Rect.height();
            break;
        }
    }

}

void MainScence::AidToScene()
{
    b_recorder_aid++;
    if(b_recorder_aid <AID_INTERVAL)
    {
        return;
    }
    b_recorder_aid = 0;
    for(int i = 0 ; i< AID_NUM;i++)
    {
        if(b_aids[i].b_Free)
        {
            //血包空闲状态改为false
            b_aids[i].b_Free = false;
            //如果升级，则加速
            if(level>b_aids[i].level){
                b_aids[i].b_Speed+=1;
                b_aids[i].level=level;
            }
            //设置坐标
            b_aids[i].b_X = rand() % (GAME_WIDTH - b_aids[i].b_Rect.width());
            b_aids[i].b_Y = -b_aids[i].b_Rect.height();
            break;
        }
    }
}

void MainScence::collisonDetection()
{
    //食物碰撞检测
        for(int i = 0; i < FOOD_NUM; i++)
        {
            if(b_foods[i].b_Free)
            {
                //空闲食物 跳转下一次循环
                continue;
            }

            if(((b_foods[i].b_X+b_foods[i].b_Rect.width()/2)-(b_Box.b_X+b_Box.b_Rect.width()/2)<50)&&(((b_foods[i].b_X+b_foods[i].b_Rect.width()/2)-(b_Box.b_X+b_Box.b_Rect.width()/2))>-50)){
                if(b_foods[i].b_Y-b_Box.b_Y<=0&&b_foods[i].b_Y-b_Box.b_Y>=-20){

                    b_foods[i].b_Free = true;
                    this->score+=20;
                    updateScore();

                }
            }

        }
        //毒蘑菇碰撞检测
        for(int i = 0; i < MUSHROOM_NUM; i++)
        {
            if(b_mushrooms[i].b_Free)
            {
                //空闲 毒蘑菇下一次循环
                continue;
            }
            if(((b_mushrooms[i].b_X+b_mushrooms[i].b_Rect.width()/2)-(b_Box.b_X+b_Box.b_Rect.width()/2)<50)&&(((b_mushrooms[i].b_X+b_mushrooms[i].b_Rect.width()/2)-(b_Box.b_X+b_Box.b_Rect.width()/2))>-50)){
                  if(b_mushrooms[i].b_Y-b_Box.b_Y<=0&&b_mushrooms[i].b_Y-b_Box.b_Y>=-20){

                    b_mushrooms[i].b_Free = true;
                    life-=10000;

                  }
              }
        }
        //血包碰撞检测
        for(int i = 0; i < AID_NUM; i++)
        {
            if(b_aids[i].b_Free)
            {
                //空闲血包下一次循环
                continue;
            }

            if(((b_aids[i].b_X+b_aids[i].b_Rect.width()/2)-(b_Box.b_X+b_Box.b_Rect.width()/2)<50)&&(((b_aids[i].b_X+b_aids[i].b_Rect.width()/2)-(b_Box.b_X+b_Box.b_Rect.width()/2))>-50)){
                  if(b_aids[i].b_Y-b_Box.b_Y<=0&&b_aids[i].b_Y-b_Box.b_Y>=-20){

                    b_aids[i].b_Free = true;
                    life+=200;
                  }
              }
        }


}



void MainScence::updateScore()
{
    this->ui->Score->display(this->score);
    this->ui->Life->display(this->life);
    this->ui->Level->display(this->level);
}

