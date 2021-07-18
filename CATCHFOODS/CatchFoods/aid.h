#ifndef AID_H
#define AID_H
#include <QPixmap>

class Aid
{
public:
    Aid();
    void updatePosition();

public:
    //血包资源对象
    QPixmap b_aid;
    //位置
    int b_X;
    int b_Y;
    //血包的矩形边框（碰撞检测）
    QRect b_Rect;
    //状态
    bool b_Free;
    //速度
    int b_Speed;
    //级别
     int level;
};

#endif // AID_H
