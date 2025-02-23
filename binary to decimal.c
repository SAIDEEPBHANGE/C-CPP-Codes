#include <stdio.h>
#include <math.h>
int main()
{
	int bin, sum = 0, i = 0;
	printf("ENTER THE BINARY::");
	scanf("%d", &bin);
	if (bin > 0)
	{
		while (bin > 0)
		{
			if ((bin % 10) <= 1)
			{
				sum += ((pow(2, i)) * (bin % 10));
				bin /= 10;
				i++;
			}
			else
				exit(0);
		}
		printf("decimal of given number (%d)10", sum);
	}
	else
		printf("invalid binary!");
	return 0;
}
