#include<stdio.h>
int main()
{
int n,f,b;
printf("ENTER THE NUMBER::");
scanf("%d",&n);
if(n%2==0)
{
printf("THIS IS EVEN NUMBER.");
}
else
{
printf("THIS IS ODD NUMBER.");
}
f=fact(n);
printf("\nFACTORIAL OF %d IS %d.",n,f);
b=bin(n);
printf("\nBINARY OF %d IS %d.",n,b);
}
int fact(int n)
{
static int f=1;
if(n>0)
{
f=f*n;
fact(n-1);
}
return f;
}
int bin(int n)
{
static int r,b=0;
if(n>0)
{
bin(n/2);
r=n%2;
b=r+(b*10);
}
return b;
}