// ################ Static Structures ################
#define N 20

// ######### Stack #########

typedef struct Stack {
  int data[N];
  int top;
} Stack;

// ######### Queues #########

typedef struct Queue {
  int data[N];
  int front, rear;
} Queue;

// ######### Graphs #########

typedef struct {
  int V;
  int E;
  int **Adj;
} Graph;

// ######### Trees #########
typedef struct tnode {
  int root;
  int left, right;
} tnode;

typedef struct {
  tnode data[N];
  int root_index;
} Btree;
