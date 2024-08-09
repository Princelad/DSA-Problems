#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int size;
    cin >> size;

    int arr[size];

    int key;

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    for(int j = 0; j < size; j++) {
        if(arr[j] > arr[j + 1]) {
            key = j;
            break;
        }
    } 
 
    int min = key;

    for(int k = key + 1; k < size; k++) {
        if(arr[min] > arr[k]) {
            min = k;
        }
    }

    swap(arr[key], arr[min]); 

    for(int i = 0; i < size; i++) {
        cout << arr[i];
    }
    
    return 0;
}