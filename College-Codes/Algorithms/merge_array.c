#include <stdio.h>
#include <conio.h>
void main()
{
	int a[100], b[100];
	int c[200], n1, n2;
	int i = 0, j = 0, k = 0;
	clrscr();
	printf("size of first array :: ");
	scanf("%d", &n1);
	for (i = 0; i < n1; i++)
		scanf("%d", &a[i]);
	printf("size of second array :: ");
	scanf("%d", &n2);
	for (i = 0; i < n2; i++)
		scanf("%d", &b[i]);
	i = 0;
	while (i < n1 && j < n2)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}
	while (i < n1)
		c[k++] = a[i++];
	while (j < n2)
		c[k++] = b[j++];
	for (i = 0; i < (n1 + n2); i++)
		printf("%d\t", c[i]);
	getch();
}
