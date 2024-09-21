#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int size;
    cout << "Enter the size of the array : ";
    cin >> size;

    int arr[size];

    for(int i = 0; i < size; i++) {
        cout << "Enter the element no. #" << (i + 1) << " : "; 
        cin >> arr[i];
    }

    int x = -1, y = -1;

    for(int i = 0; i < size - 1; i++) {
        if(arr[i] > arr[i + 1]) {
            if(x == -1) {
                x = i;
            } else {
                y = i + 1;
                break;
            }
        }
    }

    if(y == -1) {
        y = x + 1;
    }

    swap(arr[x], arr[y]);

    cout << "Output : ";
    for(int i : arr) {
        cout << '[' << i << ']';
    }
    
    return 0;
}