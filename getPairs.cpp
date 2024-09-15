# include <iostream>

using namespace std;

void getPairs(int arr[], int size, int key);

int main() {
    int size;
    cout << "Enter the size of the array :";
    cin >> size;

    if (size % 2 == 0) {

        int arr[size];

        cout << endl;
        for (int i = 0; i < size; i++) {
            cout << "Enter element no. " << (i + 1) << " :";
            cin >> arr[i];
        }

        int key;

        cout << "\nEnter the Key :";
        cin >> key;

        getPairs(arr, size, key);
    }
    else {
        cout << "\nPairs can't be formed." << endl;
    }

    return 0;
}

void getPairs(int arr[], int size, int key) {
    bool flags[size];
    int count;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (flags[i] != 1 && flags[j] != 1 && i != j && (arr[i] + arr[j]) % key == 0) {
                flags[i] = flags[j] = 1;
                count++;
            }
        }
    }

    if (count == (size / 2)) {
        cout << "\nPairs can be formed." << endl;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (flags[i] != 1 && flags[j] != 1 && i != j && (arr[i] + arr[j]) % key == 0) {
                    cout << '(' << arr[i] << ',' << arr[j] << ')' << endl;
                }
            }
        }
    }
    else {
        cout << "\nPairs cann't be formed." << endl;
    }
}
