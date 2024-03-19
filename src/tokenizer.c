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
  str = (token_start(str));
  if(*str != '\0'){
    goto tterminator;
  }
  return i;
  tterminator:
  str = (token_terminator(str));
  if(*str != '\0'){
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
  *(scopy +len) = '\0';
  return scopy;
}

char **tokenize(char* str){
  char *scopy = (copy_str(str, sizeof(str)));
  char *tokens[count_tokens(str)];

  for(int i = 0; i < sizeof(tokens); i++)
    {
    scopy = token_start(scopy);
    if(*scopy == 0 || *scopy == '\0')
      continue;
    tokens[i] = scopy;
    scopy = token_terminator(scopy);
    if(*scopy == 0 || *scopy == '\0')
      continue;
  }
  return *tokens;
  
}
//strings always were character arrays

void print_tokens(char *tokens){
  int i = 0;
  while(tokens[i] != 0)
    {
      printf("%s", tokens[i]);
      i += 1;
    }
  
}

void free_tokens(char **tokens){
  int i = 0;
  while(tokens[i] != 0)
    {
      free(tokens[i]);
      i++;
  }
  free(tokens);
}
