#include<stdio.h>
#include<stdlib.h>
int main()
{
	int num;
	char c;
	FILE *fp;
	fp=fopen("E:\\FILE1.txt","r");
	if(fp==NULL)
	{
		printf("error ! opening file ");
		exit(1);
	}
	while((c=getc(fp))!=EOF)
	{
		printf("%c",c);	
	}
	fclose(fp);
	return 0;	
} 
