#include<stdio.h>

#include<conio.h>

#include<string.h>

int main()

{

char u[1000];

int e[9],i;

printf("LOGIN ID: ");

gets(u);

printf("\nPASSWORD:");

for(i=0;i<=9;i++)

{

e[i]=getch();
printf("*");

}

//kbhit();
/*printf("\nPRESS ENTER IF YOU COMPLETE PASSWORD");*/

if((!strcmp(e,"1919455160"))&&(!strcmp(u,"SAIDEEP BHANGE")))

{

printf("\nYOU ARE SUCCESSFUL LOGIN");

}

else

{

printf("\nENTER PASSWORD IS WRONG");

}
    
            
return 0;

}