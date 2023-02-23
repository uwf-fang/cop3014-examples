#include "my-vector.hpp"
#include <iostream>

MyVector::MyVector() {
  arrSize = 0;
  capacity = 10;
  array = new int[capacity];
}

MyVector::MyVector(int size) {
  arrSize = size;
  capacity = 2 * size;
  array = new int[capacity];
  for (int i = 0; i < arrSize; ++i)
    array[i] = 0;
}

MyVector::~MyVector() {
  delete [] array;  // memory release
}

int MyVector::size() const {return arrSize;}

int & MyVector::at(int index) {
  if (index < 0 || index >= arrSize) {
    std::cout << "Out of range index!" << std::endl;
    exit(1);
  }
  return array[index];
}

void MyVector::push_back(int value) {
  if (arrSize >= capacity)
    reAllocate();
  array[arrSize] = value;
  ++arrSize;
}

void MyVector::reAllocate() {
  capacity *= 2;
  int *newArray = new int[capacity];
  for (int i = 0; i < arrSize; ++i)
    newArray[i] = array[i];
  delete [] array;
  array = newArray;
}

int MyVector::pop_back() {
  --arrSize;
  return array[arrSize];
}

void MyVector::remove(int index) {
  if (index < 0 || index >= arrSize) {
    std::cout << "Out of range index!" << std::endl;
    exit(1);
  }
  // move all element after one step to the left
  // i range from index to arrSize - 2
  for (int i = index; i < arrSize - 1; ++i)
    array[i] = array[i + 1];
  --arrSize;
}