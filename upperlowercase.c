#include<ctype.h> 

#include<stdio.h>

#include<string.h>

int main()
 
{ 
	
char ch[100],up[100];
	
int i=0;
	
printf("ENTER THE NAME::");
	
gets(ch);
	
while(ch[i]!='\0')
	
{
	
printf("%c in uppercase is represented as %c\n", ch[i], toupper(ch[i]));
	
up[i]=toupper(ch[i]);
	
i++;
    
}
    
puts(up);
    
return 0; 

} 

