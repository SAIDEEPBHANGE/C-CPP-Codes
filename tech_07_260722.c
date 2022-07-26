//Wap a program three arrays input element of a and b store adition of a and b into c
#include<stdio.h>
int main()
{
    int a[5],b[5],c[5],i;
    for(i=0; i<5; i++) {
        printf("a of %d : ",i+1);
        scanf("%d",&a[i]);
        printf("b of %d : ",i+1);
        scanf("%d",&b[i]);
        c[i]=a[i]+b[i];
    }
    printf("\nc array is: ");
    for(i=0; i<5; i++)
        printf("%d ",c[i]);
    return 0;
}
