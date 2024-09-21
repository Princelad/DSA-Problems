//
// Created by ladpr on 10-08-2024.
//
#include <iostream>
#include <algorithm>

int *arr;
int size;

void slectionSort() {
  for(int pass = 0; pass < size - 1; pass++) {
    int min = pass;
    for(int i = pass +1; i < size; i++) {
      if(arr[min] > arr[i]) {
        min = i;
      }
    }
    if(arr[min] != arr[pass]) {
      std::swap(arr[min], arr[pass]);
    }
  }
}

int main() {
  std::cout << "Enter the size of the array :";
  std:: cin >> size;
  arr = new int[size];

  for (int i = 0; i < size; i++) {
    std::cout << "Enter #" << i + 1 << " element :";
    std::cin >> arr[i];
  }

  slectionSort();

  std::cout << std::endl << "Elements :";
  for (int i = 0; i < size; i++) {
    std::cout << "[" << arr[i] << "]";
  }
  std::cout << std::endl;

  delete[] arr;

  return 0;
}
