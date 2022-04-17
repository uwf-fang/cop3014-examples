#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

double avg(const vector<int> &v);
void absolute(vector<int> &v);
vector<int> positiveOnly(vector<int> v);
void testVecBasics();
void testAlgorithms();

void testVecBasics() {
  // vector v1; invalid, vector is not a type, vector<int> is

  // initialization, constructor call
  vector<int> v1{1, 2, 3, 4, 5};
  vector<int> v2 = {1, 2, 3, 4, 5};
  vector<int> v3(5);      // 5 zeros
  vector<int> v4(5, 10);  // 5 number 10s
  vector<int> v5(v1);     // duplicate v1

  cout << "Start testing vector basics...\n";

  assert(v1.size() == 5);
  assert(v2.size() == 5);
  assert(v1 == v2);
  assert(v3.size() == 5);
  assert(v1 == v5);

  // Assignment
  v1 = {1, 3, 5};
  assert(v1.size() == 3);
  v1 = v2;
  assert(v1.size() == 5);

  // at() vs []
  // cout << v1.at(6) << endl;  // out of range error
  // cout << v1[6] << endl;     // will run! Dangerous! Undefined value or memory problem

  // push pop
  v1.push_back(6);
  assert(v1.size() == 6);
  v1.pop_back();              // the last 6 is removed
  assert(v1.size() == 5);
  assert(v1.back() == 5);
  // cout << v1.pop_back() << endl; // error, pop_back() is a void method
  cout << "Tests passed\n";
}

// aggregate algorithms
double avg(const vector<int> &v) {
  int sum;
  for (int i = 0; i < v.size(); i++) sum += v.at(0);
  return static_cast<double>(sum) / v.size();
}

// map algorithm, in-place
void absolute(vector<int> &v) {
  for (int i = 0; i < v.size(); i++)
    if (v.at(i) < 0) v.at(i) *= -1;  // v.at(i) = -v.at(i);
}

// filter algorithm, out-of-place
vector<int> positiveOnly(vector<int> v) {
  vector<int> result;
  for (int i = 0; i < v.size(); i++)
    if (v.at(i) > 0)
      result.push_back(v.at(i));
  return result;
}


int main() {
  testVecBasics();

  return EXIT_SUCCESS;
}