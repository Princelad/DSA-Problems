//
// Created by ladpr on 10-08-2024.
//
#include <iostream>

int* arr;
int size;

void countSort(const int exp) {
  int count[10] = { 0 };

  for (int i = 0; i < size; i++) {
    count[(arr[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  const auto temp = new int[size];

  for (int i = size - 1; i >= 0; i--) {
    temp[count[(arr[i] / exp) % 10] - 1] = arr[i];
    count[(arr[i] / exp) % 10]--;
  }

  for (int i = 0; i < size; i++) {
    arr[i] = temp[i];
  }

  delete[] temp;
}

void radixSort() {
  int max = arr[0];

  for (int i = 1; i < size; i++) {
    if (arr[i] > max) {
      max = arr[i];
    }
  }

  for (int exp = 1; max / exp > 0; exp *= 10) {
    countSort(exp);
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

  radixSort();

  std::cout << std::endl << "Sorted Elements:";
  for (int i = 0; i < size; i++) {
    std::cout << "[" << arr[i] << "] ";
  }
  std::cout << std::endl;

  delete[] arr;

  return 0;
}
