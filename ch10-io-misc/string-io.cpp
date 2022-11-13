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

struct StudentInfo {
  string name;
  int age;
  double height;
  string to_str() {
    ostringstream outSS;
    outSS << "Name: " << name << " age: " << age;
    outSS << " Height: " << setprecision(1) << fixed << height << endl;
    return outSS.str();
  }
};

StudentInfo parse1(const string &line) {
  StudentInfo result;
  string junk;
  stringstream inSS(line);
  getline(inSS, result.name, ',');
  inSS >> result.age;
  getline(inSS, junk, ',');  // discard the ,
  inSS >> result.height;
  return result;
}

StudentInfo parse2(const string &line) {
  StudentInfo result;
  stringstream inSS(line);
  string ageStr;
  string heightStr;
  getline(inSS, result.name, ',');
  getline(inSS, ageStr, ',');
  getline(inSS, heightStr);  // read to eof
  result.age = stoi(ageStr);
  result.height = stod(heightStr);
  return result;
}

StudentInfo parse3(const string &line) {
  StudentInfo result;
  int comma1 = line.find(',');
  int comma2 = line.find(',', comma1 + 1);
  result.name = line.substr(0, comma1);
  result.age = stoi(line.substr(comma1 + 1, comma2 - comma1 ));
  result.height = stod(line.substr(comma2 + 1, line.length() - comma2 ));
  return result;
}

int main() {
  string data = "John Smith, 20, 181.3";
  string data1 = "Mary Smith, 20, 161.3";

  cout << parse1(data).to_str() << endl << endl;
  cout << parse2(data).to_str() << endl << endl;
  cout << parse3(data).to_str() << endl << endl;

  cout << parse1(data1).to_str() << endl << endl;
  cout << parse2(data1).to_str() << endl << endl;
  cout << parse3(data1).to_str() << endl << endl;

}