// Wap a program input to five numbers and display the smallest
#include <stdio.h>
int main()
{
    int a[5], i, min;
    for (i = 0; i < 5; i++)
    {
        printf("a of %d : ", i + 1);
        scanf("%d", &a[i]);
    }
    min = a[i];
    for (i = 1; i < 5; i++)
    {
        if (min > a[i])
            min = a[i];
    }

    printf("in this 5 number %d is minimum", min);
    return 0;
}
