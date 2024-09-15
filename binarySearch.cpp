#include <iostream>
#include <algorithm>

using namespace std;

int binarySearch(int arr[], int size, int key) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key) {
            return mid;
        } else if (arr[mid] > key) {
            right = mid - 1;
        } else {
            left = mid + 1;
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

    sort(arr, arr + size);

    cout << "\nThe key is at the index " << binarySearch(arr, size, key) << " of the array.";

    return 0;
}