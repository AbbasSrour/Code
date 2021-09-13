#include <stdio.h>
#include <stdlib.h>

// Node Definition
typedef struct node {
  int data;
  struct node *next;
} node;

// Head Push
void headPush(node **href, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return;

  newNode->data = data;

  newNode->next = *href;
  *href = newNode;
}

// Tail Push
void tailPush(node **href, int data) {
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return;
  newNode->data = data;
  newNode->next = NULL;

  node *current = *href;
  if (*href == NULL)
    *href = newNode;
  else {
    while (current->next) {
      current = current->next;
    }
    current->next = newNode;
  }
}

// Createlist A linked List Using Push
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
    printf("the node of index %d = %d", i, currentNode->data);
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
    if (i == n)
      return currentNode->data;
    currentNode = currentNode->next;
    i++;
  }
  return currentNode->data;
}

// Pop The Head Node
int headPop(node **href) {
  node *currentNode = *href;
  node *nextNode = currentNode->next;
  int value = currentNode->data;

  free(currentNode);
  *href = nextNode;
  return value;
}

// Get length of the list
int lenList(node *head) {
  int len = 0;
  node *current = head;
  while (current) {
    current = current->next;
    len++;
  }
  return len;
}

// Sort list
void sortList(node **href) {
  node *current = *href;
  node *head = *href;
  node *nodeA, *nodeB;
  int len = lenList(current);
  int swap_made;
  do {
    swap_made = 0;
    current = *href;
    while (current->next) {
      if (current->data > (current->next)->data) {
        nodeA = current;
        nodeB = current->next;
        swapNodes(&head, &nodeA, &nodeB);
        swap_made = 1;
      } else
        current = current->next;
    }
  } while (swap_made);
}

// Swap Nodes
void swapNodes(node **href, node *nodeA, node *nodeB) {

  if (*href == NULL)
    return; // Empty list
  if (nodeA == nodeB)
    return; // Can't swap with itself

  // Be sure that if either node is the first, it will be nodeA
  if (nodeB == *href) {
    node *tmp = nodeA;
    nodeA = nodeB;
    nodeB = tmp;
  }

  // Be sure that if one of the nodes points to the other, then it is nodeA
  // pointing to nodeB
  if (nodeB->next == nodeA) {
    node *tmp = nodeA;
    nodeA = nodeB;
    nodeB = tmp;
  }

  // Easy part, look for nodeA, remove it from the list and add it after nodeB
  node *prevA = NULL; // NULL means it's the head
  if (*href != nodeA) {
    prevA = *href;
    while (prevA->next != NULL && prevA->next != nodeA) {
      prevA = prevA->next;
    }
    if (prevA->next == NULL)
      return; // Can't find node A
  }

  // Unlink node A
  if (prevA == NULL) {
    *href = nodeA->next;
  } else {
    prevA->next = nodeA->next;
  }

  // Add it after node B
  nodeA->next = nodeB->next;
  nodeB->next = nodeA;

  // Look for node B, remove it from the list and add it after what was before
  // node A
  node *prevB = NULL; // NULL means it's the head
  if (*href != nodeB) {
    prevB = *href;
    while (prevB->next != NULL && prevB->next != nodeB) {
      prevB = prevB->next;
    }
    if (prevB->next == NULL)
      return; // Can't find node B
  }

  // Unlink node B
  if (prevB == NULL) {
    *href = nodeB->next;
  } else {
    prevB->next = nodeB->next;
  }
  nodeB->next = NULL;

  // Relink node B after prevA
  if (prevA == NULL) {
    nodeB->next = *href;
    *href = nodeB;
  } else {
    nodeB->next = prevA->next;
    prevA->next = nodeB;
  }
}

void sortList(node **href) {
  node *current = *href;
  node *head = *href;
  node *nodeA, *nodeB;
  int len = lenList(current);
  int swap_made;
  do {
    swap_made = 0;
    current = *href;
    while (current->next) {
      if (current->data > (current->next)->data) {
        nodeA = current;
        nodeB = current->next;
        swapList(&head, &nodeA, &nodeB);
        swap_made = 1;
      } else
        current = current->next;
    }
  } while (swap_made);
}

// Create A New Node
node *createNewNode() {
  node *newNode = (node *)malloc(sizeof(node));
  if (!newNode)
    return NULL;

  int value;
  printf("Please enter the value of the node: ");
  scanf("%d", &value);
  newNode->data = value;

  newNode->next = NULL;
  return newNode;
}

// Insert A Node In A Sorted List
void sortedInsert(node **href, node *newNode) {
  node *current = *href;

  while (current) {
    // Special case for the head
    if ((*href == NULL || (*href)->data >= newNode->data)) {
      newNode->next = *href;
      *href = newNode;
    } else {
      // Locate the node before the point of insertion
      node *current = *href;
      while (current->next != NULL && current->next->data < newNode->data) {
        current = current->next;
      }
      newNode->next = current->next;
      current->next = newNode;
    }
  }
}
