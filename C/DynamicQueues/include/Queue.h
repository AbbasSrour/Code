#include "Type_Queue.h"

extern queue CreateQueue();
extern int Enqueue(queue *q, element e);
extern int Dequeue(queue *q);
extern int Front(queue q, element *e);
extern int isEmptyQueue(queue q);
