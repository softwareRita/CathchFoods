#include "box.h"
#include "config.h"

Box::Box()
{
    //初始化加载飞机图片资源
       b_box.load(BOX_PATH);

       //初始化坐标
       b_X = GAME_WIDTH * 0.5 - b_box.width() * 0.5;
       b_Y = GAME_HEIGHT - b_box.height();

       //初始化矩形框
       b_Rect.setWidth(b_box.width());
       b_Rect.setHeight(b_box.height());
       b_Rect.moveTo(b_X,b_Y);

       //初始化发射子弹间隔记录
       //m_recorder = 0;
}

void Box::setPosition(int x, int y)
{
       b_X = x;
       b_Y = y;
       b_Rect.moveTo(b_X,b_Y);
}
