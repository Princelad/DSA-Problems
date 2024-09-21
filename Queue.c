//
// Created by Prince on 21-08-2024.
//
#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
} *front, *rear;

void enqueue(const int value) {
  struct Node *ptr = malloc(sizeof(struct Node));
  if (ptr == NULL) {
    printf("\nMemory allocation failed.\n");
    return;
  }
  ptr->data = value;
  ptr->link = NULL;
  if (rear != NULL) {
    rear->link = ptr;
  } else {
    front = ptr;
  }
  rear = ptr;
}

void dequeue() {
  if (front != NULL) {
    struct Node *ptr = front;
    printf("\nElement dequeued is: [%d]", front->data);
    front = front->link;
    if (front == NULL) {
      rear = NULL;
    }
    free(ptr);
  } else {
    printf("\nQueue is empty.");
  }
}

void displayQueue() {
  if (front != NULL) {
    const struct Node *ptr = front;
    printf("\nElements: ");
    while (ptr != NULL) {
      printf("[%d] ", ptr->data);
      ptr = ptr->link;
    }
  } else {
    printf("\nQueue is empty.");
  }
}

void displayMenu() {
  printf("\nChoose operation:\n");
  printf("[1] Enqueue\n");
  printf("[2] Dequeue\n");
  printf("[3] Display\n");
  printf("[4] Exit\n");
  printf("Enter the option: ");
}

int main() {
  front = NULL, rear = NULL;
  int option, value, elements;

  do {
    displayMenu();
    scanf("%d", &option);

    switch (option) {
    case 1:
      printf("\nEnter the number of elements to be enqueued: ");
      scanf("%d", &elements);

      for (int i = 0; i < elements; i++) {
        printf("\nEnter #%d number: ", i + 1);
        scanf("%d", &value);
        enqueue(value);
      }
      break;

    case 2:
      printf("\nEnter the number of elements to be dequeued: ");
      scanf("%d", &elements);

      for (int i = 0; i < elements; i++) {
        dequeue();
      }
      break;

    case 3:
      displayQueue();
      break;

    case 4:
      printf("\nExiting program ...\n");
      break;

    default:
      printf("\nInvalid input.");
      break;
    }
  } while (option != 4);

  return 0;
}
