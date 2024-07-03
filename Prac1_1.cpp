#include <iostream>

using namespace std;

void getPairs(int arr[], int s) {
    int num, count = 0;
    cin >> num;
    int flag[s] = {0};

    for(int i = 0;i < s; i++) {
        for(int j = i+1; j < s; j++) {
            if((arr[i] + arr[j]) % num == 0 && flag[i] == 0 && flag[j] == 0) {
                printf("[%d, %d]\n", arr[i], arr[j]);
                flag[i] = flag[j] = 1;
            }
        }
    }
}

int main() {
    int size;

    cin >> size;

    if(size % 2 == 0) {
        int arr[size];

        for(int i = 0; i < size; i++) {
            cin >> arr[i];
        }
        getPairs(arr, size);
    } else {
        return 1;
    }
    
    return 0;
}
