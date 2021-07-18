#include "aid.h"
#include "config.h"


Aid::Aid()
{
    b_aid.load(AID_PATH);
        //级别
        level=1;
        //血包位置
        b_X = 0;
        b_Y = 0;
        //血包菇状态
        b_Free = true;
        //血包菇速度
        b_Speed = AID_SPEED;
        //血包矩形
        b_Rect.setWidth(b_aid.width());
        b_Rect.setHeight(b_aid.height());
        b_Rect.moveTo(b_X,b_Y);
}
void Aid::updatePosition()
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
