#include <iostream>

using namespace std;

int isSpecial(int arr[], int size) {
    int count = 0;
    for(int x = 0; x <= size; x++) {
        count = 0;
        for(int j = 0; j < size; j++) {
            if(arr[j] >= x) {
                count++;
            }
        }
        if(x == count) {
            return x;
        }
    }
    return -1;
}

int isSpecialBinary(int arr[], int size) {
    int left = 0, mid = 0, count = 0;
    int right = size;
    while(left <= right) {
        count = 0;
        mid = (right + left)/2;

        for(int i = 0; i < size; i++) {
            if(arr[i] >= mid) {
                count++;
            }
        }

        if(mid == count) {
            return mid;
        }
        else if(mid < count) {
            left = mid + 1;
        }
        else {
            right = mid -1;
        }
    }
    return -1;
}

int main() {
    int size,temp;
    cin >> size;
    int arr[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }

    cout << "Output : " << isSpecial(arr, size) << endl; 
    cout << "Output : " << isSpecialBinary(arr, size) << endl; 

    return 0;
}