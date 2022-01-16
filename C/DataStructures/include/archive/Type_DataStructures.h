// ################ Data Structures ################
#include <stdio.h>
#include <stdlib.h>
#define N 20

// ######### Linked List #########

// Singly
typedef struct node {
  int data;
  struct node *next;
} node;

// ######### Stack #########

// Dynamic Stack
typedef node *Stack;

// Static Stack
typedef struct sStack {
  int data[N];
  int top;
} sStack;

// ######### Queues #########

// Dynamic Queues
typedef struct Queue {
  struct node *front, *rear;
} Queue;

// Static Queues
typedef struct sQueue {
  int data[N];
  int front, rear;
} sQueue;

// ######### Graphs #########

// Adjacncy List
typedef struct {
  int V;
  int E;
  node **Adj;
} Graph;

// Adjacncy Matrix
typedef struct {
  int V;
  int E;
  int **Adj;
} mGraph;

// ######### Trees #########

// Dynamic
typedef struct tnode {
  int data;
  struct tnode *left, *right;
} tnode;

typedef tnode *Btree;

// Static

// ######### Trees #########
typedef struct stnode {
  int root;
  int left, right;
} stnode;

typedef struct {
  tnode data[N];
  int root_index;
} sBtree;
