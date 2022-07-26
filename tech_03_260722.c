//Wap program define two array a and b input the elements a and Store the cube of a into b
#include<stdio.h>
int main()
{
    int a[2],b[2],i;
    for(i=0; i<2; i++) {
        printf("a of %d : ",i+1);
        scanf("%d",&a[i]);
        b[i]=a[i]*a[i]*a[i];
    }
    for(i=0; i<2; i++) {
        printf("\nb of %d is %d",i+1,b[i]);
    }
    return 0;
}

