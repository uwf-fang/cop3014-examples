/**
 * Driver
 */
#include "student-group.hpp"
#include <iostream>
using namespace std;

int main() {
  StudentGroup group;
  if (group.loadFile("students.txt"))
    cout << "File loaded from students.txt" << endl;
  if (group.saveFile("output.txt"))
    cout << "File saved to output.txt" << endl;
}
