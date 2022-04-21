#include "grades.hpp"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  if (argc != 2) {
    cout << "Wrong command line arguments!" << endl;
    cout << "Usage: ./grades <input csv file path>" << endl;
    return EXIT_FAILURE;
  }
  Grades grades;
  if (!grades.load(argv[1])) {
    cerr << "Cannot load file!" << endl;
    return EXIT_FAILURE;
  }
  grades.save("output.txt");
  return EXIT_SUCCESS;
}
