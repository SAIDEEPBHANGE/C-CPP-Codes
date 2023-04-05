#include <stdio.h>
#include <stdlib.h>
char playfair[5][5];
char alpha[26]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
char key[26];
void repeat(){
	int i,j,k;
	for(i=0;i<strlen(key)-1;i++){
		for(j=i+1;j<strlen(key);j++){
			if(key[i]==key[j]){
				for(k=j;k<strlen(key)-1;k++){
					key[k]=key[k+1];
				}
				key[strlen(key)-1]='\0';
			}
		}
	}
}
int validkey(char ch){
	int i=0;
	for(i=0;i<strlen(key);i++){
		if(ch==key[i]){
			printf("\n%c is present\n",ch);
			return 0;
		}
	}
	printf("\n%c is  not present\n",ch);
	return 1;
}
int main()
{
	int i=0,j=0;
    printf("Enter the key:");
    gets(key);
    repeat();
    for(i=0;i<26;i++){
    	if(validkey(alpha[i])){
    		printf("\ni: %d\n",i);
    		key[strlen(key)]=alpha[i];
		}
	}
	puts(key);
	i=0;
	for(j=0;j<26;j++){
		playfair[i][j%5]=key[j];
		if(j%5==4){
			i++;
		}
		printf("\n%d %d\n",i,j%5);	
	}
    for(i=0;i<5;i++){
    	for(j=0;j<5;j++){
    		printf("%c ",playfair[i][j]);
		}
		printf("\n");
	}
    return 0;
}
