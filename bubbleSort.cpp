//
// Created by ladpr on 10-08-2024.
//
#include <algorithm>
#include <iostream>

int *arr;
int size;

void bubbleSort() {
  for (int i = 0; i < size - 1; i++) {
    bool flag = false;
    for (int j = 0; j < size - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) {
        std::swap(arr[j], arr[j + 1]);
        flag = true;
      }
    }
    if (!flag) {
      break;
    }
  }
}

int main() {
  std::cout << "Enter the size of the array :";
  std::cin >> size;
  arr = new int[size];

  for (int i = 0; i < size; i++) {
    std::cout << "Enter the #" << i + 1 << " element :";
    std::cin >> arr[i];
  }

  bubbleSort();

  std::cout << std::endl << "Elements :";
  for (int i = 0; i < size; i++) {
    std::cout << "[" << arr[i] << "]";
  }
  std::cout << std::endl;

  delete[] arr;
  return 0;
}
