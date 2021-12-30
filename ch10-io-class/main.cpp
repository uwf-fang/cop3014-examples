/**
 * Driver
 */
#include <iostream>
#include "student-group.hpp"
using namespace std;

int main() {
  StudentGroup group("students.txt");
  group.saveFile("output.txt");
}
