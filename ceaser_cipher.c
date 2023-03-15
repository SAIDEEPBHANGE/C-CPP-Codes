/*ceaser cipher algorithum*/
#include<stdio.h>
//#include<conio.h>
int main(){
	char str[200];
	int key,i=0;
	int ul;
	//	clrscr();
	printf("enter a string: ");
	gets(str);
	printf("enter a key value: ");
	scanf("%d",&key);
	for(i=0;str[i]!='\0';i++){
		if(90>=str[i] && str[i]>=65){
			ul=65;
		}
		if(122>=str[i]&& str[i]>=97){
			ul=97;
		}
		str[i]=((str[i]+key-ul)%26)+ul;
		i++;
	}
	printf("ciper string: ");
	puts(str);
	for(i=0;str[i]!='\0';i++){
		if(90>=str[i] && str[i]>=65){
			ul=65;
		}
		if(122>=str[i]&& str[i]>=97){
			ul=97;
		}
		str[i]=((str[i]-key-ul)%26)+ul;
		i++;
	}
	printf("Decrytpted string: ");
	puts(str);
	return 0;
//	getch();
}
