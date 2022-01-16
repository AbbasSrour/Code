#include "StaticStructures.h"
#include <stdio.h>
#include <stdlib.h>

// ################## Static Stack ###################### //
Stack createStack() {
  Stack p;
  p.top = -1;
  return p;
}

int Push(Stack *p, int e) {
  if (isFullStack(*p))
    return 0;
  p->data[++p->top] = e;
  return 1;
}

int Pop(Stack *p) {
  if (isEmptyStack(*p))
    return 0;
  p->top--;
  return 1;
}

int Top(Stack p, int *e) {
  if (isEmptyStack(p))
    return 0;
  *e = p.data[p.top];
  return 1;
}

int isEmptyStack(Stack p) {
  if (p.top == -1)
    return 1;
  else
    return 0;
}

int isFullStack(Stack p) {
  if (p.top >= N - 1)
    return 1;
  return 0;
}

// ################## Static Queue  ###################### //
Queue createQueue() {
  Queue q;
  q.front = 1;
  q.rear = 0;
  return q;
}

int enQueue(Queue *q, int e) {
  if (isFullQueue(*q))
    return 0;
  q->rear = (q->rear + 1) % N;
  q->data[q->rear] = e;
  return 1;
}

int deQueue(Queue *q) {
  if (isEmptyQueue(*q))
    return 0;
  q->front = (q->front + 1) % N;
  return 1;
}

int Front(Queue q, int *e) {
  if (isEmptyQueue(q))
    return 0;
  *e = q.data[q.front];
  return 1;
}

int isEmptyQueue(Queue q) { return (q.front == (q.rear + 1) % N); }

int isFullQueue(Queue q) { return (q.front == (q.rear + 2) % N); }

// ################## Matrix Graph ###################### //

Graph *createGraph() {
  int i, u, v;
  Graph *myGraph = (Graph *)malloc(sizeof(Graph));

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

Graph *createDirGraph() {
  int i, u, v, num;
  Graph *myGraph = (Graph *)malloc(sizeof(Graph));

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

void DFSRec(Graph *myGraph) {
  int i, *visited;
  visited = (int *)malloc(myGraph->V * sizeof(int));

  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;

  for (i = 0; i < myGraph->V; i++)
    if (!visited[i]) {
      visited[i] = 1;
      DFSTraversalRec(myGraph, i, visited);
    }
}

void DFSTraversalRec(Graph *myGraph, int index, int visited[]) {
  int v;
  printf("%d", index);
  for (v = 0; v < myGraph->V; v++) {
    if (!visited[v] && myGraph->Adj[index][v]) {
      visited[v] = 1;
      DFSTraversalRec(myGraph, v, visited);
    }
  }
}

void BFSItr(Graph *myGraph) {
  int i;
  int *visited;

  visited = malloc(myGraph->V * sizeof(int));
  for (i = 0; i < myGraph->V; i++)
    if (!visited[i])
      BFSTraversalItr(myGraph, i, visited);
}

void BFSTraversalItr(Graph *myGraph, int index, int *visited) {
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

int Path(Graph *myGraph, int source, int destination) {
  int i;
  int *visited;
  visited = malloc(myGraph->V * sizeof(int));

  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;

  visited[source] = 1;
  DFSTraversalRec(myGraph, source, visited);
  return visited[destination];
}

int Connected(Graph *myGraph) {
  int i;
  int *visited;
  visited = malloc(myGraph->V * sizeof(int));

  for (i = 0; i < myGraph->V; i++)
    visited[i] = 0;

  visited[0] = 1;
  DFSTraversalRec(myGraph, 0, visited);

  for (i = 0; i < myGraph->V; i++)
    if (!visited[i])
      return 0;

  return 1;
}

void ToplogicalSortBFSItr(Graph *myGraph) {
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

void WeigthedShortestPath(Graph *myGraph, int s) {
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
