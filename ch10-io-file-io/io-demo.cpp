// String content parsing using istringstream
#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;

/**
 * Parse text using istringstream
 * >> can parse text to other types like int or double
 * getline can only read string and need further parsing using stoi or stod
 */
void textParsingTest();
// Generate formatted text in a string using ostringstream
string makeFormattedText(string firstName, string lastName, int age,
                         double height);

// Read from file until end of file or error
void readFileDemo();

// getline after extraction >> may cause problem
// need special handling
void getlineAfterExtractionDemo();

void textParsingTest() {
  cout << "Text parsing test using istringstream class...\n";
  string text = "John Smith 20 180.1";
  istringstream inSS(text);

  string firstName, lastName;
  int age;
  double height;
  inSS >> firstName >> lastName >> age >> height;
  cout << "Name: " << firstName << " " << lastName << " | Age: " << age
       << " | height: " << height << endl;

  // When delimiters are not white spaces (comma, space, tab, etc.)
  text = "John Smith, 20, 180.1";

  // must clear before preceeding
  inSS.clear();
  inSS.str(text);

  string name, ageStr, heightStr;
  getline(inSS, name, ',');
  getline(inSS, ageStr, ',');
  getline(inSS, heightStr);
  // parse ageStr, heightStr to the right type
  // stoi: string to int
  // stod: string to double
  age = stoi(ageStr);  // not type cast! cannot use static_cast<int>(ageStr)
  height = stod(heightStr);

  cout << "Name: " << name << " | Age: " << age << " | height: " << height
       << endl;
}

string makeFormattedText(string firstName, string lastName, int age,
                         double height) {
  ostringstream outSS;
  outSS << firstName << " " << lastName << " " << age;
  outSS << " " << fixed << setprecision(1) << height;
  return outSS.str();
}

void readFileDemo() {
  // Read from a file
  // check open status
  ifstream inFS("numbers.txt");
  if (!inFS.is_open()) {
    cerr << "Error\n";
    exit(EXIT_FAILURE);
  }

  // alternative method
  // if (inFS.fail()) {
  //     cerr << "Error\n";
  //     return EXIT_FAILURE;
  // }

  // === Read numbers from a file until the end of file ===

  int num;

  // 1. Cleanest method, stop on fail
  cout << "Method 1\n";
  while (inFS >> num) {
    cout << num << endl;
  }

  // reset the read position
  // must call clear first before c++11
  // fstream::clear() clears the flag bits
  inFS.clear();
  inFS.seekg(0);  // rewind to the beginnign of the file

  // 2. While not eof, stop on fail
  cout << "Method 2\n";
  inFS >> num;
  while (!inFS.fail()) {
    cout << num << endl;
    inFS >> num;
  }

  // reset the read position
  inFS.clear();
  inFS.seekg(0);  // rewind to the beginnign of the file

  // 3. While, stop on fail
  cout << "Method 3\n";
  while (!inFS.eof() && inFS.good()) {
    inFS >> num;
    if (!inFS.fail())
      cout << num << endl;
  }

  // reset the read position
  inFS.clear();
  inFS.seekg(0);  // rewind to the beginnign of the file

  // 4. While true, stop on fail
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

void getlineAfterExtractionDemo() {
  int num1;
  cout << "Give me your age as an int";
  cin >> num1;
  string name;
  cout << "Give me your full name";
  // getline(cin, name); // wrong way, will read in an empty string

  // may use cin.ignore(); to skip but this may cause problem with different
  //   line ending or when used after getline

  // recommended way
  do {
    getline(cin, name);
  } while (name.empty());

  cout << "Name is " << name << endl;
}

int main() {
  textParsingTest();
  readFileDemo();
  return EXIT_SUCCESS;
}