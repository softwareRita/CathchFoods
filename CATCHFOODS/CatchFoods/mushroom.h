#ifndef MUSHROOM_H
#define MUSHROOM_H
#include <QPixmap>

class Mushroom
{
public:
    Mushroom();
    void updatePosition();

public:
    //毒蘑菇资源对象
    QPixmap b_mushroom;
    //位置
    int b_X;
    int b_Y;
    //毒蘑菇的矩形边框（碰撞检测）
    QRect b_Rect;
    //状态
    bool b_Free;
    //速度
    int b_Speed;
    //级别
    int level;
};

#endif // MUSHROOM_H
