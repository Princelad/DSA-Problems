#include <iostream>

using namespace std;

int binarySearch(int arr[], int size) {
    int key;
    cin >> key;
    int left, right, mid;

    left = 0;
    right = (size - 1);

    while (left <= right) {
        mid = (left + right) / 2;

        if (arr[mid] == key) {
            return mid;
        }
        else if (arr[mid] > key) {
            right = (mid - 1);
        }
        else {
            left = (mid + 1);
        }

    }

    return -1;
}

int main() {
    int size;
    cin >> size;

    int arr[size];

    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int temp;

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    cout << binarySearch(arr, size);

    return 0;
}