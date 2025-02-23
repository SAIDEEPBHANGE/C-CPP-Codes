// Wap to input element 2 by 2 matrix calculate submission of all elements in matrix
#include <stdio.h>
int main()
{
    int a[2][2], i, j, sum = 0;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("\na of %d and %d : ", i + 1, j + 1);
            scanf("%d", &a[i][j]);
            sum += a[i][j];
        }
    }
    printf("input matrix is given below and there sum is %d\n", sum);
    /*for(i=0; i<2; i++) {
        for(j=0; j<2; j++) {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }*/
    return 0;
}
