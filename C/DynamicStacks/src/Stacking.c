#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
  int data;
  struct cell *next;
} cell;
typedef cell *stack;

void push(stack *href, int value) {
  cell *newCell = (cell *)malloc(sizeof(cell));
  if (!newCell)
    return;

  newCell->data = value;
  newCell->next = *href;
  *href = newCell;
}

int main(int argc, char **argv) { return 0; }
