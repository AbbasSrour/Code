#include "DataStructures.h"
#include <stdio.h>
#include <stdlib.h>

// ################## Singly Linked List ###################### //

// Head Push
void headPush(node **href, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return;

  newNode->data = data;

  newNode->next = *href;
  *href = newNode;
}

// Tail Push
void tailPush(node **href, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return;
  newNode->data = data;
  newNode->next = NULL;

  node *current = *href;
  if (*href == NULL) {
    *href = newNode;
    return;
  }
  while (current->next)
    current = current->next;
  current->next = newNode;
}

// Createlist A linked List Using Tail Push
node *createList() {
  node *head;

  int value, n;
  printf("enter the number of nodes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("please enter the value of node at index %d: ", i);
    scanf("%d", &value);

    tailPush(&head, value);
  }
  return head;
}

// Print List
void printList(node *head) {
  int i = 0;
  node *currentNode = head;

  while (currentNode) {
    printf("the node of index %d = %d", i, currentNode->data);
    i++;
    currentNode = currentNode->next;
  }
}

// Delete List
void deleteList(node **href) {
  node *currentNode = *href;
  node *nextNode;
  while (currentNode) {
    nextNode = currentNode->next;
    free(currentNode);
    currentNode = nextNode;
  }
}

// Get And Print the nth node data
int getNthNode(node *head, int n) {
  int i = 0;
  node *currentNode = head;
  while (currentNode) {
    if (i == n)
      return currentNode->data;
    currentNode = currentNode->next;
    i++;
  }
  return currentNode->data;
}

// Pop The Head Node
int headPop(node **href) {
  node *currentNode = *href;
  node *nextNode = currentNode->next;
  int value = currentNode->data;

  free(currentNode);
  *href = nextNode;
  return value;
}

// Get length of the list
int lenList(node *head) {
  int len = 0;
  node *current = head;
  while (current) {
    current = current->next;
    len++;
  }
  return len;
}

// Sort list
void sortList(node **href) {
  node *current = *href;
  node *head = *href;
  node *nodeA, *nodeB;
  int len = lenList(current);
  int swap_made;
  do {
    swap_made = 0;
    current = *href;
    while (current->next) {
      if (current->data > (current->next)->data) {
        nodeA = current;
        nodeB = current->next;
        swapNodes(&head, nodeA, nodeB);
        swap_made = 1;
      } else
        current = current->next;
    }
  } while (swap_made);
}

// Swap Nodes
void swapNodes(node **href, node *nodeA, node *nodeB) {
  if (*href == NULL)
    return; // Empty list
  if (nodeA == nodeB)
    return; // Can't swap with itself

  // Be sure that if either node is the first, it will be nodeA
  if (nodeB == *href) {
    node *tmp = nodeA;
    nodeA = nodeB;
    nodeB = tmp;
  }

  // Be sure that if one of the nodes points to the other, then it is nodeA
  // pointing to nodeB
  if (nodeB->next == nodeA) {
    node *tmp = nodeA;
    nodeA = nodeB;
    nodeB = tmp;
  }

  // Easy part, look for nodeA, remove it from the list and add it after nodeB
  node *prevA = NULL; // NULL means it's the head
  if (*href != nodeA) {
    prevA = *href;
    while (prevA->next != NULL && prevA->next != nodeA) {
      prevA = prevA->next;
    }
    if (prevA->next == NULL)
      return; // Can't find node A
  }

  // Unlink node A
  if (prevA == NULL) {
    *href = nodeA->next;
  } else {
    prevA->next = nodeA->next;
  }

  // Add it after node B
  nodeA->next = nodeB->next;
  nodeB->next = nodeA;

  // Look for node B, remove it from the list and add it after what was before
  // node A
  node *prevB = NULL; // NULL means it's the head
  if (*href != nodeB) {
    prevB = *href;
    while (prevB->next != NULL && prevB->next != nodeB) {
      prevB = prevB->next;
    }
    if (prevB->next == NULL)
      return; // Can't find node B
  }

  // Unlink node B
  if (prevB == NULL) {
    *href = nodeB->next;
  } else {
    prevB->next = nodeB->next;
  }
  nodeB->next = NULL;

  // Relink node B after prevA
  if (prevA == NULL) {
    nodeB->next = *href;
    *href = nodeB;
  } else {
    nodeB->next = prevA->next;
    prevA->next = nodeB;
  }
}

