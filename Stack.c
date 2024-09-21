//
// Created by Prince on 21-08-2024.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
} *top = NULL;

void push(int const value) {
  struct Node* newNode = malloc(sizeof(struct Node));
  newNode->data = value;
  newNode->next = NULL;
  if (top == NULL) {
    top = newNode;
  }
  else {
    newNode->next = top;
    top = newNode;
  }
}

void pop() {
  if (top == NULL) {
    printf("\nThe stack is empty.");
  }
  else {
    struct Node* temp = top;
    printf("The popped element : %d", top->data);
    top = temp->next;
    free(temp);
  }
}

void display() {
  const struct Node* temp = top;
  printf("\nElements :");
  while (temp != NULL) {
    printf("[%d]", temp->data);
    temp = temp->next;
  }
}

void menu() {
  printf("\nChoose :\n1. Push\n2. Pop\n3. Display\n4. Exit\n Enter option: ");
}

int main() {

  int option, data, size;

  do {
    menu();
    scanf("%d", &option);

    switch (option) {
    case 1: {
      printf("\nEnter the number of values to be pushed :");
      scanf("%d", &size);
      for (int i = 0; i < size; i++) {
        printf("Enter the #%d of the element :", i + 1);
        scanf("%d", &data);
        push(data);
      }

      break;
    }
    case 2: {

      printf("\nEnter the number of values to be popped :");
      scanf("%d", &size);
      for (int i = 0; i < size; i++) {
        pop();
      }

      break;
    }
    case 3: {

      display();

      break;
    }
    case 4: {

      printf("\nExiting program...");

      break;
    }
    default: {
      printf("Invalid option");
      break;
    }
    }
  } while (option != 4);

  return 0;
}
