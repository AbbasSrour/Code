#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void tailPush(node **href, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  (*newNode).data = data;

  if (!newNode)
    return;

  node *currentNode = *href;
  if (!currentNode)
    currentNode = newNode;
  else {
    while (currentNode->next) {
      currentNode = currentNode->next;
    }
    currentNode->next = newNode;
  }
}

node *createList() {
  node *head = NULL;
  int n, value;

  printf("please enter the number of nodes: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("please enter the value of node %d : ", i);
    scanf("%d", &value);

    tailPush(&head, value);
  }

  printf("test");
  return head;
}

void printList(node *head) {
  node *currentNode = head;
  int i = 0;
  printf("test");
  while (currentNode) {
    printf("the value of the node %d is equal to %d", i, currentNode->data);
    i++;
  }
}

int headPop(node **href) {
  node *currentNode = *href;
  node *nextNode = currentNode->next;
  int value = currentNode->data;

  free(currentNode);
  *href = nextNode;
  return value;
}

int main(void) {
  node *mylist = createList();
  printList(mylist);

  int value = headPop(&mylist);
  printf("the value of the node poped is equal to %d", value);
  printList(mylist);
}
