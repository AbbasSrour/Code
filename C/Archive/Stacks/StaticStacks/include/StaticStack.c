#include "Stack.h"

stack CreateStack() {
  stack p;
  p.top = -1;
  return p;
}

int Push(stack *p, element e) {
  if (isFullStack(*p))
    return 0;
  p->data[++p->top] = e;
  return 1;
}

int Pop(stack *p) {
  if (isEmptyStack(*p))
    return 0;
  p->top--;
  return 1;
}

int Top(stack p, element *e) {
  if (isEmptyStack(p))
    return 0;
  *e = p.data[p.top];
  return 1;
}

int isEmptyStack(stack p) {
  if (p.top == -1)
    return 1;
  else
    return 0;
}

int isFullStack(stack p) {
  if (p.top >= N - 1)
    return 1;
  return 0;
}
