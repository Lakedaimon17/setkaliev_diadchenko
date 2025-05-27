#include <assert.h>
#include <stdlib.h>

typedef struct Node Node;

typedef struct {
  Node *head;
  int size;
} LinkedList;

void list_init(LinkedList *list);
void list_add_first(LinkedList *list, int data);
void list_add_last(LinkedList *list, int data);
void list_add_at(LinkedList *list, int index, int data);
void list_remove_first(LinkedList *list);
void list_remove_last(LinkedList *list);
void list_remove_at(LinkedList *list, int index);
int list_get_at(LinkedList *list, int index);
int list_size(LinkedList *list);
void list_clear(LinkedList *list);
