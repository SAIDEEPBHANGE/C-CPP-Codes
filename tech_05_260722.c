//Find the greatest among five number from array
#include<stdio.h>
int main()
{
    int a[5],i,max;
    for(i=0; i<5; i++) {
        printf("a of %d : ",i+1);
        scanf("%d",&a[i]);
    }
    max=a[i];
    for(i=1;i<5;i++){
    if(max<a[i])
    max=a[i];
    }
    
    printf("in this 5 number %d is maximum",max);
    return 0;
}
