//WAP TO I\P A NO OF DISPLAY WHETHER POSITIVE, NEGATIVE, ZERO
#include<stdio.h>
int main()
{
    int n;
    printf("enter number:");
    scanf("%d",&n);
    if(n==0)
        printf("zero");
    else if(n>=1)
        printf("+ve");
    else if(n<0)
        printf("-ve");
    else
        printf("something wrong!");
    return 0;
}
