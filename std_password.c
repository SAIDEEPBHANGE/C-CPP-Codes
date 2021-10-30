#include<stdio.h>
int main()
{
	int p[8];
	int len=8,uc,lc,s,n,tot=8;
	printf("NOW 8 PLACE IN PASSWORD\n");
	printf("how many uppercase in password :: ");
	scanf("%d",&uc);
	tot=tot-uc;
	printf("NOW %d LEFT IN PASSWORD",tot);
	printf("\nhow many lowercase in password :: ");
	scanf("%d",&lc);
	tot=tot-lc;
	printf("NOW %d LEFT IN PASSWORD",tot);
	printf("\nhow many symbol in password :: ");
	scanf("%d",&s);
	tot=tot-s;
	printf("NOW %d LEFT IN PASSWORD",tot);
	printf("\nhow many number in password :: ");
	scanf("%d",&n);
	tot=tot-n;
	printf("NOW %d LEFT IN PASSWORD",tot);
	if((uc+lc+s+n)!=8)
	{
		system("cls");
		main();
	}
	return 0;
}
