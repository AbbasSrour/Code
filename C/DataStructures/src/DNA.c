#include <stdio.h>
#include <stdlib.h>

// Q1 Define a structure type called DNA to manipulate a linked list
// representing a strand DNA.
typedef struct ADN {
  char molecule;
  struct ADN *next;
} ADN;

// Q2 Write a function int is_empty (DNA * l) which returns 1 if the linked list
// pointed to by l is empty, 0 otherwise
int est_vide(ADN *l) {
  if (l == NULL)
    return 1;
  else
    return 0;
}

// Q3 Give a DNA function * initializes (char c) initialization of a linked list
// associated with single nucleotide marked with c.
ADN *initialise(char c) {
  ADN *head;
  head = malloc(sizeof(ADN *));
  if (!head)
    return NULL;

  head->molecule = c;
  head->next = NULL;
  return head;
}

// Q4 Write an int add_base_tete function (DNA ** l, char c) which adds the
// nucleotide c at the head from list l. The function returns 1 if the addition
// could be made or 0 in the event of an error.
int ajout_base_tete(ADN **l, char c) {
  ADN *newNode;
  newNode = malloc(sizeof(ADN *));
  if (!newNode)
    return 0;

  newNode->molecule = c;
  newNode->next = *l;
  *l = newNode;
  return 1;
}

// Q5 Write a void function display_strand (DNA * l) which displays the DNA
// strand pointed to by l
void affiche_brin(ADN *l) {
  ADN *current = l;
  if (est_vide(l))
    return;
  printf("The Molecules in the DNA Strand are: \n");
  int i = 0;
  while (current) {
    printf("Molecule %d is %c\n", i, current->molecule);
    i++;
    current = current->next;
  }
}

// Q6 Write a function void libere_brin (DNA ** l) which frees the memory
// allocated to store all the information for the DNA strand pointed to by l.
void libere_brin(ADN **l) {
  ADN *temp;
  ADN *current = *l;
  if (est_vide(*l))
    return;
  while (current) {
    temp = current->next;
    free(current);
    current = temp;
  }
  *l = NULL;
}

// Q8 Write a function int verifie_brin (DNA * l) which returns 1 if the values
// contained in the list pointed to by l are correct (a DNA strand can
// only contain 4 types of values, see upper). The function returns 0 if the
// list is not correct.

int verifie_brin(ADN *l) {
  if (est_vide(l))
    return 0;
  ADN *current = l;
  // Can Be Implented In A better way
  while (current) {
    if (current->molecule != 'A' && current->molecule != 'C' &&
        current->molecule != 'G' && current->molecule != 'T')
      return 0;
    current = current->next;
  }
  return 1;
}

// Q9 Write an int add_base_position function (ADN ** l, char c, int pos) which
// adds in position pos a new element associated with the character c in the
// list pointed to by l. Function returns 1 on success, 0 otherwise. Note: this
// function generalizes the addition cases by first or last position in a list.

// I Believe This Could Have Been Implented Better Without The Need For Seperate
// Cases But I have JAVA EXAM LATER
int ajout_base_position(ADN **l, char c, int pos) {
  ADN *currentNode, *nextNode, *previousNode;

  previousNode = NULL;
  nextNode = NULL;
  currentNode = *l;

  ADN *newNode = malloc(sizeof(ADN));
  newNode->next = NULL;
  newNode->molecule = c;

  // at the head of the list
  if (pos == 0) {
    nextNode = currentNode;
    *l = newNode;
    newNode->next = currentNode;
    return 1;
  }

  int counter = 0;
  while (counter != pos && currentNode->next) {
    previousNode = currentNode;
    currentNode = currentNode->next;
    counter++;
  }

  printf("%d", counter);
  if (counter != pos - 1 && counter != pos)
    return 0;

  // at the tail of the list
  if (counter == pos - 1) {
    currentNode->next = newNode;
    return 1;
  }

  // in the middle of the list
  previousNode->next = newNode;
  newNode->next = currentNode;
  currentNode = newNode;
  return 1;
}

