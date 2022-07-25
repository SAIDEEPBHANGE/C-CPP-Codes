// WAP TO I\P N DISPLAY FIBONACCI SERIES AND DO WHILE TRY
#include<stdio.h>
int main()
{
    float x,s1=0.0,s2=1.0,s3;
    int i=1;
    printf("enter range of Fibonacci series:");
    scanf("%f",&x);
    do{
    	printf("%.0f, ",s1);
    	s3= s1+s2;
    	s1=s2;
    	s2=s3;
    	i++;
    }while(i<=x);
    return 0;
}
