#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

queue CreateQueue() {
  queue q;
  q.front = q.rear = NULL;
  return q;
}

int Enqueue(queue *q, element e) {
  struct cell *newCell;
  newCell = (struct cell *)malloc(sizeof(struct cell));
  if (!newCell)
    return 0;
  newCell->data = e;
  newCell->next = NULL;
  if (q->rear == NULL)
    q->front = q->rear = newCell;
  else
    q->rear->next = newCell;
  return 1;
}

int Dequeue(queue *q) {
  cell *temp;
  if (isEmptyQueue(*q))
    return 0;
  temp = q->front;
  q->front = q->front->next;
  free(temp);
  if (q->front == NULL)
    q->rear = NULL;
  return 0;
}

int Front(queue q, element *e) {
  if (isEmptyQueue(q))
    return 0;
  *e = q.front->data;
  return 1;
}

int isEmptyQueue(queue q) {
  if (q.front == NULL)
    return 1;
  return 0;
}
