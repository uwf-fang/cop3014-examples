#include <iostream>
#include <string>
using namespace std;


int main() {
  string myStr = "abc";
  string myStr1("abc");

  cout << myStr.at(0) << endl;
  myStr.at(0) = 'b';  // myStr become "bbc"

  cout << myStr.length() << endl;
  cout << myStr.size() << endl;
  myStr.append(myStr1);  // append myStr1 to myStr
  myStr += myStr1;

  return EXIT_SUCCESS;
}