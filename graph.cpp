#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    vector<struct Node*> adjacentNodes;
    int isVisited;
    int discoveryTime;
    int finalTime;
    int id; // Unique ID for each node to identify traversal order

    Node(int nodeId) {
        id = nodeId;
        finalTime = discoveryTime = isVisited = 0;
    }
};

// Function to visualize the traversal order
void printTraversalOrder(const vector<int>& traversalOrder, const string& traversalType) {
    cout << traversalType << " Traversal Order: ";
    for (int nodeId : traversalOrder) {
        cout << "Node " << nodeId << " ";
    }
    cout << endl;
}

void DFSVisited(struct Node* node, int& time, vector<int>& traversalOrder) {
    node->isVisited = 1; // Mark as visited
    time++;
    node->discoveryTime = time;
    traversalOrder.push_back(node->id); // Store traversal order
    cout << "Visited Node " << node->id << " (Discovery Time: " << node->discoveryTime << ")" << endl;

    for (struct Node* adjNode : node->adjacentNodes) {
        if (adjNode->isVisited == 0) {
            DFSVisited(adjNode, time, traversalOrder);
        }
    }

    node->isVisited = 2; // Mark as fully processed
    time++;
    node->finalTime = time;
    cout << "Node " << node->id << " Final Time: " << node->finalTime << endl;
}

void DFS(const vector<struct Node*>& nodes) {
    int time = 0;
    vector<int> traversalOrder;

    cout << "DFS Traversal:" << endl;
    for (struct Node* node : nodes) {
        if (node->isVisited == 0) {
            DFSVisited(node, time, traversalOrder);
        }
    }

    printTraversalOrder(traversalOrder, "DFS");
}

void BFSVisited(struct Node* node, int& time, vector<int>& traversalOrder) {
    queue<struct Node*> q;

    node->isVisited = 1; // Mark as visited
    q.push(node);
    node->discoveryTime = ++time;
    traversalOrder.push_back(node->id); // Store traversal order
    cout << "Visited Node " << node->id << " (Discovery Time: " << node->discoveryTime << ")" << endl;

    while (!q.empty()) {
        struct Node* currentNode = q.front();
        q.pop();

        for (struct Node* adjNode : currentNode->adjacentNodes) {
            if (adjNode->isVisited == 0) {
                adjNode->isVisited = 1;
                adjNode->discoveryTime = ++time;
                traversalOrder.push_back(adjNode->id); // Store traversal order
                cout << "Visited Node " << adjNode->id << " (Discovery Time: " << adjNode->discoveryTime << ")" << endl;
                q.push(adjNode);
            }
        }
        currentNode->isVisited = 2; // Mark as fully processed
    }
}

void BFS(const vector<struct Node*>& nodes) {
    int time = 0;
    vector<int> traversalOrder;

    cout << "BFS Traversal:" << endl;
    for (struct Node* node : nodes) {
        if (node->isVisited == 0) {
            BFSVisited(node, time, traversalOrder);
        }
    }

    printTraversalOrder(traversalOrder, "BFS");
}

void mainMenu() {
    cout << "\nChoose an option: " << endl;
    cout << "[1] DFS traversal" << endl;
    cout << "[2] BFS traversal" << endl;
    cout << "[3] Exit" << endl;
    cout << "Enter your option: ";
}

int main() {
    int option;

    int numberOfVertices;
    cout << "Enter the number of vertices: ";
    cin >> numberOfVertices;

    vector<struct Node*> vertices(numberOfVertices);

    // Initialize each vertex (node) with a unique ID
    for (int i = 0; i < numberOfVertices; i++) {
        vertices[i] = new Node(i); // Assigning node ID as 'i'
    }

    // Input adjacency lists
    for (int i = 0; i < numberOfVertices; i++) {
        int numberOfAdjacentVertices;
        cout << "Enter the number of adjacent vertices for vertex " << i << ": ";
        cin >> numberOfAdjacentVertices;

        for (int j = 0; j < numberOfAdjacentVertices; j++) {
            int adjacentVertexIndex;
            cout << "Enter the adjacent vertex index for vertex " << i << ": ";
            cin >> adjacentVertexIndex;

            if (adjacentVertexIndex >= 0 && adjacentVertexIndex < numberOfVertices) {
                vertices[i]->adjacentNodes.push_back(vertices[adjacentVertexIndex]);
            } else {
                cout << "Invalid vertex index!" << endl;
            }
        }
    }

    do {
        mainMenu();
        cin >> option;

        // Reset all nodes' visited status for each traversal
        for (int i = 0; i < numberOfVertices; i++) {
            vertices[i]->isVisited = 0;
            vertices[i]->discoveryTime = 0;
            vertices[i]->finalTime = 0;
        }

        switch (option) {
        case 1:
            DFS(vertices);
            break;
        case 2:
            BFS(vertices);
            break;
        case 3:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid option!" << endl;
            break;
        }
    } while (option != 3);

    // Clean up memory
    for (int i = 0; i < numberOfVertices; i++) {
        delete vertices[i];
    }

    return 0;
}