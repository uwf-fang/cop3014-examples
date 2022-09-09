/**
 * Implementation of Student and StudentGroup classes
 */

#include "student-group.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

// default constructor
// string do not need initial value, default to ""
Student::Student(): age(0), count(0) {}

// parse text formatted like "John Smith, 22, COP2334 COP3014 CIS5099
void Student::parse(const string &infoString) {
  istringstream inSS(infoString);
  string ageStr, course;
  int i;

  getline(inSS, name, ',');
  getline(inSS, ageStr, ',');
  age = stoi(ageStr);
  for (i = 0; i < MAX_COURSES; ++i) {
    inSS >> course;
    if (inSS.fail()) break;
    courses[i] = course;
  }
  count = i;
}

string Student::toStr() {
  ostringstream outSS;
  outSS << name << ',' << age << ',';
  for (int i = 0; i < MAX_COURSES && !courses[i].empty(); ++i) {
    outSS << courses[i] << ' ';  // will have an extra space at the end of line
  }
  return outSS.str();
}

StudentGroup::StudentGroup(): capacity(40), students(new Student[capacity]) {}

bool StudentGroup::loadFile(const string &filePath) {
  ifstream inFile(filePath);
  if (!inFile.is_open()) {
    cerr << "File cannot be opened!\n";
    return false;
  }
  string line;
  int i;
  // cannot add more than capacity of students
  for (i = 0; i < capacity; ++i) {
    getline(inFile, line);
    if (inFile.fail())
      break;
    if (line.empty()) // skip empty lines
      continue;
    students[i].parse(line);
  }
  size = i;
//  cout << "Loaded " << i << " lines\n";
  loaded = (i > 0);  // at least one line is parsed
  inFile.close();
  return loaded;
}

StudentGroup::~StudentGroup() {
  delete [] students;  // students will never be nullptr
}

bool StudentGroup::saveFile(string filePath) {
  ofstream outFile(filePath);
  if (!outFile.is_open()) {
    cerr << "File cannot be opened!\n";
    return false;
  }
  int i;
  for (i = 0; i < size; ++i) {
    outFile << students[i].toStr() << endl;
  }
  outFile.close();
  saved = true;
  return saved;
}
