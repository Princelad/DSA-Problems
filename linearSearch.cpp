#include <iostream>

using namespace std;

int linearSearch(int arr[], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    int size;
    cout << "\nEnter the size of the array : ";
    cin >> size;

    int arr[size];

    cout << endl;
    for (int i = 0; i < size; i++) {
        cout << "Enter the element no. " << (i + 1) << " : ";
        cin >> arr[i];
    }

    int key;
    cout << "\nEnter the key to search : ";
    cin >> key;

    cout << "\nThe key is at the index " << linearSearch(arr, size, key) << " of the array.";

    return 0;
}