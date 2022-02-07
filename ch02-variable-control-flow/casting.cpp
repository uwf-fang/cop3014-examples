#include <iostream>
#include <iomanip>

using namespace std;

int main() {

  // case conversion
  char ch1 = 'o';
  char upperCh1;
  upperCh1 = ch1 - ('a' - 'A');

  // average w/o losing precision
  double avg;
  int sum = 100, count = 12;
  // avg = sum / count; // wrong, get 8, lose precision
  // method 1
  avg = sum;
  avg /= count;
  // method 2
  avg = static_cast<double>(sum) / count;

  // round 3.14159 to 3.140000
  double pi = 3.14159;
  // cout << fixed << setprecision(2) << pi;  // wrong! pi has not changed!
  pi = static_cast<int>(pi * 100) / 100.0;

}