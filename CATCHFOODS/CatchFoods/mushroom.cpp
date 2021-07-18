#include "mushroom.h"
#include "config.h"

Mushroom::Mushroom()
{
    b_mushroom.load(MUSHROOM_PATH);
        //级别
        level=1;
        //毒蘑菇位置
        b_X = 0;
        b_Y = 0;
        //毒蘑菇状态
        b_Free = true;
        //毒蘑菇速度
        b_Speed = MUSHROOM_SPEED;
        //毒蘑菇矩形
        b_Rect.setWidth(b_mushroom.width());
        b_Rect.setHeight(b_mushroom.height());
        b_Rect.moveTo(b_X,b_Y);

}
void Mushroom::updatePosition()
{
    //空闲状态，不计算坐标
        if(b_Free)
        {
        return;
        }
        b_Y += b_Speed;
        b_Rect.moveTo(b_X,b_Y);
        if(b_Y >= GAME_HEIGHT)
        {
        b_Free = true;
        }
}
