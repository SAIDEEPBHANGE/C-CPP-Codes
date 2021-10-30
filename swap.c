#include <stdio.h>

int main() 

{
    
int a,b;
    
printf("ENTER NUMBER::\nA=");
    
scanf("%d",&a);
    
printf("B=");
    
scanf("%d",&b);
    
printf("before swapping::\n");
    
printf("A::%d,B::%d",a,b);
    
a=a+b;
    
b=a-b;
    
a=a-b;
    
printf("\nafter swapping::\n");
    
printf("A::%d,B::%d",a,b);
    
return 0;

}