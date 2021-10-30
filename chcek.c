#include <stdio.h>
#include <stdlib.h>

#define SIZE 31

int main()
{
     int array[SIZE]={0};
     int i,j;
     int startDay=0,numDays=30;
     
     printf("  S   M    T    W    TH    F    S\n");
     
     for (i=1;i<=1+ startDay*5;i++)
     printf(" ");
     
     for (i= 1; i <= numDays; i++) 
     {
               
               printf("%2d",i);
               if ((i+startDay)%7 > 0)        
                {    printf("   ");
                   system("color 4");}
                    
               else  
                    printf("\n ");
     }
     startDay = (startDay + numDays)%7;
     
     
     
            
     
     
     getchar();
     getchar();
}
