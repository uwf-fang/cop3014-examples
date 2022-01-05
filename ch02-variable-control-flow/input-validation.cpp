/**
 * Input validation
 */

#include <iostream>
using namespace std;

int main() {
  int input;

  // ==== without error messages ====

  // do while loop
  do {
    cout << "Please input a positive integer\n";
    cin >> input;
  } while (input <= 0);
  cout << "You have input " << input << endl;

  // while loop
  // must set initial invalid value
  input = 0;
  while (input <= 0) {
    cout << "Please input a positive integer\n";
    cin >> input;
  }
  cout << "You have input " << input << endl;

  // ==== with error messages ====

  // do while loop
  // redundant condition check
  do {
    cout << "Please input a positive integer\n";
    cin >> input;
    if (input <= 0)
      cout << "Invalid input, try again!\n";
  } while (input <= 0);
  cout << "You have input " << input << endl;

  // while true loop
  // recommended
  while (true) {
    cout << "Please input a positive integer\n";
    cin >> input;
    if (input > 0)
      break;
    cout << "Invalid input, try again!\n";
  }
  cout << "You have input " << input << endl;

  return EXIT_SUCCESS;
}
