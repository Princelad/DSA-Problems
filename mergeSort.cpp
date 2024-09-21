#include <iostream>

int *arr;
int size;

void merge(const int left, const int mid, const int right) {
  int i = left, j = mid + 1, L = 0;
  const auto temp = new int[right - left + 1];

  while (i <= mid && j <= right) {
    if (arr[i] <= arr[j]) {
      temp[L] = arr[i];
      i++;
    } else {
      temp[L] = arr[j];
      j++;
    }
    L++;
  }

  while (i <= mid) {
    temp[L] = arr[i];
    i++;
    L++;
  }

  while (j <= right) {
    temp[L] = arr[j];
    j++;
    L++;
  }

  for (int k = 0; k < (right - left + 1); k++) {
    arr[left + k] = temp[k];
  }

  delete[] temp;  // Clean up allocated memory
}

void mergeSort(const int left, const int right) {
  if (left < right) {
    const int mid = (left + right) >> 1;
    mergeSort(left, mid);
    mergeSort(mid + 1, right);
    merge(left, mid, right);
  }
}

int main() {
  std::cout << "Enter the size of the array:";
  std::cin >> size;
  arr = new int[size];

  for (int i = 0; i < size; i++) {
    std::cout << "Enter #" << i + 1 << " element:";
    std::cin >> arr[i];
  }

  mergeSort(0, size - 1);

  std::cout << std::endl << "Sorted Elements:";
  for (int i = 0; i < size; i++) {
    std::cout << "[" << arr[i] << "] ";
  }
  std::cout << std::endl;

  delete[] arr;  // Clean up allocated memory

  return 0;
}
