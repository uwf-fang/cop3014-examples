#include <iostream>
#include <string>
using namespace std;


int main() {

  // implicit triggering of constructor same as the next example
  string myStr = "abc";
  string myStr1("abc");
  // alt approach, preferred after C++11 standard
  // string myStr1{"abc"};

  string myStr2(10, 'a');  // repetition/fill constructor
  // string myStr2{10, 'a'};
  // curly braces will give different result as "\10a"

  cout << myStr.at(0) << endl;
  myStr.at(0) = 'b';  // C++ only syntax, myStr become "bbc"

  cout << myStr.length() << endl;
  cout << myStr.size() << endl;
  myStr.append(myStr1);  // append myStr1 to myStr, can be achieved using + too
  myStr += myStr1;

  return EXIT_SUCCESS;
}