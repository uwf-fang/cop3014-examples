#include "util.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
#include <cassert>
#include <cstdlib>

using namespace std;


bool isAscending(int arr[], int size) {
  for (int i = 0; i < size - 2; ++i)
    if (arr[i] > arr[i + 1])
      return false;
  return true;
}

void printAll(int arr[], int size) {
  for (int i = 0; i < size; ++i)
    cout << arr[i] << " ";
  cout << endl;
}

int *makeRandArray(int size, int low, int high) {
  int *res = new int[size];
  for (int i = 0; i < size; ++i)
    res[i] = rand() % (high - low + 1) + low;
  return res;
}

int *duplicate(int arr[], int size) {
  int *res = new int[size];
  for (int i = 0; i < size; ++i)
    res[i] = arr[i];
  return res;
}
