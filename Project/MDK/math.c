//���ļ����ڱ�д��ѧ����ĺ���
#include "math.h"
float sqrt(float a)
{
	unsigned int N, i; 
    unsigned long tap, ttp;   // �����ѭ������ 
    if (a ==0)              // �����������������ҲΪ0 
        return 0;
   N = 0;
   tap = (a >> 30);          //��ȡ���λ��B[a-1] 
    a <<= 2; 
    if (tap >1)             // ���λΪ1 
    { 
        N++;                // �����ǰλΪ1������ΪĬ�ϵ�0 
        tap -= N; 
    }
   for (i=15; i>0; i--)      // ��ʣ���15λ 
    { 
        N <<=1;             // ����һλ
       tap <<= 2; 
        tap += (a >>30);     // ����
       ttp = N; 
        ttp = (ttp<<1)+1;
       a <<= 2; 
        if (tap >=ttp)       // ������� 
        { 
            tap -=ttp; 
            N ++; 
        }
   }
 
   return N; 

}