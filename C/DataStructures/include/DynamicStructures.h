#include "Type_DynamicStructures.h"

// ################## Singly Linked List ###################### //

extern void headPush(node **href, int data);
extern void tailPush(node **href, int data);
extern node *createList();
extern void printList(node *head);
extern void deleteList(node **href);
extern int getNthNode(node *head, int n);
extern int headPop(node **href);
extern int lenList(node *head);
extern void sortList(node **href);
extern void swapNodes(node **href, node *nodeA, node *nodeB);
extern node *createNewNode();
extern void sortedInsert(node **href, node *newNode);
extern void append(node **href_A, node **href_B);

// ################## Dynamic Stack ###################### //
extern Stack createStack();
extern int Push(Stack *p, int e);
extern int Pop(Stack *p);
extern int Top(Stack p, int *e);
extern int isEmptyStack(Stack p);

// ################## Dynamic Queue  ###################### //
extern Queue createQueue();
extern int enQueue(Queue *q, int e);
extern int deQueue(Queue *q);
extern int isEmptyQueue(Queue q);
extern int Front(Queue q, int *e);

// ################## Linked List Graph ###################### //
extern Graph *createGraph();
extern Graph *createDirGraph();
extern void DFSRec(Graph *myGraph);
extern void DFSTraveraslRec(Graph *myGraph, int index, int visited[]);
extern void DFSItr(Graph *myGraph);
extern void DFSTraveraslItr(Graph *myGraph, int index, int visited[]);
extern void BFSItr(Graph *myGraph);
extern void BFSTraversalItr(Graph *myGraph, int index, int visited[]);
extern int Path(Graph *myGraph, int source, int destination);
extern int Connected(Graph *myGraph);
extern void TopologicalSortBFSItr(Graph *myGraph);
extern void TopologicalSortDFSRec(Graph *myGraph);
extern void TSDFSRecHelper(Graph *myGraph, int index, int visited[], Stack *s);
extern void UnWeigthedShortestPath(Graph *myGraph, int s);

// ################## Binary Tree ###################### //
extern Btree CreateBTree();
extern int isEmptyBTree(Btree T);
extern Btree Construct(int e, Btree L, Btree R);
extern int Root(Btree T, int *e);
extern int Right(Btree T, Btree *R);
extern int Left(Btree T, Btree *L);
