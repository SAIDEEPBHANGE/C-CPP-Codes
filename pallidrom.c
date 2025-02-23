#include <stdio.h>
#include <string.h>
int main()
{
	int l = 0;
	char s[100];
	gets(s);
	for (int i = strlen(s); i > 0; i--)
	{
		if (s[i - 1] != s[strlen(s) - i])
			l++;
	}
	if (l > 0)
		printf("NO");
	else
		printf("YES");
	return 0;
}