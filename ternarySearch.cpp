#include <iostream>
#include <algorithm>

using namespace std;

int ternarySearch(int arr[], int size) {
    int key;
    cout << "\nEnter the key : ";
    cin >> key;
    int right, left, mid1, mid2;

    left = 0;
    right = (size - 1);

    while (left <= right) {
        mid1 = left + (right - left) / 3;
        mid2 = right - (right - left) / 3;

        if (arr[mid1] == key) {
            return mid1;
        }
        else if (arr[mid2] == key) {
            return mid2;
        }
        else if (key < arr[mid1]) {
            right = mid1 - 1;
        }
        else if (key > arr[mid2]) {
            left = mid2 + 1;
        }
        else {
            left = mid1 + 1;
            right = mid2 - 1;
        }
    }
    return -1; // Key not found
}

int main() {
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cout << "Enter the element no #" << (i + 1) << " : ";
        cin >> arr[i];
    }

    int temp;

    sort(arr, arr + size);

    cout << "Sorted Array : ";
    for (int i : arr) {
        cout << '[' << i << ']';
    }

    cout << "At index position : " << ternarySearch(arr, size);

    return 0;
}