// Q10 Write a function int correct_strand (DNA ** l) which “corrects” a DNA str
// nd stored in the list pointed to by deleting each item that is not
// correct. The function returns 1 if successful, 0 otherwise. For example the
// list A -> T -> R -> Z -> A becomes A -> T -> A.

// implemented a counter for a stupied reason can be done a lot better
int corrige_brin(ADN **l) {
  if (est_vide(*l))
    return 0;
  if (verifie_brin(*l))
    return 1;
  ADN *current = *l;
  ADN *previousNode = NULL, *nextNode = NULL;

  int counter = 0;
  while (current) {
    if (current->molecule != 'A' && current->molecule != 'C' &&
        current->molecule != 'G' && current->molecule != 'T') {
      // head node case
      // their is no need to have current, next, and preivous pointers but I
      // find the logic to be easier to understand and a hell of a lot easier to
      // picture the process of course you can do without one of them feel free
      // to clean the code, manipulating aux vars effeciently is an intro to
      // programing concept that I make do without from time to time in the
      // spirit of simplicity
      if (counter == 0) {
        nextNode = current->next;
        *l = nextNode;
        free(current);
        current = nextNode;
      } else if (counter != 0) {
        nextNode = current->next;
        previousNode->next = nextNode;
        free(current);
        current = nextNode;
      }
    } else {
      previousNode = current;
      current = current->next;
      counter++;
    }
  }
  if (verifie_brin(*l))
    return 1;
  return 0;
}

int main() {
  // Q7 Add / complete the main function to test these first functions and
  // make sure they are correct functioning.
  ADN *myDNA = NULL;

  // test Q2
  int test = est_vide(myDNA);
  if (test)
    printf("Empty Function Works Correctly!\n");
  else
    printf("Q2 NOPE\n");

  // test Q3
  myDNA = initialise('A');
  if (!myDNA)
    printf("Q3 NOPE\n");
  else
    printf("initialise Function Works Correctly! %c\n", myDNA->molecule);

  // test Q4
  test = ajout_base_tete(&myDNA, 'C');
  if (test)
    printf("Push Function Works Correctly! %c\n", (myDNA->next)->molecule);
  else
    printf("Q4 NOPE\n");

  // test Q5
  ajout_base_tete(&myDNA, 'G');
  ajout_base_tete(&myDNA, 'T');
  affiche_brin(myDNA);

  // test Q6
  libere_brin(&myDNA);
  test = est_vide(myDNA);
  if (test)
    printf("Free Function Works Correctly!\n");
  else
    printf("Q6 NOPE\n");

  // test Q8
  ajout_base_tete(&myDNA, 'A');
  ajout_base_tete(&myDNA, 'C');
  ajout_base_tete(&myDNA, 'G');
  ajout_base_tete(&myDNA, 'T');
  // ajout_base_tete(&myDNA, 'D');
  test = verifie_brin(myDNA);
  if (test)
    printf("Check Function Works Correctly!\n");
  else
    printf("Q8 NOPE\n");

  // test Q9
  test = ajout_base_position(&myDNA, 'h', 2);
  test = ajout_base_position(&myDNA, 'e', 4);
  affiche_brin(myDNA);
  if (test)
    printf("Nth Pos Insert Function Works Correctly!\n");
  else
    printf("Q9 NOPE\n");

  // test Q10
  test = corrige_brin(&myDNA);
  affiche_brin(myDNA);
  if (test)
    printf("S&D Function Works Correctly!\n");
  else
    printf("Q10 NOPE\n");

  return 0;
}

// void enQueue(ADN **href, char c) {
//   ADN *newNode = malloc(sizeof(ADN));
//   if (!newNode)
//     return;
//   newNode->molecule = c;
//   newNode->next = NULL;

//   ADN *current = *href;
//   if (!current) {
//     *href = newNode;
//     return;
//   }

//   while (current->next)
//     current = current->next;
//   current->next = newNode;
// }
