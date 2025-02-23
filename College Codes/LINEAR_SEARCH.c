#include <stdio.h>
int main()
{
	int a[100];
	int n, x;
	int i = 0, flag = 0;
	printf("ENTER SIZE OF ARRAY ::");
	scanf("%d", &n);
	printf("ENTER ELEMENTS OF ARRAY ::\n");
	for (i = 0; i < n; i++)
	{
		printf("index of array %d ::", i + 1);
		scanf("%d", &a[i]);
	}
	printf("ENTER ELEMENT TO FIND IN ARRAY ::");
	scanf("%d", &x);
	for (i = 0; i < n; i++)
	{
		if (a[i] == x)
		{
			printf("%d is found at index %d\n", x, i + 1);
			flag--;
		}
		flag++;
	}
	if (flag == n)
		printf("%d is not found", x);
	return 0;
}
