#include "util.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// sorting functions
void insertionSort(int *arr, int size);

// function to find the index of the minimum value
int argMin(int *arr, int start, int end);
void selectionSort(int *arr, int size);

// testing functions
void testArgMin();
void testInsertSort();
void testSelectSort();

void insertionSort(int *arr, int size) {
  for (int i = 1; i < size; ++i)
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; --j) {
      // may use swap(arr[j], arr[j - 1]);
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
    }
}

int argMin(int *arr, int start, int end) {
  // Method 1: set currMin to INT_MAX and start from index 0
  // Method 2: set currMin to arr[start] and start from index 1, must check if
  // the array is empty

  int currMin = INT_MAX;
  int location = 0;
  for (int i = start; i <= end; ++i)
    if (arr[i] < currMin) {
      currMin = arr[i];
      location = i;
    }
  return location;
}

void selectionSort(int *arr, int size) {
  // iterate through the index you are going swap with the minimum value
  for (int i = 0; i <= size - 2; ++i) {
    // find the location of the minimal value
    int location = argMin(arr, i, size - 1);
    // may use swap(arr[i], arr[location])
    int temp = arr[i];
    arr[i] = arr[location];
    arr[location] = temp;
  }
}

void testArgMin() {
  int size = 5;
  int *arr = new int[size]{4, 5, 2, 1, 3};

  cout << "Testing argMin function\n";
  assert(argMin(arr, 0, size - 1) == 3);
  cout << "Tests passed\n";
  delete [] arr;
}

void testSelectSort() {
  int size = 5;
  int *arr = makeRandArray(size, 0, 10);

  cout << "Testing selection sort\n";
  printAll(arr, size);
  assert(!isAscending(arr, size));
  selectionSort(arr, size);
  assert(isAscending(arr, size));
  cout << "Tests passed\n";
  delete [] arr;
}

void testInsertSort() {
  int size = 5;
  int *arr = makeRandArray(size, 0, 10);

  cout << "Testing insertion sort\n";
  printAll(arr, size);
  assert(!isAscending(arr, size));
  insertionSort(arr, size);
  assert(isAscending(arr, size));
  cout << "Tests passed\n";
  delete [] arr;
}


int main() {
  testArgMin();
  testSelectSort();
  testInsertSort();
  return EXIT_SUCCESS;
}