// Create A New Node
node *createNewNode() {
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return NULL;

  int value;
  printf("Please enter the value of the node: ");
  scanf("%d", &value);
  newNode->data = value;

  newNode->next = NULL;
  return newNode;
}

// Insert A Node In A Sorted List
void sortedInsert(node **href, node *newNode) {
  node *current = *href;

  while (current) {
    // Special case for the head
    if ((*href == NULL || (*href)->data >= newNode->data)) {
      newNode->next = *href;
      *href = newNode;
    } else {
      // Locate the node before the point of insertion
      node *current = *href;
      while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
  }
}

// Append List B to List A
void append(node **href_A, node **href_B) {
  // Case 1: List B is empty, or A&B are empty
  if (!*href_B)
    return;
  if (!*href_B && !*href_A)
    return;

  // Case 2: List A is empty
  if (!*href_A) {
    *href_A = *href_B;
    *href_B = NULL;
    return;
  }

  // Case 3: Both Lists Are not empty
  node *current = *href_A;
  while (current->next)
    current = current->next;
  current->next = *href_B;
  *href_B = NULL;
}

// ################## Dynamic Stack ###################### //
Stack createStack() { return NULL; }

int Push(Stack *p, int e) {
  Stack temp;
  temp = (Stack)malloc(sizeof(struct node));
  if (!temp)
    return 0;
  temp->data = e;
  temp->next = *p;
  *p = temp;
  return 1;
}

int isEmptyStack(Stack p) {
  if (p == NULL)
    return 1;
  else
    return 0;
}

int Pop(Stack *p) {
  Stack temp;
  if (isEmptyStack(*p))
    return 0;
  temp = *p;
  *p = (*p)->next;
  free(temp);
  return 1;
}

int Top(Stack p, int *e) {
  if (isEmptyStack(p))
    return 0;
  *e = p->data;
  return 1;
}

// ################## Static Stack ###################### //
sStack createStackStatic() {
  sStack p;
  p.top = -1;
  return p;
}

int sPush(sStack *p, int e) {
  if (isFullStackStatic(*p))
    return 0;
  p->data[++p->top] = e;
  return 1;
}

int sPop(sStack *p) {
  if (isEmptyStackStatic(*p))
    return 0;
  p->top--;
  return 1;
}

int sTop(sStack p, int *e) {
  if (isEmptyStackStatic(p))
    return 0;
  *e = p.data[p.top];
  return 1;
}

int isEmptyStackStatic(sStack p) {
  if (p.top == -1)
    return 1;
  else
    return 0;
}

int isFullStackStatic(sStack p) {
  if (p.top >= N - 1)
    return 1;
  return 0;
}

// ################## Dynamic Queue  ###################### //
Queue createQueue() {
  Queue q;
  q.front = q.rear = NULL;
  return q;
}

int enQueue(Queue *q, int e) {
  struct node *newNode;
  newNode = (struct node *)malloc(sizeof(struct node));
  if (!newNode)
    return 0;
  newNode->data = e;
  newNode->next = NULL;
  if (q->rear == NULL)
    q->front = q->rear = newNode;
  else
    q->rear->next = newNode;
  return 1;
}

int isEmptyQueue(Queue q) {
  if (q.front == NULL)
    return 1;
  return 0;
}

int deQueue(Queue *q) {
  node *temp;
  if (isEmptyQueue(*q))
    return 0;
  temp = q->front;
  q->front = q->front->next;
  free(temp);
  if (q->front == NULL)
    q->rear = NULL;
  return 0;
}

int Front(Queue q, int *e) {
  if (isEmptyQueue(q))
    return 0;
  *e = q.front->data;
  return 1;
}

// ################## Static Queue  ###################### //
sQueue createStaticQueue() {
  sQueue q;
  q.front = 1;
  q.rear = 0;
  return q;
}

int enQueueStatic(sQueue *q, int e) {
  if (isFullQueueStatic(*q))
    return 0;
  q->rear = (q->rear + 1) % N;
  q->data[q->rear] = e;
  return 1;
}

int deQueueStatic(sQueue *q) {
  if (isEmptyQueueStatic(*q))
    return 0;
  q->front = (q->front + 1) % N;
  return 1;
}

int frontStatic(sQueue q, int *e) {
  if (isEmptyQueueStatic(q))
    return 0;
  *e = q.data[q.front];
  return 1;
}

int isEmptyQueueStatic(sQueue q) { return (q.front == (q.rear + 1) % N); }

int isFullQueueStatic(sQueue q) { return (q.front == (q.rear + 2) % N); }

// ################## Linked List Graph ###################### //

Graph *createGraph() {
  int x, y, num, i;
  node *temp1, *temp2;
  Graph *myGraph = (Graph *)malloc(sizeof(Graph));

  printf("Enter the number of Verticies: ");
  scanf("%d", &myGraph->V);
  printf("Enter the number of Edges: ");
  scanf("%d", &myGraph->E);

  // Dummy node for each list
  myGraph->Adj = (node **)malloc(myGraph->V * sizeof(node));
  for (int i = 0; i < myGraph->V; i++) {
    myGraph->Adj[i] = (node *)malloc(myGraph->V * sizeof(node));
    myGraph->Adj[i]->data = i;
    myGraph->Adj[i]->next = NULL;
  }

  for (i = 0; i < myGraph->E; i++) {
    printf("Enter the Edge: ");
    scanf("%d %d", &x, &y);

    temp1 = (node *)malloc(sizeof(node));
    temp1->data = y;
    temp1->next = NULL;
    temp2 = myGraph->Adj[x];
    while (temp2->next)
      temp2 = temp2->next;
    temp2->next = temp1;

    temp1 = (node *)malloc(sizeof(node));
    temp1->data = x;
    temp1->next = NULL;
    temp2 = myGraph->Adj[y];
    while (temp2->next)
      temp2 = temp2->next;
    temp2->next = temp1;
  }
  return myGraph;
}

Graph *createDirGraph() {
  int x, y, num, i;
  node *temp1, *temp2;
  Graph *myGraph = (Graph *)malloc(sizeof(Graph));

  printf("Enter the number of Verticies: ");
  scanf("%d", &myGraph->V);
  printf("Enter the number of Edges: ");
  scanf("%d", &myGraph->E);

  // Dummy node for each list
  myGraph->Adj = (node **)malloc(myGraph->V * sizeof(node));
  for (int i = 0; i < myGraph->V; i++) {
    myGraph->Adj[i] = (node *)malloc(myGraph->V * sizeof(node));
    myGraph->Adj[i]->data = i;
    myGraph->Adj[i]->next = NULL;
  }

  for (i = 0; i < myGraph->E; i++) {
    printf("Enter the Edge: ");
    scanf("%d %d", &x, &y);
    temp1 = (node *)malloc(sizeof(node));
    temp1->data = y;
    temp1->next = NULL;

    temp2 = myGraph->Adj[x];
    while (temp2->next)
      temp2 = temp2->next;
    temp2->next = temp1;
  }
  return myGraph;
}

void DFSRec(Graph *myGraph) {
  int i;
  int *visited;
  visited = (int *)malloc(myGraph->V * sizeof(int));
  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;
  for (i = 0; i < myGraph->V; i++)
    if (!visited[i]) {
      visited[i] = 1;
      DFSTraveraslRec(myGraph, i, visited);
    }
}

void DFSTraveraslRec(Graph *myGraph, int index, int visited[]) {
  node *head;
  head = myGraph->Adj[index]->next;
  printf("%d", index);

  while (head) {
    if (!visited[head->data]) {
      visited[head->data] = 1;
      DFSTraveraslRec(myGraph, head->data, visited);
    }
  }
}

void DFSItr(Graph *myGraph) {
  int i;
  int *visited;
  visited = (int *)malloc(myGraph->V * sizeof(int));
  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;
  for (i = 0; i < myGraph->V; i++)
    if (!visited[i])
      DFSTraveraslItr(myGraph, i, visited);
}

void DFSTraveraslItr(Graph *myGraph, int index, int visited[]) {
  Stack s;
  int e;
  node *head;

  s = createStack();
  Push(&s, index);

  while (Top(s, &e)) {
    Pop(&s);
    printf("%d", e);
    head = myGraph->Adj[e]->next;
    while (head) {
      if (!visited[head->data]) {
        visited[head->data] = 1;
        Push(&s, head->data);
      }
      head = head->next;
    }
  }
}

void BFSItr(Graph *myGraph) {
  int i;
  int *visited;
  visited = malloc(myGraph->V * sizeof(int));
  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;
  for (i = 0; i < myGraph->V; i++)
    if (!visited[i])
      BFSTraversalItr(myGraph, i, visited);
}

void BFSTraversalItr(Graph *myGraph, int index, int visited[]) {
  Queue q;
  int e;
  node *head;

  q = createQueue();
  enQueue(&q, index);
  visited[index] = 1;

  while (Front(q, &e)) {
    deQueue(&q);
    printf("%d", e);
    head = myGraph->Adj[e]->next;
    while (head) {
      if (!visited[head->data]) {
        visited[head->data] = 1;
        enQueue(&q, head->data);
      }
      head = head->next;
    }
  }
}

int Path(Graph *myGraph, int source, int destination) {
  int i;
  int *visited;
  visited = malloc(myGraph->V * sizeof(int));

  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;

  visited[source] = 1;
  DFSTraveraslRec(myGraph, source, visited);
  return visited[destination];
}

int Connected(Graph *myGraph) {
  int i;
  int *visited;
  visited = malloc(myGraph->V * sizeof(int));

  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;

  visited[0] = 1;
  DFSTraveraslRec(myGraph, 0, visited);

  for (i = 0; i < myGraph->V; i++)
    if (!visited[i])
      return 0;

  return 1;
}

void TopologicalSortDFSRec(Graph *myGraph) {
  Stack s;
  int i;
  int *visited;
  int e;

  s = createStack();
  visited = malloc(myGraph->V * sizeof(int));
  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;
  for (i = 0; i < myGraph->V; i++)
    if (!visited[i])
      TSDFSRecHelper(myGraph, i, visited, &s);
  while (Top(s, &e) && Pop(&s) && printf("%d", e))
    ;
}

void TSDFSRecHelper(Graph *myGraph, int index, int *visited, Stack *s) {
  node *head;
  head = myGraph->Adj[index]->next;
  while (head) {
    if (!visited[head->data]) {
      visited[head->data] = 1;
      TSDFSRecHelper(myGraph, head->data, visited, s);
    }
    head = head->next;
  }
  Push(s, index);
}

void TopologicalSortBFSItr(Graph *myGraph) {
  Queue q, topologicalorder;
  int v, w;
  int *indegree;
  node *head;
  indegree = malloc(myGraph->V * sizeof(int));
  for (v = 0; v < myGraph->V; v++)
    indegree[v] = 0;

  for (v = 0; v < myGraph->V; v++) {
    head = myGraph->Adj[v]->next;
    while (head) {
      indegree[head->data]++;
      head = head->next;
    }
  }

  q = createQueue();
  topologicalorder = createQueue();
  int counter = 0;
  for (v = 0; v < myGraph->V; v++)
    if (indegree[v] == 0)
      enQueue(&q, v);

  while (Front(q, &v)) {
    deQueue(&q);
    ++counter;
    enQueue(&topologicalorder, v);
    head = myGraph->Adj[v]->next;
    while (head) {
      if (--indegree[head->data] == 0)
        enQueue(&q, head->data);
      head = head->next;
    }
  }
  if (counter != myGraph->V)
    printf("Graph has cycle!\n");
  while (Front(topologicalorder, &v) && deQueue(&topologicalorder))
    printf("%d", v);
}

void UnWeigthedShortestPath(Graph *myGraph, int s) {
  Queue q;
  int v, w;
  int *distance, *Path;
  node *head;

  Path = malloc(myGraph->V * sizeof(int));
  distance = malloc(myGraph->V * sizeof(int));

  for (v = 0; v < myGraph->V; v++)
    distance[v] = -1;

  q = createQueue();
  enQueue(&q, s);
  distance[s] = 0;

  while (Front(q, &v)) {
    deQueue(&q);
    head = myGraph->Adj[v]->next;
    while (head) {
      if (distance[head->data] == -1) {
        distance[head->data] = distance[v] + 1;
        Path[head->data] = v;
        enQueue(&q, head->data);
      }
      head = head->next;
    }
  }
  for (v = 0; v < myGraph->V; v++)
    printf("%d to %d weight %d\n", Path[v], v, distance[v]);
}

// ################## Matrix Graph ###################### //

mGraph *AdjMatrix() {
  int i, u, v;
  mGraph *myGraph = (mGraph *)malloc(sizeof(mGraph));

  printf("Enter the number of Verticies: ");
  scanf("%d", &myGraph->V);
  printf("Enter the number of Edges: ");
  scanf("%d", &myGraph->E);

  // create space for 2-dimension array of size V x int*
  myGraph->Adj = (int **)malloc(myGraph->V * sizeof(int *));

  // Creating space for each element
  for (u = 0; u < myGraph->V; u++)
    myGraph->Adj[u] = (int *)malloc(myGraph->V * sizeof(int));

  // Filling all the values with 0
  for (u = 0; u < myGraph->V; u++)
    for (v = 0; v < myGraph->V; v++)
      myGraph->Adj[u][v] = 0;

  // Filling The Array
  for (i = 0; i < myGraph->E; i++) {
    printf("Enter the edge: ");
    scanf("%d %d", &u, &v);
    myGraph->Adj[u][v] = 1;
    myGraph->Adj[v][u] = 1;
  }

  return myGraph;
}

mGraph *dirAdjMatrix() {
  int i, u, v, num;
  mGraph *myGraph = (mGraph *)malloc(sizeof(mGraph));

  printf("Enter the number of Verticies: ");
  scanf("%d", &myGraph->V);
  printf("Enter the number of Edges: ");
  scanf("%d", &myGraph->E);

  // create space for 2-dimension array of point ers of size V x int*
  myGraph->Adj = (int **)malloc(myGraph->V * sizeof(int *));

  // Creating space for each element
  for (u = 0; u < myGraph->V; u++)
    myGraph->Adj[u] = (int *)malloc(myGraph->V * sizeof(int));

  // Filling all the values with 0
  for (u = 0; u < myGraph->V; u++)
    for (v = 0; v < myGraph->V; v++)
      myGraph->Adj[u][v] = 0;

  // Filling The Array
  for (i = 0; i < myGraph->E; i++) {
    printf("Enter the edge: ");
    scanf("%d %d", &u, &v);
    myGraph->Adj[u][v] = 1;
  }

  return myGraph;
}

void mDFSRec(mGraph *myGraph) {
  int i, *visited;
  visited = (int *)malloc(myGraph->V * sizeof(int));

  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;

  for (i = 0; i < myGraph->V; i++)
    if (!visited[i]) {
      visited[i] = 1;
      mDFSTraversalRec(myGraph, i, visited);
    }
}

void mDFSTraversalRec(mGraph *myGraph, int index, int visited[]) {
  int v;
  printf("%d", index);
  for (v = 0; v < myGraph->V; v++) {
    if (!visited[v] && myGraph->Adj[index][v]) {
      visited[v] = 1;
      mDFSTraversalRec(myGraph, v, visited);
    }
  }
}

void mBFSItr(mGraph *myGraph) {
  int i;
  int *visited;

  visited = malloc(myGraph->V * sizeof(int));
  for (i = 0; i < myGraph->V; i++)
    if (!visited[i])
      mBFSTraversalItr(myGraph, i, visited);
}

void mBFSTraversalItr(mGraph *myGraph, int index, int *visited) {
  int v, w;
  Queue q;
  q = createQueue();
  enQueue(&q, index);
  visited[index] = 1;

  while (Front(q, &v)) {
    deQueue(&q);
    printf("%d", v);
    for (w = 0; w < myGraph->V; w++)
      if (!visited[w] && myGraph->Adj[v][w]) {
        visited[w] = 1;
        enQueue(&q, w);
      }
  }
}

int mPath(mGraph *myGraph, int source, int destination) {
  int i;
  int *visited;
  visited = malloc(myGraph->V * sizeof(int));

  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;

  visited[source] = 1;
  mDFSTraversalRec(myGraph, source, visited);
  return visited[destination];
}

int mConnected(mGraph *myGraph) {
  int i;
  int *visited;
  visited = malloc(myGraph->V * sizeof(int));

  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;

  visited[0] = 1;
  mDFSTraversalRec(myGraph, 0, visited);

  for (i = 0; i < myGraph->V; i++)
    if (!visited[i])
      return 0;

  return 1;
}

void mToplogicalSortBFSItr(mGraph *myGraph) {
  Queue q, topologicalorder;
  int counter;
  int v, w;
  int *indegree;

  indegree = malloc(myGraph->V * sizeof(int));
  for (v = 0; v < myGraph->V; v++)
    indegree[v] = 0;

  for (v = 0; v < myGraph->V; v++)
    for (w = 0; w < myGraph->V; w++)
      if (myGraph->Adj[v][w] == 1)
        indegree[w]++;

  q = createQueue();
  topologicalorder = createQueue();
  counter = 0;
  for (v = 0; v < myGraph->V; v++)
    if (indegree[v] == 0)
      enQueue(&q, v);

  while (Front(q, &v)) {
    deQueue(&q);
    ++counter;
    enQueue(&topologicalorder, v);

    for (w = 0; w < myGraph->V; w++)
      if (myGraph->Adj[v][w] == 1)
        if (--indegree[w] == 0)
          enQueue(&q, w);

    if (counter != myGraph->V)
      printf("Graph has Cycle!\n");

    while (Front(topologicalorder, &v) && deQueue(&topologicalorder))
      printf("%d", v);
  }
}

void mUnWeigthedShortestPath(mGraph *myGraph, int s) {
  Queue q;
  int v, w;
  int *distance, *Path;

  Path = malloc(myGraph->V * sizeof(int));
  distance = malloc(myGraph->V * sizeof(int));
  for (v = 0; v < myGraph->V; v++)
    distance[v] = -1;

  q = createQueue();
  enQueue(&q, s);
  distance[s] = 0;

  while (Front(q, &v)) {
    deQueue(&q);
    for (w = 0; w < myGraph->V; w++)
      if (myGraph->Adj[v][w] == 1)
        if (distance[w] == -1) {
          distance[w] = distance[v] + 1;
          Path[w] = v;
          enQueue(&q, w);
        }
  }
  for (v = 0; v < myGraph->V; v++)
    printf("%d should pass by %d\n", v, Path[v]);
}

// ################## Binary Tree ###################### //
Btree CreateBTree() { return NULL; }

int isEmptyBTree(Btree T) { return (T == NULL); };

Btree Construct(int e, Btree L, Btree R) {
  Btree temp;
  temp = malloc(sizeof(tnode));
  if (!temp)
    return 0;
  temp->data = e;
  temp->left = L;
  temp->right = R;
  return temp;
}

int Root(Btree T, int *e) {
  if (isEmptyBTree(T))
    return 0;
  *e = T->data;
  return 1;
}

int Right(Btree T, Btree *R) {
  if (isEmptyBTree(T))
    return 0;
  *R = T->right;
  return 1;
}

int Left(Btree T, Btree *L) {
  if (isEmptyBTree(T))
    return 0;
  *L = T->left;
  return 1;
}
