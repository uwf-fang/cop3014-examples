// String content parsing using istringstream
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

// Read from file until end of file or error
void fileReadTestRun();

void fileReadTestRun() {
  // Read from a file
  // check open status
  ifstream inFS("numbers.txt");
  if (!inFS.is_open()) {
    cerr << "Error\n";
    exit(EXIT_FAILURE);
  }

  // alternative method
  // if (inFS.fail()) {
  //   cerr << "Error\n";
  //   exit(EXIT_FAILURE);
  // }

  // === Read numbers from a file until the end of file ===

  int num;

  // 1. Cleanest method, stop on fail
  //    ONLY works when there is only one type of data to be read from a file
  cout << "Method 1\n";
  while (inFS >> num)
    cout << num << endl;

  // reset the read position
  // must call clear first before c++11
  // fstream::clear() clears the flag bits
  inFS.clear();
  inFS.seekg(0);  // rewind to the beginnign of the file

  // 2. While not eof, stop on fail
  //    adjust the order so the inFS.fail() check is always happening right
  //    after the read operation (>> or getline)
  // NOT RECOMMENDED! Adjusting ordering is tricky!
  cout << "Method 2\n";
  inFS >> num;
  while (!inFS.fail()) {
    cout << num << endl;
    inFS >> num;
  }

  // reset the read position
  inFS.clear();
  inFS.seekg(0);  // rewind to the beginning of the file

  // 3. While, stop on fail
  // NOT RECOMMENDED! Redundant
  cout << "Method 3\n";
  while (!inFS.fail()) {
    inFS >> num;
    if (!inFS.fail())  // avoid displaying failed input
      cout << num << endl;
  }

  // reset the read position
  inFS.clear();
  inFS.seekg(0);  // rewind to the beginning of the file

  // 4. While true, stop on fail
  // RECOMMENDED! Straightforward.
  cout << "Method 4\n";
  while (true) {
    inFS >> num;
    if (inFS.fail()) break;
    cout << num << endl;
  }

  // wrong! will display a wrong value in the very last iteration
  // while (!inFS.eof()) {
  //     inFS >> num;
  //     cout << num << endl;
  // }

  inFS.close();
}

int main() {
  fileReadTestRun();
  return EXIT_SUCCESS;
}