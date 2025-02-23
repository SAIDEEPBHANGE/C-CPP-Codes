#include <stdio.h>
#include <conio.h>
void main()
{
    int i, n, h = 0;
    int *a;
    clrscr();
    printf("Enter the size of array A \n");
    scanf("%d", &n);
    a = (int *)malloc(n * sizeof(int));
    printf("Enter Elements of the List \n");
    for (i = 0; i < n; i++)
    {
        printf("%d)", i + 1);
        scanf("%d", a + i);
    }
    for (i = 0; i < n; i++)
    {
        if (h < *(a + i))
        {
            h = *(a + i);
        }
    }
    printf("higher elements in array = %d\n", h);
    getch();
}