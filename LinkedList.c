#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* link;
};

int main() {

    struct Node* head;
    struct Node* add;
    head = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    head->link = (struct Node*)malloc(sizeof(struct Node));

    head->link->data = 100;
    head->link->link = NULL;// This is not good option because it causes the program to be static.
    // Better way of doing this is using create a temperory pointer to the node that store the add of the current node.
    // Thus, can be executed in a loop.

    printf("%d\n", head->link->data);

    printf("%d\n", head->data);

    return 0;
}