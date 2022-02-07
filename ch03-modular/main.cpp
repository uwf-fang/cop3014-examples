#include "threeintsfcts.hpp"
#include <iostream>

using namespace std;

// Normally lots of other code here

int main() {

  cout << "Testing three int sum and three int avg function " <<
      "on 5, 10, 20" << endl;
  cout << ThreeIntsSum(5, 10, 20) << endl;
  cout << ThreeIntsAvg(5, 10, 20) << endl;

  return EXIT_SUCCESS;
}