#include <stdio.h>
int n, low = 0, mid, high, i = 0, j = 0, found = 0, temp, a[100], ser;
void main()
{
    printf("how many array elements you want ::");
    scanf("%d", &n);
    while (i < n)
    {
        printf("a[%d]::", i + 1);
        scanf("%d", &a[i]);
        i++;
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    i = 0;
    while (i < n)
    {
        printf("%d,", a[i]);
        i++;
    }
    high = n - 1;
    mid = (low + high) / 2;
    printf("\nwhich number want to search form array elements you want ::");
    scanf("%d", &ser);
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] < ser)
        {
            high = mid - 1;
        }
        else if (a[mid] > ser)
        {
            low = mid + 1;
        }
        else if (a[mid] == ser)
        {
            printf("%d number is found in array at location %d", ser, mid);
            found++;
        }
    }
    if (found == 0)
    {
        printf("%d number is not found in array", ser);
    }
}