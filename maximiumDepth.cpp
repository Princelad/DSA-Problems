#include <iostream>

using namespace std;

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

void insertNode(struct Node** root, int value, int* depth, int* count) {
    if (*root == nullptr) {
        *root = createNode(value);
        
        if (*count > *depth) {
            *depth = *count;
            *count = 0;
        }
    }
    else {
        (*count)++;
        int direction;
        cout << "Left(1) or right(0) : ";
        cin >> direction;

        if (direction) {
            insertNode(&(*root)->left, value, depth, count);
        }
        else {
            insertNode(&(*root)->right, value, depth, count);
        }
    }
}

int main() {
    struct Node* root = nullptr;

    int size;
    cout << "Enter the no. of elements in the tree : ";
    cin >> size;

    int depth = 0, count = 0;
    int data[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter the element no #" << (i + 1) << " : ";
        cin >> data[i];
        insertNode(&root, data[i], &depth, &count);
    }

    cout << "The depth of the tree is : " << depth << endl;

    return 0;
}