#include <iostream>
#include <algorithm>

using namespace std;

void printArr(int arr[],int size) {
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

void bubbleSort(int arr[], int size) {

    int passes, temp;
    bool flag;

    // cin >> passes;
    
    for (int i = 0; i < size; i++) {
        // flag = false;
        for(int j = i + 1; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                // temp = arr[i];
                // arr[i] = arr[j];
                // arr[j] = temp;
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        // if(!flag) {
        //     break;
        // }
    }

    printArr(arr, size);
}

void selectionSort(int arr[], int size) {
    int temp;
    
    for(int i = 0; i < size; i++) {
        int minIndex = i;
        for(int j = minIndex + 1; j < size; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
    
    printArr(arr, size);

}

void insertionSort(int arr[], int size) {
    int key, j;
    for(int i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while(j > -1 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    
    printArr(arr, size);
}

void countSort(int arr[], int size) {
    int maxNumber;
    cin >> maxNumber;
    int result[size] = {0};

    int arr2[maxNumber + 1] = {0};

    for(int i = 0; i < size; i++) {
        arr2[arr[i]]++;
    }

    for(int i = 0; i < size; i++) {
        arr2[i] = arr2[i] + arr2[i-1];
    }

    // if(arr2[size - 1] != size) {
    //     exit(-1);
    // }

    for(int i = 0; i < size; i++) {
        result[arr2[arr[i]] - 1] = arr[i];
        arr2[arr[i]]--;
    }

    printArr(result, size);
}

void radixSort(int arr[], int size) {
    int max;
    cin >> max;

    int temp[size];

    for(;;) {

    }

    for(int pos = 1; (max/pos) > 0; pos = pos * 10) {
        
    }
}

int main() {
    int size;

    cin >> size;

    int arr[size];

    for(int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    // bubbleSort(arr, size);
    // selectionSort(arr, size);
    // insertionSort(arr, size);
    // countSort(arr, size);
    radixSort(arr,size);

    return 0;
}