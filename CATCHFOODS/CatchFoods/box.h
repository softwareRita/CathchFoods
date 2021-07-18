#ifndef BOX_H
#define BOX_H
#include <QPixmap>
#include <QRect>


class Box
{
public:
    Box();
    void setPosition(int x, int y);

public:
   //盒子资源对象
   QPixmap b_box;

   //盒子坐标
   int b_X;
   int b_Y;

   //盒子的矩形边框
   QRect  b_Rect;
};

#endif // BOX_H
