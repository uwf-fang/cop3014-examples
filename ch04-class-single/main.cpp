// Example of a class and main function in a single cpp file
#include <iostream>

using namespace std;

class MyClass {
 private:
  int value;
  void doubleVal();
 public:
  MyClass()=default;  // default definition
  MyClass(int value): value(value) {}  // inline
  int getValue() const {return value;}  // inline
  void setValue(int value) {this->value = value;}  // inline
  int getDoubledValue();
};

// separate definition
int MyClass::getDoubledValue() {
  doubleVal();
  return value;
}

int main() {
  // trigger the default constructor
  MyClass obj1;
  cout << obj1.getValue() << endl;  // get 0

  // trigger the parameterized constructor
  MyClass obj2(10);
  // alternatives
  // MyClass obj2{10};  // since c++11
  // MyClass obj2 = 10;
  cout << obj2.getValue() << endl;  // get 10

  MyClass *ptr1;
  ptr1 = new MyClass(15);  // use new to call the constructor
  cout << ptr1->getValue() << endl;  // get 15
  cout << (*ptr1).getValue() << endl;  // get 15
}
