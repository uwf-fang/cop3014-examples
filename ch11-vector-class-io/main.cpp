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

  return EXIT_SUCCESS;
}
