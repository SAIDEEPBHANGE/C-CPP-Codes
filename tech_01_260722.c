//Wap to input five number from the user and calculate there sum
#include<stdio.h>
int main()
{
    int a[5];
    int sum=0,i;
    for(i=0; i<5; i++) {
        printf("\nsubject %d:",i+1);
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    printf("sum of all subject is %d",sum);
    return 0;
}
