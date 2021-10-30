#include<stdio.h>

int main()

{
    
int a[10][10];
    
int b[10][10];
    
int c[10][10];
    
int sum;
    
int m,n,i,j,ch,k;
    
printf("enter the rows:");
    
scanf("%d",&m);
    
printf("enter the colomn:");
    
scanf("%d",&n);
    
printf("enter the first matrix:\n");
    
for(i=1; i<=m; i++)
    
{
        
for(j=1; j<=n; j++)
        
{
            
scanf("%d",&a[i][j]);
        
}
        
printf("\n");
    
}
    
printf("enter the second matrix:\n");
    
for(i=1; i<=m; i++)
    
{
        
for(j=1; j<=n; j++)
        
{
            
scanf("%d",&b[i][j]);
        
}
        
printf("\n");
    
}
    
printf("\nif you enter 1 matrix will add or get substrate\nenter the choice:");
    
scanf("%d",&ch);
    
if(ch==1)
    
{
        
for(i=1; i<=m; i++)
        
{
            
for(j=1; j<=n; j++)
            
{
                
c[i][j]=a[i][j]+b[i][j];
                
printf("%d",c[i][j]);
            
}
            
printf("\n");
        
}
    
}
    
if(ch==2)
    
{
        
for(i=1; i<=m; i++)
        
{
            
for(j=1; j<=n; j++)
            
{
                
c[i][j]=a[i][j]-b[i][j];
                
printf("%d ",c[i][j]);
            
}
            
printf("\n");
        
}
    
}
    
if(ch==3)
    
{
        
for(i=1; i<=m; i++)
        
{
            
for(j=1; j<=n; j++)
            
{
                
sum=0;
                
for(k=1; k<=m; k++)
                
{
                    
sum=sum+(a[i][k]*b[k][j]);
                
}
                
printf("%d ",c[i][j]);
            
}
            
printf("\n");
        
}
    
}
    
return 0;

}