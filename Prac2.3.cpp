#include <iostream>
using namespace std;

void rearrangeArray(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // If the index is even
        if (i % 2 == 0) {
            // If the current element is greater than the next element, swap them
            if (arr[i] > arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        } else { // If the index is odd
            // If the current element is less than the next element, swap them
            if (arr[i] < arr[i + 1]) {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
}

int main() {
    int T; // Number of test cases
    cin >> T;

    // Process each test case
    while (T--) {
        int N; // Size of the array
        cin >> N;

        int A[N]; // Declare the array
        // Input the elements of the array
        for (int i = 0; i < N; ++i) {
            cin >> A[i];
        }

        // Call the function to rearrange the array
        rearrangeArray(A, N);

        // Output the rearranged array
        for (int i = 0; i < N; ++i) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
