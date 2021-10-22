#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int key);
void testLinearSearch();
void testBinarySearch();
int binarySearch(int arr[], int size, int key);

int main() {
  // testLinearSearch();
  testBinarySearch();
  return EXIT_SUCCESS;
}

int binarySearch(int arr[], int size, int key) {
  // binary search
  // define left, right and middle
  // when left is not converging with right and the middle element is same as key
      // if key > middle change the left to the value of middle
      // else change the right change the right to the value of middle
      // calculate the new middle

  int left = 0;
  int right = size - 1;
  int middle = 0;
  while (left < right) {
    middle = (left + right) / 2;
    if (arr[middle] == key)
      return middle;
    else if (arr[middle] > key)
      right = middle;
    else
      left = middle;
  }

  return -1;
}

void testBinarySearch() {
  int values[] = {1, 2, 3, 4 ,5, 6, 7, 8, 9, 10};
  cout << "The value 3 is at the index " << binarySearch(values, 10, 3) << endl;
}

void testLinearSearch() {
  int values[] = {1, 2, 3, 4 ,7, 6, 5, 9, 8, 0};
  cout << "The value 6 is at the index " << linearSearch(values, 10, 6) << endl;
}

int linearSearch(int arr[], int size, int key) {
  // for element in array from left to right
      // if find a match, report the index

  for (int i = 0; i < size; i++) {
    if (key == arr[i])
      return i;
  }

  // report -1

  return -1;
}

int linearSearchLast(int arr[], int size, int key) {
  // for element in array from right to left
      // if find a match, report the index
  for (int i = size - 1; i >= 0; i--)
    if (key == arr[i])
      return i;

  return -1;
}

int linearSearchLast1(int arr[], int size, int key) {
  // for element in array from right to left
      // if find a match, report the index
  for (int i = 0; i < size; i++)
    if (key == arr[size - 1 - i])
      return i;

  return -1;
}

// run size times always, not short cut
int linearSearchLast2(int arr[], int size, int key) {
  // for element in array from left to right
      // if find a match, store the index
  int index = -1;
  for (int i = 0; i < size; i++)
    if (key == arr[i])
      index = i;

  return index;
}
