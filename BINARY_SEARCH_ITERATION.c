#include<stdio.h>
int main(){
	int a[100];
	int n,x,i = 0;
	printf("ENTER SIZE OF ARRAY ::");
	scanf("%d",&n);
	printf("ENTER ELEMENTS OF ARRAY ::\n");
	for(i=0;i<n;i++){
		printf("index of array %d ::",i+1);
		scanf("%d",&a[i]);
	}
	checksort(a,n);
	printf("\nENTER ELEMENT TO FIND IN ARRAY ::");
	scanf("%d",&x);
	int result = binarysearch(a,x,0,n-1);
	if(result >= -1)
		printf("%d is found at index %d\n",x,result+1);
	else
		printf("%d is not found",x);
	//printf("%d\t",result);
	return 0;
}
int binarysearch(int b[],int x,int low,int high){
	while(low<=high){
		int mid = (low+high)/2;
		//printf("array::%d\t",b[mid]);
		if(b[mid] == x)
			return mid;
		if(b[mid] >= x)
			high = mid -1;
		else
			low = mid + 1;
		//printf("mid ::%d\t",mid);
	}
	return -2;
}
int checksort(int c[],int n){
	int temp,i,j;
	for(i=0;i<n;i++)
		for(j=0;j<i;j++)
			if(c[i]<c[j])
			{
				temp = c[i];
				c[i]=c[j];
				c[j]=temp;
			}
	printf("array is sorted now ::");
	for(i=0;i<n;i++)
		printf("\n%d :: %d",i+1,c[i]);
}
