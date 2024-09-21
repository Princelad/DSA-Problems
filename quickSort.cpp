//
// Created by ladpr on 10-08-2024.
//
#include <iostream>
#include <algorithm>

int* arr;
int size;

int Partition(const int left, const int right) {
  const int pivot = arr[right];
  int store = left;

  for (int j = left; j < right; j++) {
    if (arr[j] <= pivot) {
      std::swap(arr[j], arr[store]);
      store++;
    }
  }
  std::swap(arr[right], arr[store]);

  return store;
}

void quickSort(const int left, const int right) {
  if (left < right) {
    const int mid = Partition(left, right);
    quickSort(left, mid - 1);
    quickSort(mid + 1, right);
  }
}

int main() {
  std::cout << "Enter the size of the array :";
  std::cin >> size;
  arr = new int[size];

  for (int i = 0; i < size; i++) {
    std::cout << "Enter #" << i + 1 << " element :";
    std::cin >> arr[i];
  }

  quickSort(0, size - 1);

  std::cout << std::endl << "Elements ";
  for (int i = 0; i < size; i++) {
    std::cout << "[" << arr[i] << "] ";
  }
  std::cout << std::endl;

  delete[] arr;

  return 0;
}