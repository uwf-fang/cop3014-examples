#include <iostream>
#include <string>
using namespace std;

// check if a string consists of all digits
bool isAllDigit(string userInput) {
  for (int i = 0; i < userInput.length(); i++)
    if (userInput.at(i) < '0' || userInput.at(i) > '9')
      return false;
  return true;
}

// Input with validation


// ======== No error message ========

// while loop
// redundant first round code
string getPhoneNumInput1() {
  string userInput;
  cout << "Please give a phone number (10 digit only, no symbol): ";
  cin >> userInput;
  while (userInput.length() != 10 || !isAllDigit(userInput)) {
    cout << "Please give a phone number (10 digit only, no symbol): ";
    cin >> userInput;
  }
  return userInput;
}

// a better fit to the problem is do-while loop
string getPhoneNumInput2() {
  string userInput;
  do {
    cout << "Please give a phone number (10 digit only, no symbol): ";
    cin >> userInput;
  } while (userInput.length() != 10 || !isAllDigit(userInput));
  return userInput;
}

// while true loop
// clean implementation
string getPhoneNumInput3() {
  string userInput;
  while (true) {
    cout << "Please give a phone number (10 digit only, no symbol): ";
    cin >> userInput;
    if (userInput.length() == 10 && isAllDigit(userInput))
      break;
  }
  return userInput;
}

// ======== With error message ========

// while true loop
// best with error message
string getPhoneNumInput4() {
  string userInput;
  while (true) {
    cout << "Please give a phone number (10 digit only, no symbol): ";
    cin >> userInput;
    if (userInput.length() == 10 && isAllDigit(userInput))
      break;
    cout << "Your input is either not 10 chars long or not all digit\n";
  }
  return userInput;
}

// do-while based
// redundant condition check
string getPhoneNumInput5() {
  string userInput;
  do {
    cout << "Please give a phone number (10 digit only, no symbol): ";
    cin >> userInput;
    if (userInput.length() != 10 || !isAllDigit(userInput))
      cout << "Your input is either not 10 chars long or not all digit\n";
  } while (userInput.length() != 10 || !isAllDigit(userInput));
  return userInput;
}

// while based
// more redundant logics
string getPhoneNumInput6() {
  string userInput;
  cout << "Please give a phone number (10 digit only, no symbol): ";
  cin >> userInput;
  if (userInput.length() != 10 || !isAllDigit(userInput))
    cout << "Your input is either not 10 chars long or not all digit\n";
  while (userInput.length() != 10 || !isAllDigit(userInput)) {
    cout << "Please give a phone number (10 digit only, no symbol): ";
    cin >> userInput;
    if (userInput.length() != 10 || !isAllDigit(userInput))
      cout << "Your input is either not 10 chars long or not all digit\n";
  }
  return userInput;
}

// for loop, for fun
string getPhoneNumInput7() {
  string userInput;
  for (;true;) {
    cout << "Please give a phone number (10 digit only, no symbol): ";
    cin >> userInput;
    if (userInput.length() == 10 && isAllDigit(userInput))
      break;
    else
      cout << "Your input is either not 10 chars long or not all digit\n";
  }
  return userInput;
}

void testAllDigit() {
    if (isAllDigit("abc"))
    cout << "abc as input is all digit\n";
  else
    cout << "abc as input is not all digit\n";
 if (isAllDigit("123"))
    cout << "123 as input is all digit\n";
  else
    cout << "123 as input is not all digit\n";
}

int main()
{
  string userInput;

  userInput = getPhoneNumInput5();

  cout << "The phone number " << userInput << " is valid!\n";

  // testAllDigit();
  return 0;
}
