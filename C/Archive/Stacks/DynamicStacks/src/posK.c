#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  struct cell *next;
} cell;

typedef cell *stack;

void push(stack *stack, int value) {
  cell *newCell = malloc(sizeof(cell));
  if (!newCell)
    return;
  newCell->data = value;
  newCell->next = *stack;
  *stack = newCell;
}

void insertNth(stack *myStack) {
  int pos;
  printf("Please enter the pos of the value you want to insert: ");
  scanf("%d", &pos);

  int value;
  printf("Please enter the value of cell : ");
  scanf("%d", &value);

  cell *newCell = malloc(sizeof(cell));
  if (!newCell)
    return;
  newCell->data = value;
  cell *current = *myStack;
  int currPos = 0;
  while (currPos < pos && current->next) {
    currPos++;
    current = current->next;
  }
  cell *temp;
  temp = current->next;
  current->next = newCell;
  newCell->next = temp;
}

void printStack(stack stack) {
  int n = 0;
  while (stack) {
    printf("the value of cell %d = %d \n", n, stack->data);
    stack = stack->next;
    n++;
  }
}

stack createStack() {
  stack head = NULL;
  int n;
  printf("Please enter the number of cells in the stack: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    int value;
    printf("Please enter the value of cell %d : ", i);
    scanf("%d", &value);
    push(&head, value);
  }
  return head;
}

int main() {
  stack myStack = createStack();
  insertNth(&myStack);
  printStack(myStack);
}
