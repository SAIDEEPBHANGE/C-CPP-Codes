#include<stdio.h>

int main()

{

long double n,i,fact=1;

printf("enter the number: ");

scanf("%Lf",&n);

for(i=1;i<=n;i++)

{

printf("\n%.Lf*%.Lf::%.Lf",fact,i,fact*i);

fact=fact*i;

}

printf("\nfullanswer:\n%.Lf",fact);

return 0;

}