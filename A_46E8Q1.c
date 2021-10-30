#include<stdio.h>
#includse<conio.h>
int i=0,found=0,n,a[100],ser;
void main()
{
printf("how many array elements you want ::");
scanf("%d",&n);
while(i<n)
{
printf("a[%d]::",i+1);
scanf("%d",&a[i]);
i++;
}
printf("\nwhich number want to search form array elements you want ::");
scanf("%d",&ser);
i=0;
while(i<n)
{
if(ser==a[i])
{
printf("%d number is found in array at loaction %d",ser,i);
found=1;
}
i++;
}
if(!found)
{
printf("%d number is not found in array",ser);
}
}
