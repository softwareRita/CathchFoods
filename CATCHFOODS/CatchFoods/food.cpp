#include "food.h"
#include "config.h"

Food::Food()
{

    QString str = QString(FOOD_PATH).arg(rand() % (FOOD_MAX));
    b_food.load(str);

        //食物位置
        b_X = 0;
        b_Y = 0;
        //食物状态
        b_Free = true;
        //食物速度
        b_Speed = FOOD_SPEED;
        //食物矩形
        b_Rect.setWidth(b_food.width());
        b_Rect.setHeight(b_food.height());
        b_Rect.moveTo(b_X,b_Y);

}
void Food::updatePosition()
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

