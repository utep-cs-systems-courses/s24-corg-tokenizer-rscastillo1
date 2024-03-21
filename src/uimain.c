#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"
#define MAXLEN 101

int main()
{
  char input[MAXLEN];
  char choice;
  char **tokens;//stores tokens. Freed after adding to history
  
  int count = 0;//token count

  List* history = init_history();

  printf("Welcome to tokenizer!\n");

  //loop will serve as the main program
  //takes in input, tokenizes
 
 beginning://used as loop, and for displaying history
  //will be referred to as loop for rest of the program
  //to make a programmer mad
  printf("Type t for tokenizer. Type h for history. Type x to exit");
  printf("\n>>\t");
  scanf(" %c", &choice);
  
  if(choice == 't'){
    getchar();
  stringEnter:
    printf("Please enter a string\n>>");
    fgets(input, MAXLEN, stdin);
    input[MAXLEN-1] = '\0';
    
    if(input[0] == '\n')
      {
	printf("Empty input");
	goto stringEnter;
      }
    
    tokens = tokenize(input);
    if(tokens == NULL)
      {
	printf("Tokenization failed. Returning to menu");
	goto beginning;
      }
    else
      {
	//print tokens 
	printf("Tokenz:\n");
	print_tokens(tokens);
	//frees tokens
	free_tokens(tokens);
	//adds input to history
	add_history(history, input);
	goto beginning;
    }
  }
  else if(choice == 'h')//prints history
    {
      print_history(history);
      printf("history:\n");
      goto beginning;
    }
  else if(choice != 'x')//exit
    {
      printf("Invalid choice");
      goto beginning;
    }
 
  else{ //frees history, ends program
    printf("mmmmm yummy tokens nomnomnomnom");
    free_history(history);
    printf("Out of tokens to nomnom\n>>Exiting tokenizer");
    return 0;
  }
}

