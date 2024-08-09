#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
}*front, * rear;

void enqueue(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->link = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = ptr;
    }
    else {
        rear->link = ptr;
        rear = ptr;
    }
}

void dequeue() {
    if (front == NULL && rear == NULL) {
        printf("\nQueue is empty.");
    }
    else {
        struct Node* ptr = front;
        front = front->link;
        printf("\nElement dequeued is : [%d]", ptr->data);
        free(ptr);
    }
}

void displayQueue() {
    if (front == NULL && rear == NULL) {
        printf("\nQueue is empty.");
    }
    else {
        struct Node* ptr = front;
        printf("\nElements :");
        while (ptr != NULL) {
            printf("[%d] ", ptr->data);
            ptr = ptr->link;
        }
    }
}

void Menu() {
    printf("\nChoose operation :\n");
    printf("[1] Enqueue\n");
    printf("[2] Dequeue\n");
    printf("[3] Display\n");
    printf("[4] Exit\n");
    printf("Enter the option :");
}

int main() {
    front = rear = NULL;
    int option, value, elements;

    do{
        Menu();
        scanf("%d", &option);

        switch(option) 
        {
        case 1:
    
            printf("\nEnter the number of elements to be enqueued :");
            scanf("%d", &elements);

            for (int i = 0; i < elements; i++) {
                printf("\nEnter #%d number :", i + 1);
                scanf("%d", &value);
                enqueue(value);
            }        
            
            break;
        case 2:

            printf("\nEnter the number of elements to be dequeued :");
            scanf("%d", &elements);

            for (int i = 0; i < elements; i++) {
                dequeue();
            }
            
            break;
        case 3:

            displayQueue();
            
            break;
        case 4:

            printf("\nExiting program ...");
            
            break;
        default:

            printf("\nInvaild input.");
            
            break;
        }
    }while(option != 4);

    return 0;
}