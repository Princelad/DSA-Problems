#include <iostream>

using namespace std;

int ternarySearch(int arr[], int size) {
    int key;
    cin >> key;
    int right, left, mid1, mid2;

    left = 0;
    right = (size - 1);

    while(left <= right) {
        mid2 = (left+(right - left))/3;
        mid1 = (right+(left - right))/3;

        if(arr[mid1] == key) {
            return mid1;
        } 
        else if(arr[mid2] == key) {
            return mid2;
        }
        else if(arr[mid1] > key) {
            right = mid1 - 1;
        }
        else if(arr[mid1] < key && arr[mid2] > key) {
            left = mid1 + 1;
            right = mid2 - 1;
        }
        else{
            left =  mid1 + 1;
        }
    }
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

    cout << ternarySearch(arr, size);

    
    return 0;
}