#include "grades.hpp"
#include <sstream>
#include <fstream>

using namespace std;

Grade::Grade(const std::string &text) {
  parse();
}
void Grade::parse(const std::string &text) {
  istringstream inSS(text);
  getline(inSS, name, ',');
  getline(inSS, gradeStr, ',');
  midterm1 = stod(gradeStr);
  getline(inSS, gradeStr, ',');
  midterm2 = stod(gradeStr);
  inSS >> final;
}
bool Grades::load(std::string path) {
  ifstream inFS(path);
  string line;
  if (!inFS.is_open()) {
    cerr << "Cannot open file" << endl;
    return false;
  }
  while (getline(inFS, line)) {
    grades.push_back(Grade(line));
  }
  inFS.close;
  return true;
}
bool Grades::save() {
  return true;
}