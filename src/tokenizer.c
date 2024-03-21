#include <stdlib.h>
#include <stdio.h>

int space_char(char c){
  if (c == ' ' || c == '\t')
    return 1;
  return 0; 
  
}

int non_space_char(char c){

  if (c == '\0') return 0;
  
  return !space_char(c);
}

char *token_start(char *str){
  while(*str != '\0'){
    if(space_char(*str) || *str == '\0'){
      str++;
      if(*str == '\0'){
	return NULL;
      }//if
    }
    else{
      return str;
    }
  }
  return NULL;
}

char *token_terminator(char *str){
  while(*str){
    if(space_char(*str))
      return --str;
    
    str++;
  }
  return NULL;
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
  
  char *scopy = (char *)malloc((len + 1) * sizeof(char));
  int i;
  
  for(i = 0; i<len && Instr[i] != '0'; i++){
    scopy[i] = Instr[i];
  }
  scopy[len] = '\0';
  return scopy;
}

char **tokenize(char* str){
  int count = count_tokens(str);
  int token_index = 0;

  char **tokens= malloc((count+1) * sizeof(char));
  char *token_begin = token_start(str);

  
  while(token_begin != NULL){
    char *token_end = token_terminator(token_begin);
    int token_length = token_end - token_begin;
    
    tokens[token_index] = copy_str(token_begin, token_length);
    
    token_index++;
    
    token_begin = token_start(token_end);//move to start of next string
  }
  
  tokens[count] = '\0';//mark the end of the token array
  
  return tokens;
}

//strings always were character arrays

void print_tokens(char **tokens){
  
  if(tokens == NULL)
    {
    printf("Token array is null\n");
    return;
    }
  
  for(int i = 0; tokens[i] != NULL; i++)
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
