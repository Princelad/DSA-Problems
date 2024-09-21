#include <iostream>

using namespace std;

void rearrangeArray(int array[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        if (i % 2 == 0) {
            if (array[i] > array[i + 1]) {
                swap(array[i], array[i + 1]);
            }
        }
        else {
            if (array[i] < array[i + 1]) {
                swap(array[i], array[i + 1]);
            }
        }
    }
}

int main() {
    int cases;
    cout << "Enter the number of cases : ";
    cin >> cases;


    while (cases--) {
        int size;
        cout << "Enter the size : ";
        cin >> size;

        int array[size];
        for (int i = 0; i < size; ++i) {
            cout << "Enter the element no. #" << (i + 1) << " : ";
            cin >> array[i];
        }

        rearrangeArray(array, size);

        cout << "Output : ";
        for (int i : array) {
            cout << '[' << i << ']';
        }
        cout << endl;
    }
    return 0;
}
