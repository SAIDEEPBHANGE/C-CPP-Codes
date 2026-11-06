#include <windows.h>
#include <stdio.h>
int main()
{
	int a[100], temp;
	int i = 0, n, step;
	printf("ENTER SIZE OF ARRAY ::");
	scanf("%d", &n);
	printf("ENTER ELEMENTS OF ARRAY ::\n");
	for (i = 0; i < n; i++)
	{
		printf("index of array %d ::", i + 1);
		scanf("%d", &a[i]);
	}
	system("cls");
	printf("ENTERED ARRAY:: \t");
	display(a, n);
	for (step = 0; step < n - 1; step++)
	{
		int min_index = step;
		printf("\nstep no : %d\n", step + 1);
		for (i = step + 1; i < n; i++)
		{
			if (a[i] < a[min_index])
				min_index = i;
			display_color(a, n, step, min_index);
		}
		temp = a[min_index];
		a[min_index] = a[step];
		a[step] = temp;
		display_color(a, n, step, min_index);
	}
	printf("\nARRAY IN ACCENDING ORDER :: \t");
	display(a, n);
	return 0;
}
int display(int a[], int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
		printf("%d\t", a[i]);
	printf("\n");
}
int display_color(int a[], int n, int i, int j)
{
	HANDLE h;
	h = GetStdHandle(STD_OUTPUT_HANDLE);
	int c;
	for (c = 0; c < n; c++)
	{
		if (c == i || c == j)
		{
			SetConsoleTextAttribute(h, 4);
			printf("%d\t", a[c]);
			SetConsoleTextAttribute(h, 15);
		}
		else
			printf("%d\t", a[c]);
	}
	printf("\n");
}
