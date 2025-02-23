// Wap input 5 numbers from the user and calculate total number positive element ahe negative
#include <stdio.h>
int main()
{
    int a[5], i, p = 0, n = 0, z = 0;
    for (i = 0; i < 5; i++)
    {
        printf("a of %d : ", i + 1);
        scanf("%d", &a[i]);
        if (a[i] == 0)
            z++;
        if (a[i] > 0)
            p++;
        if (a[i] < 0)
            n++;
    }
    printf("in this 5 number %d is positive %d is negative and %d is zero", p, n, z);
    return 0;
}
