#include "my-class.hpp"

void MyClass::doubleVal() {
  value *= 2;
}

int MyClass::getDoubledValue() {
  doubleVal();
  return value;
}

// default constructor
// with initializer list to set value to 0
MyClass::MyClass(): value(0) {}

// parameterized constructor
// using initializer list
// MyClass::MyClass(int value): value(value) {}

// not using initializer list
MyClass::MyClass(int value) {
  // this->value refers to the instance variable
  // must add this-> when names conflict
  this->value = value;
}

int MyClass::getValue() const{
  return value;
}

// cannot use the initializer list because this is not a constructor
void MyClass::setValue(int value) {
  this->value = value;
}
