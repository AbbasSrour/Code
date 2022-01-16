// ################ Data Structures ################

// ######### Linked List #########

typedef struct node {
  int data;
  struct node *next;
} node;

// ######### Stack #########

typedef node *Stack;

// ######### Queues #########

typedef struct Queue {
  struct node *front, *rear;
} Queue;

// ######### Graphs #########

typedef struct {
  int V;
  int E;
  node **Adj;
} Graph;

// ######### Trees #########
typedef struct tnode {
  int data;
  struct tnode *left, *right;
} tnode;

typedef tnode *Btree;
