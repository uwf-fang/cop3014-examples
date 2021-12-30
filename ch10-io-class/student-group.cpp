/**
 * Implementation of Student and StudentGroup classes
 */

#include "student-group.hpp"
#include <sstream>
#include <fstream>
#include <iostream>

using namespace std;

Student::Student() = default;

Student::Student(const string &all_info_string) {
  parse(all_info_string);
}

// text formatted like "John Smith, 22, COP2334 COP3014 CIS5099
void Student::parse(const string &all_info_string) {
  istringstream inSS(all_info_string);
  string age_str, courses_str, course;

  getline(inSS, name, ',');
  getline(inSS, age_str, ',');
  age = stoi(age_str);
  getline(inSS, courses_str);
  inSS.clear();
  inSS.str(courses_str);
  int i = 0;
  while (inSS >> course) {
    courses[i] = course;
    i++;
  }
  empty = false;
}

string Student::toStr() {
  if (isEmpty())
    return "";
  ostringstream outSS;
  outSS << name << ',' << age << ',';
  for (int i = 0; i < MAX_COURSES && !courses[i].empty(); i++) {
    outSS << courses[i] << ' ';  // will have an extra space at the end of line
  }
  return outSS.str();
}

bool Student::isEmpty() {
  return empty;
}

StudentGroup::StudentGroup() {
  students = new Student[capacity];
}

StudentGroup::StudentGroup(const string &filePath) {
  students = new Student[capacity];
  loadFile(filePath);
}

bool StudentGroup::loadFile(const string &filePath) {
  ifstream inFile(filePath);
  if (!inFile.is_open()) {
    cerr << "File cannot be opened!\n";
    return false;
  }
  string line;
  int i;
  // cannot add more than capacity of students
  for (i = 0; i < capacity; i++) {
    getline(inFile, line);
    if (inFile.fail() || line.empty())
      break;
    students[i].parse(line);
  }
  size = i;
//  cout << "Loaded " << i << " lines\n";
  loaded = (i > 0);  // at least one line is parsed
  inFile.close();
  return loaded;
}

StudentGroup::~StudentGroup() {
  delete [] students;
}

bool StudentGroup::isLoaded() {
  return loaded;
}

bool StudentGroup::saveFile(string filePath) {
  ofstream outFile(filePath);
  if (!outFile.is_open()) {
    cerr << "File cannot be opened!\n";
    return false;
  }
  int i;
  // cannot add more than capacity of students
  for (i = 0; i < size; i++) {
    outFile << students[i].toStr() << endl;
  }
//  cout << "Saved " << i << " lines\n";
  outFile.close();
  saved = true;
}
