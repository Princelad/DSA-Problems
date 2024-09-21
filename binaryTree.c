#include <stdio.h>
#include <stdlib.h>
//
// Created by Prince on 13-09-2024.
//
struct Node {
  struct Node* left;
  int data;
  struct Node* right;
};

struct Queue {
  struct Node* root;
  struct Queue* next;
} *front = NULL, * rear = NULL;

void enqueue(struct Node* root) {
  struct Queue* q = malloc(sizeof(struct Queue));
  q->root = root;
  q->next = NULL;
  if (rear != NULL) {
    rear->next = q;
  }
  else {
    front = q;
  }
  rear = q;
}

struct Node* dequeue() {
  if (front == NULL) {
    printf("\nQueue is empty.");
    return NULL;
  }

  struct Node* temp = front->root;
  struct Queue* toFree = front;
  front = front->next;

  if (front == NULL) {
    rear = NULL;
  }

  free(toFree);

  return temp;
}

struct Node* createNode(const int data) {
  struct Node* node = malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}

void insertNode(struct Node** root, const int value) {
  int direction;
  if (*root == NULL) {
    *root = createNode(value);
  }
  else {
    printf("Left(1) or right(0) :");
    scanf("%d", &direction);
    if (direction) {
      insertNode(&(*root)->left, value);
    }
    else {
      insertNode(&(*root)->right, value);
    }
  }
}

void deleteNode(struct Node** root) {
  if (*root == NULL) {
    printf("Node is empty.\n");
    return;
  }

  if ((*root)->left == NULL && (*root)->right == NULL) {
    struct Node* temp = *root;
    *root = NULL;
    free(temp);
    printf("Leaf node deleted.\n");
  }
  else {
    int direction;
    printf("Left(1) or right(0): ");
    scanf("%d", &direction);
    if (direction) {
      deleteNode(&(*root)->left);
    }
    else {
      deleteNode(&(*root)->right);
    }
  }
}

void inOrder(const struct Node* root) {
  if (root != NULL) {
    inOrder(root->left);
    printf("[%d]", root->data);
    inOrder(root->right);
  }
}

void preOrder(const struct Node* root) {
  if (root != NULL) {
    printf("[%d]", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(const struct Node* root) {
  if (root != NULL) {
    postOrder(root->left);
    postOrder(root->right);
    printf("[%d]", root->data);
  }
}

void levelOrder(struct Node* root) {
  if (root == NULL) {
    printf("Empty Tree");
  }
  else {
    enqueue(root);

    struct Node* node = NULL;

    while (front != NULL) {
      node = dequeue();

      printf("[%d]", node->data);

      if (node->left != NULL) {
        enqueue(node->left);
      }

      if (node->right != NULL) {
        enqueue(node->right);
      }
    }

    free(node);
  }
}

void mainMenu() {
  printf("\nOperations:");
  printf("\n1.Insert Node");
  printf("\n2.Delete Node");
  printf("\n3.InOrder");
  printf("\n4.PreOrder");
  printf("\n5.PostOrder");
  printf("\n6.Level Order");
  printf("\n7.Exit");
  printf("\nEnter your choice: ");
}

int main() {
  struct Node* root = NULL;
  int option, size;

  do {
    mainMenu();
    scanf("%d", &option);

    switch (option) {
    case 1: {
      printf("\nEnter the number of elements : ");
      scanf("%d", &size);

      int data[size];
      for (int i = 0; i < size; i++) {
        printf("Enter the element #%d : ", (i + 1));
        scanf("%d", &data[i]);
        insertNode(&root, data[i]);
      }

      break;
    }
    case 2: {
      deleteNode(&root);
      break;
    }
    case 3: {
      printf("\nInorder Traversal:");
      inOrder(root);
      break;
    }
    case 4: {
      printf("\nPreorder Traversal:");
      preOrder(root);
      break;
    }
    case 5: {
      printf("\nPostorder Traversal:");
      postOrder(root);
      break;
    }
    case 6: {
      printf("\nLevel order Traversal:");
      levelOrder(root);
      break;
    }
    case 7: {
      printf("\nExiting...");
      break;
    }
    default: {
      printf("Invalid choice");
    }
    }
  } while (option != 7);

  return 0;
}