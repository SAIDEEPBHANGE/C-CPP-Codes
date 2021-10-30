#include<stdio.h>
#include<stdlib.h>
struct person{
int roll_no;
float mark;
char name[30],add[100]; 
}; 
int main()
{ 
struct person *ptr; 
int i, n;
printf("Enter the number of students::"); 
scanf("%d", &n); 
ptr=(struct person *)malloc(n * sizeof(struct person)); 
for(i = 0; i < n; ++i) 
{ 
printf("Enter %d student:: (name, address,roll no,marks)\n",i+1);
scanf("%s %s %d %f",(ptr+i)->name,(ptr+i)->add,&(ptr+i)->roll_no,&(ptr+i)->mark);
}
printf("Displaying Information:\n"); 
for(i = 0; i < n; ++i)
{
printf("student number %d)\nName: %s\naddress: %s\nroll: %d\nmarks: %.2f\n",i+1,(ptr+i)->name,(ptr+i)->add,(ptr+i)->roll_no,(ptr+i)->mark);
}
return 0;
}
