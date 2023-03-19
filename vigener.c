#include<stdio.h>
char vigt[26][26];
int i,j;
int main(){
	char pt[200],kt[200];
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			vigt[i][j]='a'+(j+i)%26;
		}
	}
	for(i=0;i<26;i++){
		for(j=0;j<26;j++){
			printf("%c ",vigt[i][j]);
		}
		printf("\n");
	}
	printf("Enter Plain Text: ");
	gets(pt);
	printf("Keyword: ");
	gets(kt);
	puts(pt);
	puts(kt);
	for(i=0;pt[i]!='\0';i++){
//		pt[i]=vigt[kt[i%(strlen(kt))]-'a'][pt[i]-'a'];
//		pt[i]='a'+(pt[i]-'a'+kt[i%(strlen(kt))]-'a')%26;
		pt[i]=(((pt[i]+kt[i%(strlen(kt))])%97)%26+'a');
	}
	printf("Enter cipher Text: ");
	puts(pt);
	for(i=0;pt[i]!='\0';i++){
		printf("%d\n",((pt[i]-kt[i%(strlen(kt))])%97)%26+'a');
		pt[i]=(((pt[i]-kt[i%(strlen(kt))])%97)%26+'a');
	}
	printf("Enter decrypted Text: ");
	puts(pt);
	return 0;
}
