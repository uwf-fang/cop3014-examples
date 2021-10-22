#include <iostream>
using namespace std;

int main() {
  int a = 10;
  int b = 100;

  // the type is "int &"
  // reference variable can only be initialized to refer to another variable
  // any later assignments will be redirected to the referred variable
  int &myRef1 = a; // initialization, myRef1 is now an alias of a
  myRef1 = b; // second assignment, myRef1 will not refer to b, it is same as a = b; value of a become 10

  cout << "Value of a: " << a << endl;
  cout << "Value of b: " << b << endl;
  cout << "Value of myRef1: " << myRef1 << endl;

  return EXIT_SUCCESS;
}