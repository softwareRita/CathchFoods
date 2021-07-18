#ifndef FOOD_H
#define FOOD_H
#include <QPixmap>

class Food
{
public:
    Food();
    void updatePosition();
public:

    //硬币资源对象
    QPixmap b_food;
    //位置
    int b_X;
    int b_Y;
    //硬币的矩形边框（碰撞检测）
    QRect b_Rect;
    //状态
    bool b_Free;
    //速度
    int b_Speed;



};

#endif // FOOD_H
