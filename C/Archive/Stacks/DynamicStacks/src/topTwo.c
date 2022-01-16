#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  struct cell *next;
} cell;

typedef cell *stack;

void push(stack *myStack, int value) {
  cell *newCell = malloc(sizeof(cell));
  if (!newCell)
    return;
  newCell->data = value;
  newCell->next = *myStack;
  *myStack = newCell;
}

stack newStack() {
  stack myStack = NULL;
  int n;
  printf("Please enter the number of cells in the stack: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int value;
    printf("Please enter the value of cell %d : ", i);
    scanf("%d", &value);
    push(&myStack, value);
  }
  return myStack;
}

void printStack(stack myStack) {
  int n = 0;
  while (myStack) {
    printf("the value of cell %d = %d \n", n, myStack->data);
    n++;
    myStack = myStack->next;
  }
}

void pop(stack *myStack) {
  cell *toPop = *myStack;
  *myStack = (*myStack)->next;
  free(toPop);
}
