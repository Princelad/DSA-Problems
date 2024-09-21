//
// Created by Prince on 14-08-2024.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
  struct Node *previous;
  int data;
  struct Node *next;
} *head;

void addNode(int const value) {
  struct Node *ptr = malloc(sizeof(struct Node));
  ptr->data = value;
  ptr->next = ptr->previous = NULL;

  if (head == NULL) {
    head = ptr;
  } else {
    struct Node *temp = head;

    while (temp->next != NULL) {
      temp = temp->next;
    }

    temp->next = ptr;
    ptr->previous = temp;
  }
}

void removeRearNode() {
  if (head == NULL) {
    printf("The Linked list is empty.");
  } else {
    struct Node *temp = head;
    while (temp->next != NULL) {
      temp = temp->next;
    }
    struct Node *ptr = temp->previous;
    ptr->next = NULL;
    free(temp);
  }
}

void addFrontNode(int const value) {
  struct Node *ptr = malloc(sizeof(struct Node));
  ptr->data = value;
  ptr->previous = ptr->next = NULL;
  if (head == NULL) {
    head = ptr;
  } else {
    head->previous = ptr;
    ptr->next = head;
    head = ptr;
  }
}

void removeFrontNode() {
  if (head == NULL) {
    printf("The Linked List is empty.");
  } else {
    struct Node *temp = head;
    head = head->next;
    head->previous = NULL;
    free(temp);
  }
}

void addNodeAt(int const index, int const value) {
  struct Node *ptr = malloc(sizeof(struct Node));
  ptr->data = value;
  ptr->next = ptr->previous = NULL;
  if (head == NULL) {
    head = ptr;
  } else {
    struct Node *temp = head;
    for (int i = 0; i < index - 1; i++) {
      temp = temp->next;
    }
    ptr->next = temp->next;
    temp->next->previous = ptr;
    temp->next = ptr;
    ptr->previous = temp;
  }
}

void removeNodeAt(int const index) {
  if(head == NULL) {
    printf("The Linked List is empty.");
  } else {
    struct Node* ptr = head;
    for(int i = 0; i < index - 2; i++) {
      ptr = ptr->next;
    }
    struct Node* temp = ptr->next;
    ptr->next = temp->next;
    temp->next->previous = ptr;
    free(temp);
  }
}

void printList() {
  if (head == NULL) {
    printf("The Linked list is empty.");
  } else {
    const struct Node *temp = head;
    printf("\nElements :");
    while (temp != NULL) {
      printf("[%d]", temp->data);
      temp = temp->next;
    }
  }
}

void Menu() {
  printf("\nChoose operation :\n");
  printf("[1] Add Nodes\n");
  printf("[2] Remove Node from rear\n");
  printf("[3] Add Node in front\n");
  printf("[4] Remove  Node from front\n");
  printf("[5] Add Node at index\n");
  printf("[6] Remove Node from index\n");
  printf("[7] Display the Linked list\n");
  printf("[8] Exit\n");
  printf("Enter the option :");
}

int main() {
  head = NULL;
  int option, data, index, number;
  do {
    Menu();
    scanf("%d", &option);

    switch (option) {
    case 1: {
      printf("\nEnter the initial size of the list :");
      scanf("%d", &number);
      for (int i = 0; i < number; i++) {
        printf("\nEnter the #%d element :", i + 1);
        scanf("%d", &data);
        addNode(data);
      }
      break;
    }
    case 2: {
      removeRearNode();
      break;
    }
    case 3: {
      printf("\nEnter the value :");
      scanf("%d", &data);
      addFrontNode(data);
      break;
    }
    case 4: {
      removeRearNode();
      break;
    }
    case 5: {
      printf("\nEnter the index :");
      scanf("%d", &index);
      printf("Enter the value :");
      scanf("%d", &data);
      addNodeAt(index, data);
      break;
    }
    case 6: {
      printf("\nEnter the index :");
      scanf("%d", &index);
      removeNodeAt(index);
      break;
    }
    case 7: {
      printList();
      break;
    }
    case 8: {
      printf("Exiting program...");
      break;
    }
    default: {
      printf("Choose a correct option.");
      break;
    }
    }

  } while (option != 8);
}
