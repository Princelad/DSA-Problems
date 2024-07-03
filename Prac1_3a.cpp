#include <iostream>

using namespace std;

int linearSearch(int arr[], int size) {
    int key;
    cin >> key;

    for(int i = 0; i < size; i++) {
        if(arr[i] == key) {
            return i;
        }
    }

    return (-1);
}

int main() {
    int size;
    cin >> size;

    int arr[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    cout << linearSearch(arr, size);

    return 0;
}