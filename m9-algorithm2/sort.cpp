#include <iostream>
#include <string>
using namespace std;

void insertSort(int arr[], int size) {
  for (int i = 1; i < size; i++) {
    for (int j = i; j > 0 && arr[j] < arr[j - 1]; j--) {
      int temp = arr[j];
      arr[j] = arr[j - 1];
      arr[j - 1] = temp;
    }
  }
}

int minLoc(int arr[], int size, int start) {
  int currMin = -1;
  int location = 0;
  for (int i = start; i < size; i++) {
    if (currMin == -1 || arr[i] < currMin) {
      currMin = arr[i];
      location = i;
    }
  }
  return location;
}

void selectSort(int arr[], int size) {
  // iterate through the index you are going swap with the minimal
  for (int index = 0; index <= size - 2; index++) {
    // find the location of the minimal value
    int location = minLoc(arr, size, index);
    // swap
    int temp = arr[index];
    arr[index] = arr[location];
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
  int arr[5] = {4, 5, 2, 1, 3};

  cout << minLoc(arr, size, 2) << endl;
}

void testSelectSort() {
  int size = 5;
  int arr[5] = {4, 5, 2, 1, 3};

  printAll(arr, size);
  selectSort(arr, size);
  printAll(arr, size);
}

void testInsertSort() {
  int size = 5;
  int arr[5] = {4, 5, 2, 1, 3};

  printAll(arr, size);
  insertSort(arr, size);
  printAll(arr, size);
}


int main() {
  int size = 5;
  int arr[5] = {4, 5, 2, 1, 3};


  // testMinLoc();
  // testSelectSort();
  testInsertSort();
  return EXIT_SUCCESS;
}