#include "destructor.hpp"
#include <iostream>
using namespace std;

int main() {
  MyVector vec(10);  // local object, in stack
  MyVector *vecPtr = new MyVector(10);  // dynamic object, in heap

  cout << "vec size " << vec.getSize() << endl;
  cout << "vecPtr size " << vecPtr->getSize() << endl;

  delete vecPtr;  // destructor will be called

  return 0;  // destructor for vec will be called upon exiting the program
}