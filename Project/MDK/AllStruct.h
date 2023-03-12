#ifndef __ALLSTRUCT_H_
#define __ALLSTRUCT_H_
typedef enum
{
  Need_judge,
  No_road,      //���س���ܵ����޷�У����ͣ��
  Out_of_way,   //�Ѿ�����ܵ�
  Lose_left,    //����
  Lose_right,
  Cross,        //ʮ�ֽ���
  Straight,//ֱ��
  Curve, //���
  LeftRing,//��Բ��
  RightRing,//����Բ��
  LeftOutRing,//����Բ��
  RightOutRing,//��Բ��
  Three_L,
//  Three_f_cu,
  Three_R,
//  Three_s_cu,
  Finish,//����־
  OutGarage,//�����־
  InGarage,
  Stoped

 //Ϊ�˳��򷽱����õģ���ʾ��Ҫ����һ�����ж�
}Flag;

typedef struct 
{

    unsigned long duty_duo;
    unsigned long duty_dian;

    short L1_real; //��45
    short L2_real; //���
    short L3_real; //����
    short L4_real; //����
    short L5_real; //�Һ�
    short L6_real; //��45

    unsigned short L1_max;//��⵽�����ֵ
    unsigned short L2_max;
    unsigned short L3_max;
    unsigned short L4_max;
    unsigned short L5_max;
    unsigned short L6_max;

    float L1_once;//һ�ι�һ����
    float L2_once;
    float L3_once;
    float L4_once;
    float L5_once;
    float L6_once;
    float L2_once_b;
    float L5_once_b;

    float L1_twice; //���ι�һ����
    float L2_twice;
    float L3_twice;
    float L4_twice;
    float L5_twice;
    float L6_twice;

} DG_state;

typedef struct
{
    unsigned short duty_duo_mid ;//
    unsigned short duty_duo_max ;//�˴���д�������PWM��ռ�ձ�ֵ���ѻ��㣩;//(�˴���д�����ת����)
    unsigned short duty_duo_min ;//�˴���д�����С��PWM��ռ�ձ�ֵ���ѻ��㣩;//(�˴���д�����ת����)
    uint8 duo_dead;

} Steer;

typedef struct
{
        short Outgar_speed_bas;//  ��׼�ٶȣ��������
        short Outgar_speed_ai;//    Ŀ���ٶȣ����������صģ���������ӳ���ٶ����һ��

        short Strai_speed_bas;//ֱ��
        short Strai_speed_ai;

        short Cur_speed_bas;//���
        short Cur_speed_ai;

        short Cross_speed_bas;//ʮ��
        short Cross_speed_ai;

        short Rampin_speed_bas;//���µ�
        short Rampin_speed_ai;

        short Ramp_speed_bas;//�µ�
        short Ramp_speed_ai;

        short Ring_speed_bas;//Բ���ڲ�
        short Ring_speed_ai;

        short Ringin_speed_bas;//��Բ��
        short Ringin_speed_ai;

        short Ringout_speed_bas;//��Բ��
        short Ringout_speed_ai;

        short Three_speed_bas;//����
        short Three_speed_ai;

        short Threein_speed_bas;//800;//������
        short Threein_speed_ai;//50;


} Speed;
#endif