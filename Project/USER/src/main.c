/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,��ɿƼ�
 * All rights reserved.
 * ��������QQȺ��һȺ��179029047(����)  ��Ⱥ��244861897(����)  ��Ⱥ��824575535
 *
 * �����������ݰ�Ȩ������ɿƼ����У�δ��������������ҵ��;��
 * ��ӭ��λʹ�ò������������޸�����ʱ���뱣����ɿƼ��İ�Ȩ������
 *
 * @file       		main
 * @company	   		�ɶ���ɿƼ����޹�˾
 * @author     		��ɿƼ�(QQ790875685)
 * @version    		�鿴doc��version�ļ� �汾˵��
 * @Software 		MDK FOR C251 V5.60
 * @Target core		STC16F40K128
 * @Taobao   		https://seekfree.taobao.com/
 * @date       		2020-12-18
 ********************************************************************************************************************/

#include "headfile.h"
#include "Variable.h"
#include "ui.h"
#include "Allinit.h"
#include "encoder.h"

#define LED P52//debugר��С�Ƶ�
/*
 *�����ں�Ƶ�ʵ��趨�����Բ鿴board.h�ļ�
 *��board_init��,�Ѿ���P54��������Ϊ��λ
 *�����Ҫʹ��P54����,������board.c�ļ��е�board_init()������ɾ��SET_P54_RESRT����
 */


void main()
{
	DisableGlobalIRQ();		//�ر����ж�
	
    //sys_clk��ѡֵ:30000000, 27000000. 24000000, 22118400, 20000000, 18432000, 12000000, 11059200, 6000000, 5529600��
    //����ϵͳƵ�ʣ���Ƶ����Ҫ��STC-ISP����е� <�����û��������е�IRCƵ��>ѡ���Ƶ��һ�¡�
    //���Ƶ�����ò��ԣ����ᵼ�´��ڵ����ݲ�����,PWM�Ĺ����������ȵȡ�
    sys_clk = 30000000;     //����ϵͳƵ��Ϊ30MHz
    
	board_init();			//��ʼ���Ĵ���
	//�˴���д�û�����(���磺�����ʼ�������)
/*	while(SCAN == 0) //�˴�д���ɨ��ɼ����������޸�
	{
		find_mm_adc(&dg_state);
	}
	*/
	ALL_init();   
	//���ж������
	EnableGlobalIRQ();		//�������ж�
	
    while(1)
	{
        //�˴���д��Ҫѭ��ִ�еĴ���
		delay_ms(1000);
		//pwm_duty(PWMB_CH1_P74, 5000)
		//printf("SP_L = %d\r\n\r\n", speed_now.speed_L);
		printf("SP_R = %d\r\n", speed_now.speed_R);//��ǰ
    printf("SP_RA = %d\r\n", speed_state.Strai_speed_R_ai);//Ŀ��
		printf("pwm = %d\r\n\r\n", PWM_Motor_R_now);
		
		/*printf("SP_ER = %d\r\n", err_motor.err_R_m);//��ǰ���
		printf("SP_ER2 = %d\r\n", err_motor.err_derivative_R_m);//��ǰ�����ϴ����֮��
		printf("SP_ER3 = %d\r\n\r\n", err_motor.err_derivative2_R_m);//���ϴ������ϴ����֮��
		*/
				
	  printf("P = %f\r\n", pid_motor.p_motor);
		printf("I = %f\r\n", pid_motor.i_motor);
		printf("D = %f\r\n\r\n", pid_motor.d_motor);
		
		printf("PWM_L = %d \r\n\r\n",PWM_Motor_L_now);
		printf("PWM_R = %d \r\n\r\n",PWM_Motor_R_now);
		printf("\r\n\r\n");
	
    }
}

