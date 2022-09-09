#include "grades.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>

using namespace std;

Grade::Grade(const std::string &text) {
  parse(text);
}

void Grade::parse(const std::string &text) {
  istringstream inSS(text);
  string gradeStr;
  getline(inSS, name, ',');
  getline(inSS, gradeStr, ',');
  midterm1 = stod(gradeStr);
  getline(inSS, gradeStr, ',');
  midterm2 = stod(gradeStr);
  inSS >> finalExam;
}

string Grade::toStr() {
  ostringstream outSS;
  outSS << setw(15) << left << name << " | ";
  outSS << fixed << setprecision(2) << right;
  outSS << setw(6) << midterm1 << " | ";
  outSS << setw(6) << midterm2 << " | ";
  outSS << setw(6) << finalExam;
  return outSS.str();
}

bool Grades::load(string path) {
  ifstream inFS(path);
  string line;
  if (!inFS.is_open()) {
    return false;
  }
  while (getline(inFS, line)) {
    grades.push_back(Grade(line));
  }
  inFS.close();
  return true;
}

bool Grades::save(string path) {
  ofstream outFS(path);
  if (!outFS.is_open()) {
    cerr << "Cannot open file" << endl;
    return false;
  }
  for (int i = 0; i < grades.size(); ++i)
    outFS << grades.at(i).toStr() << endl;

  outFS.close();

  return true;
}