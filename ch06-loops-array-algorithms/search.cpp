#include "search.hpp"

int binarySearch(int arr[], int size, int key) {

  int left = 0;
  int right = size - 1;
  int middle = 0;
  while (left <= right) {  // must include equal
    middle = (left + right) / 2;
    if (arr[middle] == key)
      return middle;
    else if (arr[middle] > key)
      right = middle - 1;
    else
      left = middle + 1;
  }
  return -1;
}

int linearSearch(int arr[], int size, int key) {
  for (int i = 0; i < size; ++i)
    if (key == arr[i])
      return i;
  return -1;
}

int linearSearchLast(int arr[], int size, int key) {
  for (int i = size - 1; i >= 0; i--)
    if (key == arr[i])
      return i;
  return -1;
}

int linearSearchLast1(int arr[], int size, int key) {
  for (int i = 0; i < size; ++i)
    if (key == arr[size - 1 - i])
      return size - 1 - i;
  return -1;
}

int linearSearchLast2(int arr[], int size, int key) {
  int index = -1;
  for (int i = 0; i < size; ++i)
    if (key == arr[i])
      index = i;
  return index;
}