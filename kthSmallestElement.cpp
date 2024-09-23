#include <iostream>
#include <vector>

using namespace std;

struct Node {
    struct Node* left;
    int data;
    struct Node* right;
};

struct Node* createNode(int value) {
    struct Node* ptr = new Node;
    ptr->data = value;
    ptr->left = nullptr;
    ptr->right = nullptr;
    return ptr;
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

void inOrder(struct Node* root, vector<int>* result, int key) {
    if (root != NULL && --key) {
        inOrder(root->left, &(*result), key);
        (*result).push_back(root->data);
        inOrder(root->right, &(*result), key);
    }
}

int kthSmallestElement(struct Node* root) {
    vector<int> result;
    
    int key;
    cout << "Enter the value for k : ";
    cin >> key;
    key--;
    
    inOrder(root, &result, key);

    return result[key];
}

int main() {
    struct Node* root = nullptr;
    int size;

    cout << "Enter the number of elements to insert : ";
    cin >> size;

    int data[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter the element no. #" << (i + 1) << " : ";
        cin >> data[i];
        insertNode(&root, data[i]);
    }

    int ans = kthSmallestElement(root);

    cout << "Output : " << ans << endl;

    return 0;
}