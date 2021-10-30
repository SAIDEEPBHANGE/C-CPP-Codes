#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
int main()
{
    int no,temp,i=0,n,p;
	printf("ENTER THE PASSWORD::");
    scanf("%d",&no);
    system("cls");
    srand(time(0));
	do{
    	temp = rand();
    	i++;
	}while(temp != no);
	printf("password is %d",temp);
	return 0;
}
