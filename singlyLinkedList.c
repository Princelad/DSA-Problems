#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *link;
} *head;

void printLinkedlist() {
  if (head == NULL) {
    printf("List is empty.");
  } else {

    int count = 0;
    const struct Node *temp = head;

    printf("Elements :");

    while (temp != NULL) {
      printf("[%d]", temp->data);
      temp = temp->link;
      count++;
    }

    printf("\nCount :%d\n", count);
  }
}

void addNode(int const value) {
  struct Node *ptr = malloc(sizeof(struct Node));
  ptr->data = value;
  ptr->link = NULL;

  if (head == NULL) {
    head = ptr;
  } else {
    struct Node *temp = head;
    while (temp->link != NULL) {
      temp = temp->link;
    }
    temp->link = ptr;
  }
}

void addNodeFront(int const value) {
  struct Node *ptr = malloc(sizeof(struct Node));
  ptr->data = value;
  ptr->link = NULL;

  if (head == NULL) {
    head = ptr;
  } else {
    ptr->link = head;
    head = ptr;
  }
}

void removeNodeFront() {
  printf("\nRemoving node @1 :\n");

  if (head == NULL) {
    printf("List is empty.");
  } else {
    struct Node *ptr = head;
    head = head->link;
    free(ptr);
  }
}

void removeNodeRear() {
  struct Node *ptr = head;

  printf("\nRemoving node @rear :\n");

  if (head == NULL) {
    printf("List is empty.");
  } else {
    while (ptr->link->link != NULL) {
      ptr = ptr->link;
    }
    struct Node *temp = ptr->link;
    free(temp);
    ptr->link = NULL;
  }
}

void addNodeAt(int const index, int const value) {
  if (head == NULL) {
    printf("List is empty.");
  } else {
    struct Node *ptr = head;
    for (int i = 0; i < index - 2; i++) {
      ptr = ptr->link;
    }
    struct Node *ptr2 = malloc(sizeof(struct Node));
    ptr2->data = value;
    ptr2->link = ptr->link;
    ptr->link = ptr2;
  }
}

void removeNodeAt(int const index) {
  if (head == NULL) {
    printf("List is empty.");
  } else {
    struct Node *ptr = head;
    struct Node *ptr2 = head;
    for (int i = 0; i < index - 1; i++) {
      ptr = ptr->link;
    }

    for (int i = 0; i < index - 2; i++) {
      ptr2 = ptr2->link;
    }

    ptr2->link = ptr->link;
    free(ptr);
  }
}

void Menu() {
  printf("Choose operation :\n");
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

  int option, index, size, data;

  do {
    Menu();
    scanf("%d", &option);

    switch (option) {
    case 1:

      printf("Enter the number of elements :");
      scanf("%d", &size);

      for (int i = 0; i < size; i++) {
        printf("\nEnter the #%d data :", i + 1);
        scanf("%d", &data);

        addNode(data);
      }

      break;

    case 2:

      removeNodeFront();

      break;
    case 3:

      printf("\nEnter the front data :");
      scanf("%d", &data);

      addNodeFront(data);

      break;
    case 4:

      removeNodeFront();

      break;
    case 5:

      printf("\nEnter the position where you want to insert data :");
      scanf("%d", &index);

      printf("Enter the data :");
      scanf("%d", &data);

      addNodeAt(index, data);

      break;
    case 6:

      printf("Enter the index of the element to be removed :");
      scanf("%d", &index);
      removeNodeAt(index);

      break;
    case 7:

      printLinkedlist();

      break;
    case 8:

      printf("Exting the program...");
      break;
    default:

      printf("Invalid option.");
      break;
    }
  } while (option != 8);

  return 0;
}