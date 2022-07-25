//WAP TO I\P TO THE CHAR AND DISPLAY WHETHER IT VOWEL OR NOT
#include<stdio.h>
int main()
{
    char ch;
    int ASCII;
    printf("enter character:");
    scanf("%c",&ch);
    ASCII = ch-32;
    switch(ASCII) {
    case 'A':
        printf("it is A vowel");
        break;
    case 'E':
        printf("it is E vowel");
        break;
    case 'I':
        printf("it is I vowel");
        break;
    case 'O':
        printf("it is O vowel");
        break;
    case 'U':
        printf("it is U vowel");
        break;
    default:
        printf("it is consonant");
    }
    return 0;
}
