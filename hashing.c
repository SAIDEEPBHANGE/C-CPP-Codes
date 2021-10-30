#include<stdio.h>
#include<conio.h>
int main()
{
    int a[100],temp,n, values[100],i,key[100],se,in,j;
	int A=0;
	printf("length of array::");
    scanf("%d",&n);
    for(i=0; i<n; i++)
    {
	printf("a[%d]::",i+1);
	scanf("%d",&temp);
	a[i]=temp%n;
	if(A==0)
	{
	for(j=0;j<i;j++)
	{
		if(a[j]==a[i])
		{
			A++;
			break;
		}
	}
	}
    key[(temp%n)+A]=(temp%n)+A;
	values[(temp%n)+A]=temp;
	}
	printf("no\tvalues\tkeys\n");
	for(i=0;i<n;i++)
    {
		printf("%d\t%d\t%d\n",i+1,values[i],key[i]);
	}
    /*printf("element to search::");
    scanf("%d",&se);
    if(values[se%n]==se)
    {
    printf("number is exist at position %d",se%n);
    }
    else
    {
    printf("number does not exist.");
    }
    printf("\ninsert the number in array::");
    scanf("%d",&in);
    for(i=0; i<n; i++)
    {
	key[in%n]=in%n;
	values[in%n]=in;
    }
    printf("no\tvalues\tkeys\n");
    for(i=0; i<n; i++)
    {
	if(values[i]!=in)
	{
	printf("\n%d\t%d\t%d\n",i+1,values[i],key[i]);
	}
	else
	{
	   printf("\n%d       %d       %d\n",i+1,values[i],key[i]);
	}
    }
    printf("collision occurs at position is %d",in%n);*/
    return 0;
}
