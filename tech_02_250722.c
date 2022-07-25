//WAP TO I\P A NO OF DISPLAY FOLLOWING
#include<stdio.h>
int main()
{
    int n;
    printf("enter number:");
    scanf("%d",&n);
    if(n>=0 && n<= 9)
    	printf("small");
    else if(n>=10 && n<=99)
    	printf("large");
    else if(n>=100 && n<=999)
    	printf("very large");
    else
    	printf("something wrong!");
    return 0;
}
