#include "Type_StaticStructures.h"

// ################## Static Stack ###################### //
extern Stack createStack();
extern int Push(Stack *p, int e);
extern int Pop(Stack *p);
extern int Top(Stack p, int *e);
extern int isEmptyStack(Stack p);
extern int isFullStack(Stack p);

// ################## Static Queue  ###################### //
extern Queue createQueue();
extern int enQueue(Queue *q, int e);
extern int deQueueStatic(Queue *q);
extern int Front(Queue q, int *e);
extern int isEmptyQueue(Queue q);
extern int isFullQueue(Queue q);

// ################## Matrix Graph ###################### //
extern Graph *createGraph();
extern Graph *createDirGraph();
extern void DFSRec(Graph *myGraph);
extern void DFSTraversalRec(Graph *myGraph, int index, int visited[]);
extern void BFSItr(Graph *myGraph);
extern void BFSTraversalItr(Graph *myGraph, int index, int *visited);
extern int Path(Graph *myGraph, int source, int destination);
extern int Connected(Graph *myGraph);
extern void ToplogicalSortBFSItr(Graph *myGraph);
extern void UnWeigthedShortestPath(Graph *myGraph, int s);
