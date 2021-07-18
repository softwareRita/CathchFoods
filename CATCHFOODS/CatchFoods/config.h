#ifndef CONFIG_H
#define CONFIG_H

/************* 游戏界面配置数据 **************/
#define GAME_WIDTH 500                //宽度
#define GAME_HEIGHT 700             //高度
#define GAME_TITLE "CatchFood v1.0"      //标题
//#define GAME_RES_PATH ":/"    //rcc文件路径
#define GAME_ICON ":/food1.png"      //图标资源
#define GAME_RATE 20        //刷新间隔，帧率 单位毫秒
#define GAME_LEVELUP_SCORE 300  //升级所需分数

/************* 背景配置数据 **************/
#define BACKGROUND_PATH ":/bg2.png"     //背景图片路径
//#define MAP_SCROLL_SPEED 2      //背景滚动速度


/************* 盒子配置数据 **************/
#define BOX_PATH ":/box.png"

/**********  食物配置数据    **********/
#define FOOD_PATH  ":/food%1.png"  //食物资源图片
#define FOOD_SPEED  5 //食物移动速度
#define FOOD_NUM   20  //食物总数量
#define FOOD_INTERVAL  60  //食物出场时间间隔
#define FOOD_MAX 10 //食物图片最大索引


 /**********  爆炸配置数据   (用不上) **********/
//#define BOMB_PATH  ":/bomb-%1.png"   //爆炸资源图片
//#define BOMB_NUM 20     //爆炸数量
//#define BOMB_MAX 7      //爆炸图片最大索引
//#define BOMB_INTERVAL 20    //爆炸切图时间间隔

/**********  毒蘑菇配置数据    **********/
#define MUSHROOM_PATH  ":/mushroom.png"  //毒蘑菇资源图片
#define MUSHROOM_SPEED  6 //毒蘑菇移动速度
#define MUSHROOM_NUM   20  //毒蘑菇总数量
#define MUSHROOM_INTERVAL 320  //毒蘑菇出场时间间隔

/*************血包配置数据**************/
#define AID_PATH  ":/aid.png"  //血包资源图片
#define AID_SPEED  4 //血包移动速度
#define AID_NUM   20  //血包总数量
#define AID_INTERVAL 200  //血包出场时间间隔


//#define SOUND_BACKGROUND ":/res/bg.wav"        //背景音效
//#define SOUND_BOMB ":/res/bomb.wav"            //爆炸音效

#endif // CONFIG_H

/*
 游戏规则：
 接到食物score+20
 接到毒蘑菇life-10000；
 接到血包life+200；

 //以上可在mainscence.cpp中collisonDetection()查找并修改

 score每增加GAME_LEVELUP_SCORE则升级
 升级赠送20000life
 并且食物、血包、毒蘑菇speed+1；
 //以上可在mainscence.cpp中AidToScene()，MushroomToScene()，FoodToScene()查找并修改

 未添加功能：游戏首页，游戏介绍，游戏结束条件等
 */
