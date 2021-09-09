#include <stdio.h>
#include <stdlib.h>

// Node Definition
typedef struct node {
  int data;
  struct node *next;
} node;

// Push Flavors
void headPush(node **href, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  (*newNode).data = data;

  if (!newNode)
    return;

  (*newNode).next = *href;
  *href = newNode;
}

void tailPush(node **href, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  (*newNode).data = data;
  node *current = *href;

  if (!newNode)
    return;

  if (*href == NULL)
    *href = newNode;
  else {
    while (current && (*current).next) {
      current = (*current).next;
    }

    (*current).next = newNode;
  }
}

// Createlist Flavors
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
    printf("the node of index %d = %d", i, (*currentNode).next);
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
    if (i == n) {
      return currentNode->data;
    } else {
      currentNode = currentNode->next;
    }
    i++;
  }
  return currentNode->data;
}
