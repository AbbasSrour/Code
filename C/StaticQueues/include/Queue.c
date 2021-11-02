#include "Queue.h"
#include <stdio.h>
#include <stdlib.h>

queue CreateQueue() {
  queue q;
  q.front = 1;
  q.rear = 0;
  return q;
}

int Enqueue(queue *q, element e) {
  if (isFullQueue(*q))
    return 0;
  q->rear = (q->rear + 1) % N;
  q->data[q->rear] = e;
  return 1;
}

int Dequeue(queue *q) {
  if (isEmptyQueue(*q))
    return 0;
  q->front = (q->front + 1) % N;
  return 1;
}

int Front(queue q, element *e) {
  if (isEmptyQueue(q))
    return 0;
  *e = q.data[q.front];
  return 1;
}

int isEmptyQueue(queue q) { return (q.front == (q.rear + 1) % N); }

int isFullQueue(queue q) { return (q.front == (q.rear + 2) % N); }
