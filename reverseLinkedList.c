//
// Created by Prince on 18-08-2024.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* link;
} *head;

void addNode(int const data) {
  struct Node* ptr = malloc(sizeof(struct Node));
  ptr->data = data;
  ptr->link = NULL;
  if (head == NULL) {
    head = ptr;
  }
  else {
    struct Node* temp = head;
    while (temp->link != NULL) {
      temp = temp->link;
    }
    temp->link = ptr;
  }
}

void reverseList() {
  if (head == NULL) {
    printf("The Linked List is empty");
  }
  else {
    struct Node* prev = NULL;
    struct Node* curr = NULL;
    while (head != NULL) {
      curr = head->link;
      head->link = prev;
      prev = head;
      head = curr;
    }
    head = prev;
  }
}

void display() {
  if (head == NULL) {
    printf("The Linked List is empty.");
  }
  else {
    const struct Node* temp = head;
    printf("\nElements :");
    while (temp != NULL) {
      printf("[%d]", temp->data);
      temp = temp->link;
    }
  }
}

int main() {
  head = NULL;

  int size, data;
  printf("Enter the size of the Linked list :");
  scanf("%d", &size);

  for (int i = 0; i < size; i++) {
    printf("Enter the #%d of the  list :", i + 1);
    scanf("%d", &data);
    addNode(data);
  }

  printf("\nDisplaying the original Linked List :\n");
  display();

  reverseList();

  printf("\nDisplaying the reverse Linked List :\n");
  display();

  return 0;
}
