#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* link;
} *head = NULL;

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

struct Node* reverseList(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* curr = head;
    struct Node* next = NULL;
    while (curr != NULL) {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool isPalindrome() {
    if (head == NULL || head->link == NULL) {
        // An empty list or a list with one node is a palindrome
        return true;
    }

    // Step 1: Find the middle of the list
    struct Node* slow = head;
    struct Node* fast = head;
    while (fast != NULL && fast->link != NULL) {
        slow = slow->link;
        fast = fast->link->link;
    }

    // Step 2: Reverse the second half of the list
    struct Node* second_half = reverseList(slow);

    // Step 3: Compare the two halves
    struct Node* first_half = head;
    struct Node* temp_second_half = second_half;
    bool is_palindrome = true;

    while (temp_second_half != NULL) {
        if (first_half->data != temp_second_half->data) {
            is_palindrome = false;
            break;
        }
        first_half = first_half->link;
        temp_second_half = temp_second_half->link;
    }

    // Step 4: Restore the list to its original order
    reverseList(second_half);

    return is_palindrome;
}

int main() {
    int size, data;
    printf("Enter the size of the Linked list: ");
    scanf("%d", &size);

    for (int i = 0; i < size; i++) {
        printf("Enter the #%d of the list: ", i + 1);
        scanf("%d", &data);
        addNode(data);
    }

    printf("isPalindrome: %s\n", isPalindrome() ? "true" : "false");

    return 0;
}
