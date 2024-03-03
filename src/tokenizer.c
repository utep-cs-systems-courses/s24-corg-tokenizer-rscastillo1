#include <stdlib.h>
#include <stdio.h>

int space_char(char c){
  if (c == ' ' || c == '\t')
    return 1;
  return 0; 
  
}

int non_space_char(char c){
  if (c != ' ' && c != '\t')
    return 1;
  return 0;
}

char *token_start(char *str){
  while(space_char(*str)){
    str++;
  }
  if(non_space_char(*str)){
    return str;
  }
  return 0;
  
}

char *token_terminator(char *str){
  while(non_space_char(*str)){
    str++;
  }
  if(space_char(*str))
    return --str;
  return 0;
}

int count_tokens(char *str){
  int i = 0;
  t_s:
  if(token_start(str) != 0){
    goto tterminator;
  }
  return i;
  tterminator:
  if(token_terminator(str) != 0){
    i += 1;
    goto t_s;
  }
  return i;
  
}

char *copy_str(char *Instr, short len){
  
  char *scopy = malloc((len + 1) * sizeof(char)), c;
  int i;
  
  for(i = 0; i<len; i++){
    *(scopy + i) = *(Instr + i);
  }
  return scopy;
}

char **tokenize(char* str){
  
}

void print_tokens(char *tokens){
  
}

void free_tokens(char **tokens){
  
}
