/*********************************************************************************************************************
 * COPYRIGHT NOTICE
 * Copyright (c) 2020,逐飞科技
 * All rights reserved.
 * 技术讨论QQ群：一群：179029047(已满)  二群：244861897(已满)  三群：824575535
 *
 * 以下所有内容版权均属逐飞科技所有，未经允许不得用于商业用途，
 * 欢迎各位使用并传播本程序，修改内容时必须保留逐飞科技的版权声明。
 *
 * @file       		main
 * @company	   		成都逐飞科技有限公司
 * @author     		逐飞科技(QQ790875685)
 * @version    		查看doc内version文件 版本说明
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

#define LED P52//debug专用小灯灯
/*
 *关于内核频率的设定，可以查看board.h文件
 *在board_init中,已经将P54引脚设置为复位
 *如果需要使用P54引脚,可以在board.c文件中的board_init()函数中删除SET_P54_RESRT即可
 */


void main()
{
	DisableGlobalIRQ();		//关闭总中断
	
    //sys_clk可选值:30000000, 27000000. 24000000, 22118400, 20000000, 18432000, 12000000, 11059200, 6000000, 5529600。
    //设置系统频率，此频率需要跟STC-ISP软件中的 <输入用户程序运行的IRC频率>选项的频率一致。
    //如果频率设置不对，将会导致串口的数据不正常,PWM的工作不正常等等。
    sys_clk = 30000000;     //设置系统频率为30MHz
    
	board_init();			//初始化寄存器
	//此处编写用户代码(例如：外设初始化代码等)
/*	while(SCAN == 0) //此处写电感扫描采集按键，需修改
	{
		find_mm_adc(&dg_state);
	}
	*/
	ALL_init();   
	//总中断最后开启
	EnableGlobalIRQ();		//开启总中断
	
    while(1)
	{
        //此处编写需要循环执行的代码
		delay_ms(1000);
		//pwm_duty(PWMB_CH1_P74, 5000)
		//printf("SP_L = %d\r\n\r\n", speed_now.speed_L);
		printf("SP_R = %d\r\n", speed_now.speed_R);//当前
    printf("SP_RA = %d\r\n", speed_state.Strai_speed_R_ai);//目标
		printf("pwm = %d\r\n\r\n", PWM_Motor_R_now);
		
		/*printf("SP_ER = %d\r\n", err_motor.err_R_m);//当前误差
		printf("SP_ER2 = %d\r\n", err_motor.err_derivative_R_m);//当前误差和上次误差之差
		printf("SP_ER3 = %d\r\n\r\n", err_motor.err_derivative2_R_m);//上上次误差和上次误差之差
		*/
				
	  printf("P = %f\r\n", pid_motor.p_motor);
		printf("I = %f\r\n", pid_motor.i_motor);
		printf("D = %f\r\n\r\n", pid_motor.d_motor);
		
		printf("PWM_L = %d \r\n\r\n",PWM_Motor_L_now);
		printf("PWM_R = %d \r\n\r\n",PWM_Motor_R_now);
		printf("\r\n\r\n");
	
    }
}

