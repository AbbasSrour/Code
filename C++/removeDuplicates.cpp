#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void pushTail(node **href, int value) {
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return;
  newNode->data = value;
  newNode->next = NULL;

  node *currentNode = *href;
  if (!currentNode) {
    *href = newNode;
    return;
  }
  while (currentNode->next)
    currentNode = currentNode->next;
  currentNode->next = newNode;
}

node *createList() {
  node *head = NULL;
  int n;
  printf("please enter the number of nodes: ");
  scanf("%d", &n);

  int value;
  for (int i = 0; i < n; i++) {
    printf("please enter the value of node %d : ", i);
    scanf("%d", &value);
    pushTail(&head, value);
  }
  return head;
}

void printList(node *head) {
  node *currentNode = head;
  int i = 0;
  while (currentNode) {
    printf("the value of node %d is %d \n", i, currentNode->data);
    currentNode = currentNode->next;
    i++;
  }
}

void removeDups(node **href) {
  node *currentNode = *href;
  if (!currentNode)
    return;

  node *temp = NULL;
  node *nextNode = NULL;

  while (currentNode->next) {
    if (!currentNode)
      return;

    if (currentNode->data == (currentNode->next)->data) {
      nextNode = currentNode->next;
      temp = nextNode->next;
      currentNode->next = temp;
      free(nextNode);
    } else
      currentNode = currentNode->next;
  }
}

void test() {
  node *myList = createList();
  printList(myList);
  removeDups(&myList);
  printList(myList);
}
int main(void) { test(); }
