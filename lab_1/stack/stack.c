#include "stack.h"

#define INITIAL_CAPACITY 4

int stack_init(Stack *stack, int initial_capacity) {
  if (initial_capacity <= 0) {
    initial_capacity = INITIAL_CAPACITY;
  }

  stack->data = (int *)malloc(initial_capacity * sizeof(int));
  if (!stack->data) {
    return -1;
  }

  stack->top = -1;
  stack->capacity = initial_capacity;
  return 0;
}

void stack_free(Stack *stack) {
  free(stack->data);
  stack->data = NULL;
  stack->top = -1;
  stack->capacity = 0;
}

int stack_is_empty(const Stack *stack) { return stack->top == -1; }

int stack_is_full(const Stack *stack) { return stack->top == stack->capacity - 1; }

int stack_push(Stack *stack, int value) {
  if (stack_is_full(stack)) {
    int new_capacity = stack->capacity + 1;
    int *new_data = (int *)realloc(stack->data, new_capacity * sizeof(int));
    if (!new_data) {
      return -1;
    }
    stack->data = new_data;
    stack->capacity = new_capacity;
  }

  stack->data[++stack->top] = value;
  return 0;
}

int stack_pop(Stack *stack, int *value) {
  if (stack_is_empty(stack)) {
    return -1;
  }
  *value = stack->data[stack->top--];
  return 0;
}

int stack_peek(const Stack *stack, int *value) {
  if (stack_is_empty(stack)) {
    return -1;
  }
  *value = stack->data[stack->top];
  return 0;
}

int stack_size(const Stack *stack) { return stack->top + 1; }
