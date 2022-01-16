#include "Stack.h"
#include <stdio.h>
#include <stdlib.h>

stack CreateStack() { return NULL; }

int Push(stack *p, element e) {
  stack temp;
  temp = (stack)malloc(sizeof(struct cell));
  if (!temp)
    return 0;
  temp->data = e;
  temp->next = *p;
  *p = temp;
  return 1;
}

int Pop(stack *p) {
  stack temp;
  if (isEmptyStack(*p))
    return 0;
  temp = *p;
  *p = (*p)->next;
  free(temp);
  return 1;
}

int Top(stack p, element *e) {
  if (isEmptyStack(p))
    return 0;
  *e = p->data;
  return 1;
}

int isEmptyStack(stack p) {
  if (p == NULL)
    return 1;
  else
    return 0;
}
