#include<stdio.h>
int main(){
	static int i=0;
	i++;
	printf("%d main recursion.\n",i);
	if(i<=10)
		main();
	printf("%d main recursion.\n",i);
	return 0;
}
