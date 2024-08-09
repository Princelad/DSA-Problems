#include <iostream>

using namespace std;

void countSort(int arr[], int n, int exp)
{
    int count[10] = { 0 };
    // maximum array of one's 10th or 100th place will be alwasy 10
    //  Store the count of each digit in the count array

    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / exp) % 10]++;
    }

    // Modify the count array to store the actual position of each digit in the sorted array

    for (int i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // Create a temporary array to store the sorted array
    int temp[n];
    // Build the sorted array 
    for (int i = n - 1; i >= 0; i--)
    {
        temp[count[(arr[i] / exp) % 10] - 1] = arr[i]; // the sorting logic is to
        count[(arr[i] / exp) % 10]--;
    }
    // Copy the sorted array back to the original array
    for (int i = 0; i < n; i++)
    {
        arr[i] = temp[i];
    }
}

void radixsort(int arr[], int n)
{
    float max = arr[0]; // Find the maximum element in the array
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i]; // Find the maximum element in the array
        }
    }

    // Perform counting sort for each digit place
    for (int exp = 1; max / exp > 0; exp *= 10)
    {
        countSort(arr, n, exp);
        // cout << "hi";
    }
}


int main()
{
    int n;
    cout << "Enter the number of elements in the array: ";
    int arr[n];
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cout << "Enter the element " << i + 1 << ": ";
        cin >> arr[i];
    }
    radixsort(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}