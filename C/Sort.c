#include <stdio.h>
#include <stdlib.h>

typedef struct node {
  int data;
  struct node *next;
} node;

void tailPush(node **href, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = data;
  if (!newNode)
    return;

  node *current = *href;
  if (!current)
    *href = newNode;
  else {
    while (current->next)
      current = current->next;
    current->next = newNode;
  }
}

void headPush(node **href, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  newNode->data = data;
  node *current = *href;

  if (!newNode)
    return;

  newNode->next = *href;
  *href = newNode;
}

node *createList() {
  node *head = NULL;

  int n, value;
  printf("please enter the number of nodes to push: ");
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    printf("please enter the value of node %d: ", i);
    scanf("%d", &value);
    tailPush(&head, value);
  }
  return head;
}

void printtList(node *head) {
  node *current = head;
  int count = 0;
  while (current) {
    printf("the value of node %d is equal to %d\n", count, current->data);
    current = current->next;
    count++;
  }
}

int lenList(node *head) {
  int len = 0;
  node *current = head;
  while (current) {
    current = current->next;
    len++;
  }
  return len;
}

void swapList(node **href, node **nodeA, node **nodeB) {
  node *currentHead = *href;

  // looking for node prevA
  node *prevA = NULL;
  while (currentHead && currentHead != *nodeA) {
    prevA = currentHead;
    currentHead = currentHead->next;
  }

  currentHead = *href;

  // looking for prevB
  node *prevB = NULL;
  while (currentHead && currentHead != *nodeB) {
    prevB = currentHead;
    currentHead = currentHead->next;
  }

  // reasigning the entering links
  if (prevA != NULL)
    prevA->next = *nodeB;
  if (prevB != NULL)
    prevB->next = *nodeA;

  // reasigning the exiting links
  node *nextA = (*nodeA)->next;
  node *nextB = (*nodeB)->next;

  node *temp = (*nodeA)->next;
  (*nodeA)->next = nextB;
  (*nodeB)->next = temp;
}

void sortList(node **href) {
  node *current = *href;
  node *head = *href;
  node *nodeA, *nodeB;
  int len = lenList(current);

  for (int i = 0; i < len * len; i++) {
    while (current->next) {
      if (current->data >= (current->next)->data) {
        nodeA = current;
        nodeB = current->next;
        swapList(&head, &nodeA, &nodeB);
      }
      current = current->next;
    }
    current = head;
  }
}

void test() {
  node *mylist;

  mylist = createList();
  printf("the unsorted linked list is:\n");
  printtList(mylist);

  sortList(&mylist);
  printf("the sorted list is:\n");
  printtList(mylist);
}

int main(void) { test(); }
