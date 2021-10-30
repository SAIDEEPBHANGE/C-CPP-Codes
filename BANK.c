#include<stdio.h>
double amo,in,ans;
int dur,type,y,m;
int save();
int fd(double);
int main()
{
    printf("ENTER THE AMOUNT::");
    scanf("%lf",&amo);
    printf("ENTER ANNUAL INTEREST::");
    scanf("%lf",&in);
    printf("DURATION FOR AMMOUNT::");
    scanf("%d",&dur);
    printf("1)SAVING ACCOUNT\n2)FD ACCOUNT");
    printf("\nENTER ACCOUNT TYPE::");
    scanf("%d",&type);
    switch(type)
    {
    case 1:
        ans=save();
        break;
    case 2:
        ans=fd(amo);
        break;
    }
    printf("YOUR AMOUNT AFTER %d DURATION IS %.2lf",dur,ans);
}
int save()
{
    double inter=0.0,sum=0.0;
    for(y=0; y<dur; y++)
    {
        for(m=1; m<=12; m++)
        {
            if(m%3==0)
            {
                inter=sum*(in/100);
                inter=inter/4;
                sum=sum+inter;
            }
            sum=sum+amo;
        }
    }
    return sum;
}
int fd(double sum)
{
    double inter;
    for(y=0; y<dur; y++)
    {
        inter=sum*(in/100);
        sum=sum+inter;
    }
    return sum;
}