#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List *init_history(){
  List *list = malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str)
{
  
  int id = 1;
  Item *new_i = malloc(sizeof(Item));
  
  new_i->id = id+1;
  new_i->str = str;
  new_i->next = NULL;
  if(list->root == NULL)
    {
    list->root = new_i;
    return;
  }
  Item *tmp = list->root;
  while(tmp->next != NULL)
    {
    tmp = tmp->next;
  }
  tmp->next = new_i;
}

char *get_history(List *list, int id){
  Item *tmp = list->root;
  while(tmp != NULL){
    if(tmp->id == id)
      return tmp->str;
    tmp = tmp->next;
  }
}

void print_history(List *list){
  Item *hcopy = list->root;
  while(list->root != NULL)
    {
      hcopy = list->root;
      list->root = list->root->next;
      free(hcopy->str);
      free(hcopy);
  }
  free(list);
}


