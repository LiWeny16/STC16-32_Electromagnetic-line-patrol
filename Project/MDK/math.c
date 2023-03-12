//该文件用于编写数学运算的函数
#include "math.h"
float sqrt(float a)
{
	unsigned int N, i; 
    unsigned long tap, ttp;   // 结果、循环计数 
    if (a ==0)              // 被开方数，开方结果也为0 
        return 0;
   N = 0;
   tap = (a >> 30);          //获取最高位：B[a-1] 
    a <<= 2; 
    if (tap >1)             // 最高位为1 
    { 
        N++;                // 结果当前位为1，否则为默认的0 
        tap -= N; 
    }
   for (i=15; i>0; i--)      // 求剩余的15位 
    { 
        N <<=1;             // 左移一位
       tap <<= 2; 
        tap += (a >>30);     // 假设
       ttp = N; 
        ttp = (ttp<<1)+1;
       a <<= 2; 
        if (tap >=ttp)       // 假设成立 
        { 
            tap -=ttp; 
            N ++; 
        }
   }
 
   return N; 

}