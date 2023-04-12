/**
 * @file string-io.cpp
 * @brief Demonstration of string io and string method
 *
 * @copyright Copyright (c) 2022
 *
 */
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>

using namespace std;

class StudentInfo {
 private:
  string name;
  int age;
  double height;
 public:
  void parse1(const string &line);
  void parse2(const string &line);
  void parse3(const string &line);
  string toStr() {
    ostringstream outSS;
    outSS << "Name: " << name << " age: " << age;
    outSS << " Height: " << setprecision(1) << fixed << height;
    return outSS.str();
  }
};

void StudentInfo::parse1(const string &line) {
  string junk;
  istringstream inSS(line);
  getline(inSS, name, ',');
  inSS >> age;
  getline(inSS, junk, ',');  // discard the ,
  inSS >> height;
}

void StudentInfo::parse2(const string &line) {
  istringstream inSS(line);
  string ageStr;
  string heightStr;
  getline(inSS, name, ',');
  getline(inSS, ageStr, ',');
  getline(inSS, heightStr);  // read to eof
  age = stoi(ageStr);
  height = stod(heightStr);
}

void StudentInfo::parse3(const string &line) {
  int comma1 = line.find(',');
  int comma2 = line.find(',', comma1 + 1);
  name = line.substr(0, comma1);
  age = stoi(line.substr(comma1 + 1, comma2 - comma1 ));
  height = stod(line.substr(comma2 + 1, line.length() - comma2 ));
}

int main() {
  StudentInfo info;
  string data1 = "John Smith, 20, 181.3";
  string data2 = "Mary D. Smith, 18, 161.3";

  info.parse1(data1);
  cout << "Parse1" << info.toStr() << endl << endl;
  info.parse2(data1);
  cout << "Parse2" << info.toStr() << endl << endl;
  info.parse3(data1);
  cout << "Parse3" << info.toStr() << endl << endl;

  info.parse1(data2);
  cout << "Parse1" << info.toStr() << endl << endl;
  info.parse2(data2);
  cout << "Parse2" << info.toStr() << endl << endl;
  info.parse3(data2);
  cout << "Parse3" << info.toStr() << endl << endl;

}