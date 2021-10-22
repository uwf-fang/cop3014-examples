#include "destructor.hpp"

MyVector::MyVector() {
  size = 0;
  capacity = 0;
  array = nullptr;
}

MyVector::MyVector(int size) {
  this->size = size;
  capacity = 2 * size;
  array = new int[size]; // memory allocation
}

int MyVector::getSize() {return size;}

int MyVector::getVal(int index) {
  if (index < 0 || index >= size)
    return -1;
  return array[index];
}

MyVector::~MyVector() {
  if (array != nullptr)  // delete nullptr will give an error
    delete [] array;  // memory release
}
