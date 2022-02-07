/**
 * Driver
 */
#include "student-group.hpp"
#include <iostream>
using namespace std;

int main() {
  StudentGroup group("students.txt");
  group.saveFile("output.txt");
}
