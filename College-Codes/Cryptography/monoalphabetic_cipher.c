#include <stdio.h>
#include <conio.h>
char alpha[26][2] = {{'a', 'f'}, {'b', 'a'}, {'c', 'g'}, {'d', 'u'}, {'e', 'n'}, {'f', 'i'}, {'g', 'j'}, {'h', 'k'}, {'i', 'l'}, {'j', 'm'}, {'k', 'o'}, {'l', 'p'}, {'m', 'q'}, {'n', 'r'}, {'o', 's'}, {'p', 't'}, {'q', 'v'}, {'r', 'w'}, {'s', 'x'}, {'t', 'y'}, {'u', 'z'}, {'v', 'b'}, {'w', 'c'}, {'x', 'd'}, {'y', 'e'}, {'z', 'h'}};
int i, k, j;
void encry(char *s)
{
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ')
		{
			for (j = 0; j < 26; j++)
			{
				if (alpha[j][0] == s[i])
				{
					s[i] = alpha[j][1];
					break;
				}
			}
		}
	}
}
void dencry(char *s)
{
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] != ' ')
		{
			for (j = 0; j < 26; j++)
			{
				if (alpha[j][1] == s[i])
				{
					s[i] = alpha[j][0];
					break;
				}
			}
		}
	}
}
void main()
{
	char s[200];
	clrscr();
	printf("Enter the string: ");
	gets(s);
	encry(s);
	printf("encryption of String: ");
	puts(s);
	dencry(s);
	printf("decryption of String: ");
	puts(s);
	getch();
}
