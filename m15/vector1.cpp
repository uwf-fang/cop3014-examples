#include <iostream>
#include <vector>
#include <string>
#include <cassert>

using namespace std;

double avg(const vector<int> &v) {
  int sum;
  for (int i = 0; i < v.size(); i++)
    sum += v.at(0);
  return static_cast<double>(sum) / v.size();
}

void absolute(vector<int> &v) {
  for (int i = 0; i < v.size(); i++)
    if (v.at(i) < 0)
      v.at(i) *= -1;  // v.at(i) = -v.at(i);
}

int main() {
  vector<int> v1;
  vector<int> v2;

  v1 = {1, 3, 5};
  v2 = v1;
  v1.at(0) = 0;

  cout << avg(v1);

  return 0;
}