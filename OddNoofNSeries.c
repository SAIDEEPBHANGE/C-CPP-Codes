// WAP TO I\P N DISPLAY ALL ODD NUMBER FROM 1 TO N USING ++ MOD OPERATOR
#include <stdio.h>
int main()
{
    int n, i;
    printf("enter number:");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)
        (i % 2 != 0) ? printf("%d", i) : printf("\n");
    return 0;
}