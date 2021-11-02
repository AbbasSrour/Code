#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  struct cell *next;
} cell;

void push(cell **href, int value) {
  cell *newCell = (cell *)malloc(sizeof(cell));
  if (!newCell)
    return;
  newCell->next = *href;
  *href = newCell;
}

cell *nth(cell *href, int n) {
  cell *current = href;
  if (current) {
    int i = 0;
    while (current && i <= n)
      current = current->next;
    if (i == n)
      return current;
  }
}

int main(int argc, char **argv) {
  cell *stack1 = NULL;
  push(&stack1, 1);
  push(&stack1, 1);
  push(&stack1, 2);
  push(&stack1, 1);

  int i = 0;
  while (stack1 != NULL) {
    printf("The value of element %d is %d", i, stack1->data);
    i++;
    stack1 = stack1->next;
    cell *nthCell = nth(stack1, 3);
    printf("The nth cell is %d", nthCell->data);
  }
}
