#include<stdio.h>
#include<math.h>
int main()
{
	int num,bin = 0,i = 0;
	printf("ENTER THE NUMBER:");
	scanf("%d",&num);
	if(num > 0){
		while(num > 0){
			bin += ((pow(10,i)) * (num % 2));
			i++;
			num /=2;
		}
		printf("binary of given number (%d)2",bin);		
	}
	else
		printf("enter valid number");
	return 0;
}
