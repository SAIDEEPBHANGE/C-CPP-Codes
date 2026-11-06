#include <stdio.h>
#include <math.h>
int x[100], y[100], i, n, j;
double put_x = 0.0, put_y = 0.0, t;
int k = 1;
int main()
{
    // clrscr();
    printf("ENTER NO OF VERTEX::");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        printf("POINT %d:\n", i + 1);
        scanf("%d %d", &x[i], &y[i]);
    }
    // clrscr();
    printf("\nno\tT\tX\tY\n");
    j = n - 1;
    for (t = 0.0; t <= 1.05; t = t + 0.05)
    {
        put_x = 0.0;
        put_y = 0.0;
        for (i = 0; i <= j; i++)
        {
            if (i == 0)
            {
                put_x = put_x + (pow(1 - t, j) * x[i]);
                put_y = put_y + (pow(1 - t, j) * y[i]);
            }
            else if (i == j)
            {
                put_x = put_x + pow(t, j) * x[i];
                put_y = put_y + pow(t, j) * y[i];
                break;
            }
            else
            {
                put_x = put_x + (j * pow(t, i) * pow(1 - t, j - i) * x[i]);
                put_y = put_y + (j * pow(t, i) * pow(1 - t, j - i) * y[i]);
            }
        }
        printf("%d)\t%.2lf\t%.2lf\t%.2lf\n", k++, t, put_x, put_y);
    }
    return 0;
}