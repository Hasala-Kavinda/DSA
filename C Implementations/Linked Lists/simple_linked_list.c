#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
  int data;
  int key;
  struct node *next;
} Node;

Node *head = NULL;
Node *current = NULL;

// display the lsit
void printList() {
  Node *ptr = head;
  printf("\n[");

  // starting from the begining
  while (ptr != NULL) {

    printf("(%d, %d) ,", ptr->key, ptr->data);
    ptr = ptr->next;
  }
  printf("]");
}

// inset at the first location
void insertFirst(int key, int data) {

  // create a link
  Node *link = (Node *)malloc(sizeof(Node));

  link->key = key;
  link->data = data;

  // point it to old first node
  link->next = head;

  // point fist to new node
  head = link;
}

Node *deleteFirst() {

  // save referance to fist link
  Node *tempLink = head;

  // mark next to first link as first
  head = head->next;

  return tempLink;
}

// is list empty
bool isEmpty() { return head == NULL; }

int length() {
  int length = 0;
  Node *current;

  for (current = head; current != NULL; current = current->next) {
    length++;
  }

  return length;
}

// find a link with given key
Node *find(int key) {

  // start from the fit link
  Node *current = head;

  // if list is empty
  if (head == NULL) {
    return NULL;
  }

  // navigate through list
  while (current->key != key) {

    // if it is last node
    if (current->next == NULL) {
      return NULL;
    } else {
      // go to next link
      current = current->next;
    }
  }
  // if data found, return the current link
  return current;
}

Node *delete(int key) {
  Node *current = head;
  Node *previous = NULL;

  // if list is empty
  if (head == NULL) {
    return NULL;
  }

  // navigate through list
  while (current->key != key) {

    // if it is last node
    if (current->next == NULL) {
      return NULL;
    } else {
      // store reference to current node
      previous = current;

      // move to next link
      current = current->next;
    }
  }

  // found a match, update the link
  if (current == head) {
    // change first to point to next link
    head = head->next;
  } else {
    // bypassthe currrent link
    previous->next = current->next;
  }
  return current;
}

void sort() {

  int i, j, k, tempKey, tempData;
  Node *current;
  Node *next;

  int size = length();
  k = size;

  for (int i = 0; i < size - 1; i++, k--) {
    current = head;
    next = head->next;

    for (j = 1; j < k; j++) {

      if (current->data > next->data) {
        tempData = current->data;
        current->data = next->data;
        next->data = tempData;

        tempKey = current->key;
        current->key = next->key;
        next->key = tempKey;
      }

      current = current->next;
      next = next->next;
    }
  }
}

void sort_improved() {
  if (head == NULL || head->next == NULL) {
    return;
  }

  int swapped;
  Node *current = head;
  Node *last = NULL;

  do {

    swapped = 0;
    int tempKey, tempData;

    current = head;
    while (current->next != last) {
      if (current->data > current->next->data) {

        tempData = current->data;
        current->data = current->next->data;
        current->next->data = tempData;

        tempKey = current->key;
        current->key = current->next->data;
        current->next->key = tempKey;

        swapped = 1;
      }
      current = current->next;
    }
    last = current;

  } while (swapped);
}

void reverse(Node **head_ref) {

  Node *prev = NULL;
  Node *current = *head_ref;
  Node *next = NULL;

  while (current != NULL) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
}
int main() {
  insertFirst(1, 10);
  insertFirst(2, 20);
  insertFirst(3, 30);
  insertFirst(4, 1);
  insertFirst(5, 40);
  insertFirst(6, 56);

  printf("Original List:");

  printList();

  while (!isEmpty()) {
    struct node *temp = deleteFirst();
    printf("\nDeleted value:");
    printf("(%d,%d) ", temp->key, temp->data);
  }

  printf("\nList after deleting all items: ");
  printList();

  insertFirst(1, 10);
  insertFirst(2, 20);
  insertFirst(3, 30);
  insertFirst(4, 1);
  insertFirst(5, 40);
  insertFirst(6, 56);

  printf("\nRestored List: ");
  printList();
  printf("\n");
  struct node *foundLink = find(4);

  if (foundLink != NULL) {
    printf("Element found: ");
    printf("(%d,%d) ", foundLink->key, foundLink->data);
    printf("\n");
  } else {
    printf("Element not found.");
  }

  delete(4);
  printf("List after deleting an item: ");
  printList();
  printf("\n");
  foundLink = find(4);

  if (foundLink != NULL) {
    printf("Element found: ");
    printf("(%d,%d) ", foundLink->key, foundLink->data);
    printf("\n");
  } else {
    printf("Element not found.");
  }

  printf("\n");
  sort();
  printf("List after sorting the data: ");
  printList();
  reverse(&head);
  printf("\nList after reversing the data: ");
  printList();

  return 0;
}
