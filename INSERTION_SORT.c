#include <windows.h>
#include<stdio.h>
int main(){
	int a[100];
	int i = 0,n,step;
	printf("ENTER SIZE OF ARRAY ::");
	scanf("%d",&n);
	printf("ENTER ELEMENTS OF ARRAY ::\n");
	for(i=0;i<n;i++){
		printf("index of array %d ::",i+1);
		scanf("%d",&a[i]);
	}
	system("cls");
	printf("ENTERED ARRAY:: \t");
	display(a,n);
	for(step =1;step<n;step++){
		int key = a[step];
		int j = step-1;
		printf("\nstep no : %d key : %d\n",step,key);
		while(key < a[j] && j>=0){
			a[j+1] = a[j];
			j--;
			display_color(a,n,j,j+1);
		}
		a[j+1] = key;
		display_color(a,n,j,j+1);
	}
	printf("\nARRAY IN ACCENDING ORDER :: \t");
	display(a,n);
	return 0;
}
int display(int a[],int n){
	int i=0;
	for(i=0; i<n; i++)
		printf("%d\t",a[i]);
	printf("\n");
}
int display_color(int a[],int n,int i,int j){
	HANDLE h;
  	h = GetStdHandle ( STD_OUTPUT_HANDLE );
	int c;
	for(c=0;c<n;c++){
		if(c == i || c == j){
			//textcolor(RED);
			//system("color 4");
			SetConsoleTextAttribute ( h, 4 );
			printf("%d\t",a[c]);
			SetConsoleTextAttribute ( h, 15 );
			//system("color 15");
		}
		else
			printf("%d\t",a[c]);
	}
	printf("\n");
}
