#include <iostream>
#include <string>

using namespace std;

class State {
 private:
  string name;
 public:
  State();
  State(const string &name);
  string getName();
};

int main() {
  State *states1; // 1d array of object
  // State state[];  // 1d array of object

  states1 = new State[100];
  for (int i = 0; i < 100; i++)
    states1[i] = State("Alabama");  // make a temporary object (rvalue) and assign, = should be overloaded if State class has dynamic date
  cout << states1[0].getName();
  delete [] states1;

  State **states2;  // 1d array of pointers to the state object
  // State states[][]; // 2d array of object, logically correct
  // State *states[];  // 1d array of pointers to the state object

  states2 = new State *[100];
  for (int i = 0; i < 100; i++)
    states2[i] = new State("Alabama");

  cout << states2[0]->getName();

  for (int i = 0; i < 100; i++)
    delete states2[i];
  delete [] states2;
}