// Wap to input element of 3*3 matrix and calculate submission of diganal element of matrix
#include <stdio.h>
int main()
{
    int a[3][3], i, j, sum = 0;
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("\na of %d and %d : ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", a[i][j]);
            if (i == j)
                sum += a[i][j];
            if ((i + j) == 2)
                sum += a[i][j];
        }
        printf("\n");
    }
    sum -= a[1][1];
    printf("digonal matrix sum is %d\n", sum);
    return 0;
}
