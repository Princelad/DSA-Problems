#include <iostream>

using namespace std;

struct Node {
    struct Node* right;
    int data;
    struct Node* left;
};

struct Node* createNode(int value) {
    struct Node* newNode = new Node;
    newNode->data = value;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
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

void binaryTreeRightView(struct Node* root, bool right) {
    if (root != nullptr) {
        if (right) {
            printf("[%d]", root->data);
        }
        binaryTreeRightView(root->right, true);
        binaryTreeRightView(root->left, false);
    }
}

void printLeaves(struct Node* root) {
    if (root) {
        printLeaves(root->left);
        if (!root->left && !root->right) {
            printf("[%d]", root->data);
        }
        printLeaves(root->right);
    }
}

void printLeftBoundary(struct Node* root) {
    if (root) {
        if (root->left) {
            printf("[%d]", root->data);
            printLeftBoundary(root->left);
        }
        else if (root->right) {
            printf("[%d]", root->data);
            printLeftBoundary(root->right);
        }
    }
}

void printRightBoundary(struct Node* root) {
    if (root) {
        if (root->right) {
            printRightBoundary(root->right);
            printf("[%d]", root->data);
        }
        else if (root->left) {
            printRightBoundary(root->left);
            printf("[%d]", root->data);
        }
    }
}

void binaryTreeBoundary(struct Node* root) {
    if (root) {
        printf("[%d]", root->data);
        printLeftBoundary(root->left);
        printLeaves(root);
        printRightBoundary(root->right);
    }
}

int main() {
    struct Node* root = nullptr;
    int size, option;

    cout << "Enter the no. of elements : ";
    cin >> size;

    int data[size];
    for (int i = 0; i < size; i++) {
        cout << "Enter element no. #" << (i + 1) << " : ";
        cin >> data[i];
        insertNode(&root, data[i]);
    }

    do {

        cout << "\nChoose : ";
        cout << "\n[1] Binary tree right view";
        cout << "\n[2] Binary tree boundary";
        cout << "\n[3] Exit";
        cout << "\nEnter your choice : ";
        cin >> option;

        cout << "Output : ";

        switch (option)
        {
        case 1: {
            binaryTreeRightView(root, true);

            break;
        }
        case 2: {
            binaryTreeBoundary(root);

            break;
        }
        case 3: {
            cout << "Exiting ..." << endl;

            break;
        }
        default: {
            cout << "Enter a valid option." << endl;

            break;
        }
        }

        cout << endl;

    } while (option != 3);

    return 0;
}