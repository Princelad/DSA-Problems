#include <iostream>

using namespace std;

int main() {
    int rows, columns, key;
    cout << "Enter the rows of the array : ";
    cin >> rows;
    cout << "Enter the columns of the array : ";
    cin >> columns;

    int arr[rows][columns];

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            cout << "Enter the element no. [" << (i + 1) << ',' << (j + 1) << "] : ";
            cin >> arr[i][j];
        }
    }

    cout << "Enter the key : ";
    cin >> key;

    bool found = false;

    for (int i = 0; i < rows; i++) {
        if (arr[i][0] <= key && (i == rows - 1 || arr[i + 1][0] > key)) {
            int left = 0, right = columns - 1, mid = 0;

            while (left <= right) {
                mid = left + (right - left) / 2;

                if (arr[i][mid] == key) {
                    cout << "At index : [" << i << ',' << mid << ']' << endl;
                    found = true;
                    break;
                } else if (arr[i][mid] > key) {
                    right = mid - 1;
                } else {
                    left = mid + 1; 
                }
            }
        }
    }

    if (!found) {
        cout << "Key not found" << endl;
    }

    return 0;
}