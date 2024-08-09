#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
}*top;

void push(int value) {
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->data = value;
    ptr->link = NULL;

    if (top == NULL) {
        top = ptr;
    }
    else {
        ptr->link = top;
        top = ptr;
    }
}

void pop() {
    if (top == NULL) {
        printf("\nStack is empty.");
    }
    else {
        struct Node* ptr = top;
        top = top->link;
        printf("\nPoped element : [%d]", ptr->data);
        free(ptr);
    }
}

int peek() {
    return top->data;
}

void displayStack() {
    if (top == NULL) {
        printf("\nStack is empty.");
    }
    else {
        struct Node* ptr = top;
        while (ptr != NULL) {
            printf("[%d] ", ptr->data);
            ptr = ptr->link;
        }
    }
}

void Menu() {
    printf("\nChoose the opration :\n");
    printf("[1] Push\n");
    printf("[2] Pop\n");
    printf("[3] Peek\n");
    printf("[4] Display\n");
    printf("[5] Exit\n");
    printf("Enter the option :");
}


int main() {
    top = NULL;
    int value, option, elements;

    do {
        Menu();
        scanf("%d", &option);

        switch (option)
        {
        case 1:

            printf("\nEnter the number of elements to be pushed :");
            scanf("%d", &elements);

            for (int i = 0; i < elements; i++) {
                printf("\nEnter #%d number :", i + 1);
                scanf("%d", &value);
                push(value);
            }

            break;
        case 2:

            printf("\nEnter the number of elements to be poped :");
            scanf("%d", &elements);

            for (int i = 0; i < elements; i++) {
                pop();
            }

            break;
        case 3:

            value = peek();

            printf("\nValue on the top of the stack is : [%d]", value);

            break;
        case 4:

            displayStack();

            break;
        case 5:

            printf("Exiting program ...");

            break;
        default:

            printf("Invalid input.");

            break;
        }
    } while (option != 5);

    return 0;
}