#include "my-vector.hpp"
#include <iostream>
#include <cassert>

using namespace std;

void testVector();

void testVector() {
  MyVector v1;
  assert(v1.size() == 0);

  MyVector v(10);
  assert(v.size() == 10);

  cout << "test at()" << endl;
  assert(v.at(0) == 0);
  v.at(0) = 10;
  assert(v.at(0) == 10);

  cout << "test push_back()" << endl;
  v.push_back(20);
  assert(v.size() == 11);
  assert(v.at(10) == 20);

  cout << "test pop_back()" << endl;
  assert(v.pop_back() == 20);
  assert(v.size() == 10);

  // test remove
  cout << "test remove()" << endl;
  v.remove(5);
  assert(v.size() == 9);
}

int main() {
  testVector();
  return EXIT_SUCCESS;
}