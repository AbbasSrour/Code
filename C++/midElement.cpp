#include <math.h>
#include <stdio.h>

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

int lenList(node *head) {
  node *currentNode = head;
  int i = 0;
  while (currentNode) {
    i++;
    currentNode = currentNode->next;
  }
  return i;
}

node *midElement(node *head) {
  node *currentNode = head;
  int n = lenList(head), i = 0;
  while (currentNode) {
    if ((n % 2 == 0) && (i = (n / 2) + 1)) {
      currentNode = currentNode->next;
      break;
    } else if ((n % 2 != 0) && (i = (n / 2) + 2)) {
      currentNode = currentNode->next;
      break;
    }
    currentNode = currentNode->next;
    i++;
  }
  return currentNode;
}

void test() {
  node *myList = createList();
  printList(myList);
  node *midNode = midElement(myList);
  printf("the value of the mid node is %d", midNode->data);
}

int main(void) { test(); }
