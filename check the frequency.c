#include<stdio.h>

void main()

{

char name[100];

char alphabet;

int i=0, count=0;

printf("enter the name=");

gets(name);

printf("enter the alpabet=");

scanf("%c",&alphabet);

while (name[i]!='\0')

{

if (name[i]==alphabet)

{

count++;

}

i++;

}

printf("frequency of given %c=%d",alphabet, count);

return 0;

}