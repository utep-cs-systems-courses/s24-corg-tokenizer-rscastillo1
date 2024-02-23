#include <stdio.h>

int space_char(char c){
  if (c == ' ' || c == '\t')
    return true;
  return false; 
  
}

int non_space_char(char c){
  (c != ' ' && c != '\t') ? return true: return false;
}

char *token_start(char *str){
  
}

char *token_terminator(char *str){
  
}

int count_tokens(char *str){

}

char *copy_string(char *Instr, short len){
  
}

char **tokenize(char* str){
  
}

void print_tokens(char *tokens){
  
}

void free_tokens(char **tokens){
  
}
