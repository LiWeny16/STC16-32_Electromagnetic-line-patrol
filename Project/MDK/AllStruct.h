#ifndef __ALLSTRUCT_H_
#define __ALLSTRUCT_H_
typedef enum
{
  Need_judge,
  No_road,      //严重冲出跑道且无法校正则停车
  Out_of_way,   //已经冲出跑道
  Lose_left,    //丢线
  Lose_right,
  Cross,        //十字交叉
  Straight,//直道
  Curve, //弯道
  LeftRing,//左圆环
  RightRing,//出右圆环
  LeftOutRing,//出左圆环
  RightOutRing,//右圆环
  Three_L,
//  Three_f_cu,
  Three_R,
//  Three_s_cu,
  Finish,//入库标志
  OutGarage,//出库标志
  InGarage,
  Stoped

 //为了程序方便设置的，表示需要更进一步的判断
}Flag;

typedef struct 
{

    unsigned long duty_duo;
    unsigned long duty_dian;

    short L1_real; //左45
    short L2_real; //左横
    short L3_real; //左竖
    short L4_real; //右竖
    short L5_real; //右横
    short L6_real; //右45

    unsigned short L1_max;//检测到的最大值
    unsigned short L2_max;
    unsigned short L3_max;
    unsigned short L4_max;
    unsigned short L5_max;
    unsigned short L6_max;

    float L1_once;//一次归一化后
    float L2_once;
    float L3_once;
    float L4_once;
    float L5_once;
    float L6_once;
    float L2_once_b;
    float L5_once_b;

    float L1_twice; //两次归一化后
    float L2_twice;
    float L3_twice;
    float L4_twice;
    float L5_twice;
    float L6_twice;

} DG_state;

typedef struct
{
    unsigned short duty_duo_mid ;//
    unsigned short duty_duo_max ;//此处填写舵机最大的PWM的占空比值（已换算）;//(此处填写舵机旋转方向)
    unsigned short duty_duo_min ;//此处填写舵机最小的PWM的占空比值（已换算）;//(此处填写舵机旋转方向)
    uint8 duo_dead;

} Steer;

typedef struct
{
        short Outgar_speed_bas;//  基准速度，给电机的
        short Outgar_speed_ai;//    目标速度，编码器返回的，这两个反映的速度最好一样

        short Strai_speed_bas;//直道
        short Strai_speed_ai;

        short Cur_speed_bas;//弯道
        short Cur_speed_ai;

        short Cross_speed_bas;//十字
        short Cross_speed_ai;

        short Rampin_speed_bas;//上坡道
        short Rampin_speed_ai;

        short Ramp_speed_bas;//坡道
        short Ramp_speed_ai;

        short Ring_speed_bas;//圆环内部
        short Ring_speed_ai;

        short Ringin_speed_bas;//进圆环
        short Ringin_speed_ai;

        short Ringout_speed_bas;//出圆环
        short Ringout_speed_ai;

        short Three_speed_bas;//三岔
        short Three_speed_ai;

        short Threein_speed_bas;//800;//进三岔
        short Threein_speed_ai;//50;


} Speed;
#endif