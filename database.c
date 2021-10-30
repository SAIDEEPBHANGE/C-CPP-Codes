#include <stdio.h>
#include <ctype.h>
int main()
{
	int i=0;
	char ch,s[100];
	gets(s);
	for(i=0;s[i]!='\0';i++)
	{
		ch=s[i];
		if(ch>='A' && ch<='Z')
			s[i]=tolower(ch);
		else
			s[i]=toupper(ch);
	}
	puts(s);
	return 0;
}
