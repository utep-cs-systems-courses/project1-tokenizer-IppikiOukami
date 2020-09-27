#include <stdio.h>
#include <stdlib.h>
#include "history.h"


// Initialize List with empty root
List *init_history()
{
  List *history = malloc(sizeof(List));
  history->root = NULL;
  return history;
}

// Adds new node to History Linked List 
void add_history(List *list, char *str)
{
  Item *item = malloc(sizeof(Item)), *curr = list->root;
  int ctr = 0;
  
  item->str = str; 
  item->next = NULL; 

  if (list->root == NULL) { // if head is null, node becomes head
    item->id = ctr;
    list->root = item;
  } else {                 // find next == null and set node
    ctr = 1;
    while (curr->next != NULL) {
      ctr++;
      curr = curr->next;
    }                  
    curr->next = item;
    item->id = ctr;
  }
}

// Extracts element data at index value of id
char *get_history(List *list, int id)
{
  Item *curr = list->root;
  
  while (curr != NULL) {  // find elem in list with given id  
    if (curr->id == id) {
      return curr->str;  
    }
    curr = curr->next;
  }
  return NULL; // NULL if id is not found
}

// Prints linked list contents
void print_history(List *list)
{
  Item *curr = list->root; 

  printf("\n");

  while (curr != NULL) {                     // Traverse and print each element
    printf("%d: %s\n", curr->id, curr->str); // id and string in linked list
    curr = curr->next;
  }
  
  printf("\n");
}

// Deallocate history
void free_history(List *list)
{
  Item *old_root;

  while (list->root != NULL) {     // traverse list and its values
    old_root = list->root;       
    list->root = list->root->next; 
    free(old_root);                // frees the prev root
  }
  free(list);                      // deallocate memory from list
}
