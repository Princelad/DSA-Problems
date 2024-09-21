//
// Created by Prince on 06-09-2024.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
};

void addNode(struct Node **head, const int data) {
  struct Node *newNode = malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->link = NULL;

  if (*head == NULL) {
    *head = newNode;
  } else {
    struct Node *temp = *head;
    while (temp->link != NULL) {
      temp = temp->link;
    }
    temp->link = newNode;
  }
}

struct Node *mergeSortedLinkedList(const struct Node *head1,
                                   const struct Node *head2) {
  struct Node *r = NULL;

  while (head1 != NULL && head2 != NULL) {
    if (head1->data < head2->data) {
      addNode(&r, head1->data);
      head1 = head1->link;
    } else {
      addNode(&r, head2->data);
      head2 = head2->link;
    }
  }

  while (head1 != NULL) {
    addNode(&r, head1->data);
    head1 = head1->link;
  }

  while (head2 != NULL) {
    addNode(&r, head2->data);
    head2 = head2->link;
  }

  return r;
}

void display(const struct Node *head) {
  if (head == NULL) {
    printf("List is empty\n");
  } else {
    const struct Node *temp = head;
    while (temp != NULL) {
      printf("[%d] ", temp->data);
      temp = temp->link;
    }
    printf("\n");
  }
}

int main() {
  struct Node *head1 = NULL;
  struct Node *head2 = NULL;

  int size, data;

  printf("\nEnter the initial size of the first linked list: ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    printf("Enter the value #%d: ", i + 1);
    scanf("%d", &data);
    addNode(&head1, data);
  }

  printf("\nEnter the initial size of the second linked list: ");
  scanf("%d", &size);
  for (int i = 0; i < size; i++) {
    printf("Enter the value #%d: ", i + 1);
    scanf("%d", &data);
    addNode(&head2, data);
  }

  const struct Node *mergedHead = mergeSortedLinkedList(head1, head2);

  printf("\nThe merged Linked List is: ");
  display(mergedHead);

  return 0;
}
