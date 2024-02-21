#include <stdio.h>

int main()
{
  puts("Welcome!");

  fputs("Please enter a sentence\n>>", stdout);
  fflush(stdout);
  char c[50];
  fgets(c, sizeof(c), stdin);
  printf("Sentence: ");
  puts(c);
  
}
