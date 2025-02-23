#include <conio.h>
#include <stdio.h>
#include <string.h>
void main()
{
  long int pre;
  char sd, ed, data[200], pad, dest[10], src[10], check;
  int len, i, cnt = 0;
  clrscr();
  printf(
      "\n I Preamble I SD I DEST I SRC I LENGTH I DATA I PAD BITS I CHECKSUM "
      "I");
  printf("\n Enter the preamble bits:: ");
  flushall();
  scanf("%ld", &pre);
  printf("\n Enter the start delimeter:: ");
  flushall();
  scanf("%c", &sd);
  printf("\n Enter destination add:: ");
  flushall();
  gets(dest);
  printf("\n Enter source add:: ");
  flushall();
  gets(src);
  printf("\n Enter the pad bit:: ");
  flushall();
  scanf("%c", &pad);
  printf("\n Enter the data:: ");
  flushall();
  gets(data);
  len = strlen(data);
  if (len < 46)
  {
    for (i = len; i < 46; i++) data[i] = pad;
  }
  data[i] = '\0';
  for (i = 0; data[i] != '\0'; i++)
  {
    if (data[i] == 'a') cnt++;
  }
  if (cnt % 2 == 0)
    check = 'E';
  else
    check = 'O';
  getch();
  clrscr();
  printf(
      "\n I Preamble I SD I DEST I SRC I LENGTH I DATA I PAD BITS I CHECKSUM "
      "I");
  printf("\n I %ld I %c I %s I %s I %d I %s I %c I", pre, sd, dest, src, len,
         data, check);
  getch();
}