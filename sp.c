#include <stdio.h>
#include <stdlib.h>
struct student{
    float marks;
    int rollno;
    char name[30],add[100];
};
int main() 
{
    struct student *ptr;
    int i, n;
    printf("Enter the number of student::");
    scanf("%d", &n);

    // Memory allocation for noOfRecords structures
    ptr = (struct student *)malloc(n * sizeof(struct student));
    for (i = 0; i < n; ++i)
	{
        printf("enter information of %d student::( name , add , roll no , marks)\n",i+1);
        scanf("%s %s %d %f", (ptr + i)->name,(ptr+i)->add, &(ptr + i)->rollno,&(ptr + i)->marks);
    }

    printf("Displaying Information:\n");
    printf("no\tname\taddress\troll no\tmarks\n");
    for (i = 0; i < n; ++i)
        printf("%d)\t%s\t%s\t%d\t%.2f\n", i+1,(ptr + i)->name,(ptr+i)->add,(ptr + i)->rollno,(ptr + i)->marks);

    return 0;
}
