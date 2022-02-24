#include "my-vector.hpp"

MyVector::MyVector() {
  arrSize = 0;
  capacity = 10;
  array = new int[capacity];
  for (int i = 0; i < arrSize; i++)
    array[i] = 0;
}

MyVector::MyVector(int size) {
  arrSize = size;
  capacity = 2 * size;
  array = new int[capacity]; // memory allocation
  for (int i = 0; i < arrSize; i++)
    array[i] = 0;
}

MyVector::~MyVector() {
  if (array != nullptr)  // delete nullptr will give an error
    delete [] array;  // memory release
}

int MyVector::size() const {return arrSize;}

int & MyVector::at(int index) {
  if (index < 0 || index >= arrSize)
    throw "Out of range";  // throw exception, will terminate program if not caught
  return array[index];
}

void MyVector::push_back(int value) {
  if (arrSize + 1 >= capacity)
    reAllocate();
  array[arrSize] = value;
  arrSize++;
}

void MyVector::reAllocate() {
  capacity *= 2;
  int *newArray = new int[capacity];
  for (int i = 0; i < arrSize; i++)
    newArray[i] = array[i];
  delete [] array;
  array = newArray;
}

int MyVector::pop_back() {
  arrSize--;
  return array[arrSize];
}

void MyVector::remove(int index) {
  if (index < 0 || index >= arrSize)
    throw "Index out of range";
  for (int i = index; i < arrSize - 1; i++)
    array[i] = array[i + 1];
  arrSize--;
}