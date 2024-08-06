#include<stdio.h>
#include<math.h>
#define pi 3.14
void main()
{
double Vs=400 ,Vm=sqrt(2)*Vs,R=10,theta=30;
double Vo=(3*Vm*cos((theta*pi)/(180)))/pi;
double Io=Vo/R;
double Ps=(Vo*Vo)/R;
printf("The values power deliver to the load po=%f  W",Ps);
}