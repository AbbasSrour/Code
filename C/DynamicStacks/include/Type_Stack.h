
typedef int element;
typedef struct cell {
  element data;
  struct cell *next;
} cell;
typedef cell *stack;
