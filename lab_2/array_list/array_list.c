
#include "array_list.h"

void array_list_create(array_list *list, linear_allocator *allocator) {
  if (list == NULL || allocator == NULL)
    return;
  list->allocator = allocator;
  list->size = 0;
  list->capacity = 4;
  list->data = (void **)linear_allocator_allocate(
      allocator, list->capacity * sizeof(void *));
}

void array_list_resize(array_list *list, size_t new_capacity) {
  void *new_data =
      linear_allocator_allocate(list->allocator, new_capacity * sizeof(void *));
  if (new_data == NULL)
    return;
  memcpy(new_data, list->data, list->size * sizeof(void *));
  list->data = new_data;
  list->capacity = new_capacity;
}

void array_list_add(array_list *list, void *data, size_t index) {
  if (list == NULL)
    return;
  if (index > list->size)
    return;
  if (list->size == list->capacity) {
    size_t new_capacity = list->capacity * 2;
    array_list_resize(list, new_capacity);
  }
  memmove(&list->data[index + 1], &list->data[index],
          (list->size - index) * sizeof(void *));
  list->data[index] = data;
  list->size++;
}

void *array_list_get(array_list *list, size_t index) {
  if (list == NULL)
    return NULL;
  if (index > list->size)
    return NULL;
  return list->data[index];
}

void array_list_remove(array_list *list, size_t index) {
  if (list == NULL)
    return;
  if (index > list->size)
    return;
  memmove(&list->data[index], &list->data[index + 1],
          (list->size - index - 1) * sizeof(void *));
  list->size--;
}

void array_list_free(array_list *list) {
  if (list == NULL || list->allocator == NULL)
    return;
  list->allocator = NULL;
  list->size = 0;
  list->capacity = 0;
  list->data = NULL;
}
