#include <stdio.h>
#include <string.h>
#include <conio.h>
void main()
{
	long int pre;
	char sd, ed, data[200], pad, dest[10], src[10], check;
	int len, i, cnt = 0, fc;
	clrscr();
	printf("\n\n ~~~ IEEE Std 802.4 Frame Format ~~~~");
	printf("\n\n ---------------------------------------------------------------------");
	printf("\n | Preamble | SD | Frame Control | Dest | Src | Data | Checksum | ED | ");
	printf("\n ----------------------------------------------------------------------");
	printf("\n\n  Enter the preamble bits : ");
	flushall();
	scanf("%ld", &pre);
	printf("\n  Enter the start delimiter : ");
	flushall();
	scanf("%c", &sd);
	printf("\n  Enter the end delimiter : ");
	flushall();
	scanf("%c", &ed);
	printf("\n  Enter the Destination Address : ");
	flushall();
	gets(dest);
	printf("\n  Enter the Source Address : ");
	flushall();
	gets(src);
	printf("\n  Press 1 for [control frame] or 0 for [data frame] : ");
	flushall();
	scanf("%d", &fc);
	if (fc == 0)
	{
		printf("\n  Enter the data : ");
		flushall();
		gets(data);
		for (i = 0; data[i] != '\n'; i++)
		{
			if (data[i] == 'a')
				cnt++;
		}
		if (cnt % 2 == 0)
			check = 'E';
		else
			check = 'O';
		printf("\n\n  Now Turn To Output Window -> ");
		getch();
		// Displaying Frame Format
		clrscr();
		printf("\n\n ~~~ IEEE Std 802.3 Frame Format ~~~~");
		printf("\n\n --------------------------------------------------------------------");
		printf("\n | Preamble | SD | Frame Control | Dest | Src | Data | Checksum | ED |");
		printf("\n --------------------------------------------------------------------");
		printf("\n\n\n --------------------------------------------------------------------");
		printf("\n | %ld | %c | %d | %s | %s | %s | %c | %c | ", pre, sd, fc, dest, src, data, check, ed);
		printf("\n --------------------------------------------------------------------");
	}
	else if (fc == 1)
	{
		printf("\n\n  Now Turn To Output Window -> ");
		getch();
		// Displaying Frame Format
		clrscr();
		printf("\n\n ~~~ IEEE Std 802.4 Frame Format ~~~~");
		printf("\n\n -------------------------------------------------");
		printf("\n | Preamble | SD | Dest | Src | Frame Control | ED | ");
		printf("\n ---------------------------------------------------");
		printf("\n\n\n -------------------------------------------------");
		printf("\n | %ld | %c | %s | %s | %c | ", pre, sd, dest, src, fc, ed);
		printf("\n -----------------------------------------------------");
	}
	getch();
}