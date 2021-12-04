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
  *href->next = newNode;
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

void test() {
  printf("create List A:\n");
  node *listA = createList();
  printList(listA);

  printf("Create List B: \n");
  node *listB = createList();
  printList(listB);

  append(&listA, &listB);
  printf("The appended list: \n");
  printList(listA);
}
int main(void) { test(); }
