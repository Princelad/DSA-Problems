#include <iostream>

using namespace std;

int getIndex(int arr[rows][columns]) {
    int rLeft = 0, cLeft = 0, rMid, cMid;
    int rRight = rows - 1;
    int cRight = columns - 1;

    while(rLeft < rRight) {
        while(cLeft < cRight) {
            
        }
    }
    return -1;
}

int main() {
    int rows, columns;
    cin  >> rows >> columns;

    int arr[rows][columns] = {0};

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < columns; j++) {
            cin >> arr[i][j];
        }
    }

    cout << getIndex(arr);
    
    return 0;
}