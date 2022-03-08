#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cassert>

using namespace std;

// Utilities
void printAll(int arr[], int size);

// sorting functions
void insertSort(int arr[], int size);

// Find the index of the minimum value
// with start and end index specified
int minLoc(int arr[], int start, int end);
void selectSort(int arr[], int size);

// testing functions
void testMinLoc();
void testInsertSort();
void testSelectSort();

void insertSort(int arr[], int size) {
  for (int i = 1; i < size; i++)
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      // may use swap(arr[j], arr[j - 1]);
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
    }
}

int minLoc(int arr[], int start, int end) {
  // Method 1: set currMin to INT_MAX and start from index 0
  // Method 2: set currMin to arr[0] and start from index 1, must check if the
  //     array is empty
  int currMin = INT_MAX;
  int location = 0;
  for (int i = start; i <= end; i++)
    if (arr[i] < currMin) {
      currMin = arr[i];
      location = i;
    }
  return location;
}

void selectSort(int arr[], int size) {
  // iterate through the index you are going swap with the minimal
  for (int i = 0; i <= size - 2; i++) {
    // find the location of the minimal value
    int location = minLoc(arr, i, size - 1);
    // may use swap(arr[index], arr[location])
    int temp = arr[i];
    arr[i] = arr[location];
    arr[location] = temp;
  }
}

void printAll(int arr[], int size) {
  for (int i = 0; i < size; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void testMinLoc() {
  int size = 5;
  int *arr = new int[size]{4, 5, 2, 1, 3};

  cout << "Testing minLoc function\n";
  assert(minLoc(arr, 0, size - 1) == 3);
  cout << "Tests passed\n";
  delete [] arr;
}

void testSelectSort() {
  int size = 5;
  int arr[5] = {4, 5, 2, 1, 3};

  cout << "Before Sorting: ";
  printAll(arr, size);
  selectSort(arr, size);
  cout << "After Selection Sort: ";
  printAll(arr, size);
}

void testInsertSort() {
  int size = 5;
  int arr[5] = {4, 5, 2, 1, 3};

  cout << "Before Sorting: ";
  printAll(arr, size);
  insertSort(arr, size);
  cout << "After Insertion Sort: ";
  printAll(arr, size);
}


int main() {
  testMinLoc();
  testSelectSort();
  testInsertSort();
  return EXIT_SUCCESS;
}