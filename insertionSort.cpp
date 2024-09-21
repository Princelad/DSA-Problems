//
// Created by ladpr on 10-08-2024.
//
#include <iostream>

int *arr;
int size;

void selectionSort() {
  for(int i = 1; i < size; i++) {
    const int key = arr[i];
    int j = i - 1;
    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
  }
}

int main() {
  std::cout << "Enter the size of the array :";
  std::cin >> size;
  arr = new int[size];

  for(int i = 0; i < size; i++) {
    std::cout << "Enter #" << i + 1 << " element :";
    std::cin >> arr[i];
  }

  selectionSort();

  std::cout << std::endl << "Elements :";
  for(int i = 0; i < size; i++) {
    std::cout << '[' << arr[i] << "] ";
  }
  std::cout << std::endl;

  delete[] arr;

  return 0;
}