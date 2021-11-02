#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void tailpush(node **href, int value) {
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return;
  newNode->data = value;
  newNode->next = NULL;

  node *current = *href;
  if (!current) {
    *href = newNode;
    return;
  }
  while (current->next)
    current = current->next;
  current->next = newNode;
}

node *createList() {
  node *head = NULL;

  int n;
  printf("please enter the number of nodes: ");
  scanf("%d", &n);

  int value;
  for (int i = 0; i < n; i++) {
    printf("enter the value of node %d: ", i);
    scanf("%d", &value);
    tailpush(&head, value);
  }
  return head;
}

void printList(node *head) {
  int i = 0;
  node *currentNode = head;

  while (currentNode) {
    printf("the node of index %d = %d\n", i, currentNode->data);
    i++;
    currentNode = currentNode->next;
  }
}

void moveNode(node **href, node **theNode) {
  if (!*theNode)
    return;

  if (!*href) {
    *href = *theNode;
    return;
  }
  node *currentNode = *href;
  while (currentNode->next)
    currentNode = currentNode->next;
  currentNode->next = *theNode;
}

void splitList(node **source, node **href_even, node **href_odd) {
  node *node_to_move;
  node *nextNode = NULL;
  node *currentNode = *source;

  if (!currentNode)
    return;

  while (currentNode) {
    node_to_move = currentNode;
    node_to_move->next = NULL;

    nextNode = currentNode->next;
    currentNode = nextNode;
    *source = nextNode;

    if (node_to_move->data % 2 == 0)
      moveNode(href_even, &node_to_move);
    else
      moveNode(href_odd, &node_to_move);
  }
}

void test() {
  node *sourceList = NULL;
  sourceList = createList();

  node *evenList = NULL;
  node *oddList = NULL;
  printf("The Original List: \n");
  printList(sourceList);

  printf("test\n");
  splitList(&sourceList, &evenList, &oddList);

  printf("The Original List After Splitting (it should be empty): \n");
  printList(sourceList);
  printf("The Even List: \n");
  printList(evenList);
  printf("The Odd List: \n");
  printList(oddList);
}

int main(void) { test(); }
