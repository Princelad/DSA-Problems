#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

void printArr(int arr[], int size) {
    cout << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSort(int arr[], int size) {
    bool flag;
    
    for (int i = 0; i < size - 1; i++) {
        flag = false;
        for(int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(!flag) {
            break;
        }
    }

    printArr(arr, size);
}

void selectionSort(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        int minIndex = i;
        for(int j = minIndex + 1; j < size; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            swap(arr[minIndex], arr[i]);
        }
    }
    
    printArr(arr, size);
}

void insertionSort(int arr[], int size) {
    for(int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
    
    printArr(arr, size);
}

void countSort(int arr[], int size) {
    int maxNumber = *max_element(arr, arr + size);
    int result[size] = {0};
    int count[maxNumber + 1] = {0};

    for(int i = 0; i < size; i++) {
        count[arr[i]]++;
    }

    for(int i = 1; i <= maxNumber; i++) {
        count[i] += count[i-1];
    }

    for(int i = size - 1; i >= 0; i--) {
        result[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for(int i = 0; i < size; i++) {
        arr[i] = result[i];
    }

    printArr(arr, size);
}

void radixSort(int arr[], int size) {
    int max = *max_element(arr, arr + size);

    for(int exp = 1; max / exp > 0; exp *= 10) {
        int output[size];
        int count[10] = {0};

        for(int i = 0; i < size; i++)
            count[(arr[i] / exp) % 10]++;

        for(int i = 1; i < 10; i++)
            count[i] += count[i - 1];

        for(int i = size - 1; i >= 0; i--) {
            output[count[(arr[i] / exp) % 10] - 1] = arr[i];
            count[(arr[i] / exp) % 10]--;
        }

        for(int i = 0; i < size; i++)
            arr[i] = output[i];
    }

    printArr(arr, size);
}

int main() {
    int size;

    cout << "\nEnter the size of the array: ";
    cin >> size;

    int arr[size];

    for(int i = 0; i < size; i++) {
        cout << "Enter the element no. " << i + 1 << " : ";
        cin >> arr[i];
    }

    int choice;
    do {
        cout << "\nChoose a sorting algorithm:" << endl;
        cout << "1. Bubble Sort" << endl;
        cout << "2. Selection Sort" << endl;
        cout << "3. Insertion Sort" << endl;
        cout << "4. Count Sort" << endl;
        cout << "5. Radix Sort" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;

        switch(choice) {
            case 1:
                bubbleSort(arr, size);
                break;
            case 2:
                selectionSort(arr, size);
                break;
            case 3:
                insertionSort(arr, size);
                break;
            case 4:
                countSort(arr, size);
                break;
            case 5:
                radixSort(arr, size);
                break;
            case 6:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 6);

    return 0;
}