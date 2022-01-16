
typedef int element;

typedef struct cell {
  element data;
  struct cell *next;
} cell;

typedef struct queue {
  struct cell *front, *rear;
} queue;
