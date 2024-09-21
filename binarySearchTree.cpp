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

void insertNode(struct Node** root, int value) {
    if (*root == nullptr) {
        *root = createNode(value);
    }
    else if ((*root)->data > value) {
        insertNode(&(*root)->left, value);
    }
    else {
        insertNode(&(*root)->right, value);
    }
}

string searchTree(struct Node* root, struct Node** resultNode) {
    if (root == nullptr) {
        return "Empty tree.";
    }
    else {
        int key;
        cout << "Enter the key : ";
        cin >> key;

        string path = "root";

        while (root != nullptr) {
            if (root->data == key) {
                *resultNode = root;
                return path;
            }
            else if (root->data > key) {
                path += "->left";
                root = root->left;
            }
            else {
                path += "->right";
                root = root->right;
            }
        }

        return "Not found in tree.";
    }
}

void mainMenu() {
    cout << "\nChoose : ";
    cout << "\n[1] Insert Node";
    cout << "\n[2] Search tree";
    cout << "\n[3] Exit";
    cout << "\nChoose option : ";
}

int main() {
    int option, size;

    struct Node* root = nullptr;

    do
    {
        mainMenu();
        cin >> option;

        switch (option) {
        case 1: {
            cout << "Enter the number of elments : ";
            cin >> size;

            int data[size];
            for (int i = 0; i < size; i++) {
                cout << "Enter the element #" << (i + 1) << " : ";
                cin >> data[i];
            }

            for (int i : data) {
                insertNode(&root, i);
            }

            break;
        }
        case 2: {
            struct Node* resultNode = nullptr;

            string path = searchTree(root, &resultNode);

            if (resultNode != nullptr) {
                cout << "Output : [" << resultNode->data << ", "
                    << (resultNode->left == nullptr ? "NULL" : to_string(resultNode->left->data)) << ", "
                    << (resultNode->right == nullptr ? "NULL" : to_string(resultNode->right->data)) << "]"
                    << endl;

                cout << "Path : " << path << endl;
            }
            else {
                cout << "Output : Node not found." << endl;
            }

            break;
        }
        case 3: {
            cout << "\nExiting...\n" << endl;

            break;
        }
        default: cout << "Choose a correct option." << endl;
        }

    } while (option != 3);

    return 0;
}