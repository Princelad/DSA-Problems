#include <iostream>
#include <vector>

using namespace std;

void heapify_Max(vector<int>& heap, const int& i) {
    int largest = i;
    int left = (2 * i) + 1;
    int right = (2 * i) + 2;
    int size = heap.size();

    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }

    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(heap[largest], heap[i]);
        heapify_Max(heap, largest);
    }
}

void buildHeap_Max(vector<int>& heap) {
    for (int i = (heap.size() / 2) - 1; i >= 0; i--) {
        heapify_Max(heap, i);
    }
}

void insertNode(vector<int>& heap, const int& data) {
    heap.push_back(data);
    int i = heap.size() - 1;

    while (i != 0 && heap[(i - 1) / 2] < heap[i]) {
        swap(heap[i], heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void removeNode(vector<int>& heap) {
    if (heap.size() == 0) {
        cout << "Heap is empty." << endl;
        return;
    }

    heap[0] = heap[heap.size() - 1];
    heap.pop_back();

    heapify_Max(heap, 0);
}

void printHeap(const vector<int>& heap) {
    cout << "Heap : ";
    for (int element : heap) {
        cout << '[' << element << ']';
    }
    cout << endl << endl;
}

void mainMenu() {
    cout << "Choose operation: " << endl;
    cout << "[1] Build Heap." << endl;
    cout << "[2] Insert an element in Heap." << endl;
    cout << "[3] Remove an element in Heap." << endl;
    cout << "[4] Print Heap." << endl;
    cout << "[5] Exit." << endl;
    cout << "Choose your option: ";
}

int main() {
    int option, data;

    vector<int> heap;

    do {
        mainMenu();
        cin >> option;

        switch (option) {
        case 1:
            int size;
            cout << "Enter the number of elements in Heap: ";
            cin >> size;
            heap.resize(size);

            for (int i = 0; i < size; i++) {
                cout << "Enter element no. #" << (i + 1) << " : ";
                cin >> heap[i];
            }
            buildHeap_Max(heap);

            cout << endl << "Heap is built..." << endl << endl;

            printHeap(heap);
            break;

        case 2:
            cout << "Enter the value to be inserted: ";
            cin >> data;
            insertNode(heap, data);

            cout << endl << "Element inserted..." << endl << endl;

            printHeap(heap);
            break;

        case 3:
            removeNode(heap);

            cout << endl << "Element removed..." << endl << endl;

            printHeap(heap);
            break;

        case 4:
            cout << endl;
            printHeap(heap);
            cout << endl;
            break;

        case 5:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid option." << endl;
            break;
        }
    } while (option != 5);

    return 0;
}
