/**
 * Ian Fang on 10/25/21.
 */

#ifndef COP3014_2021F_FILE_IO_DEMO_STUDENT_GROUP_HPP_
#define COP3014_2021F_FILE_IO_DEMO_STUDENT_GROUP_HPP_

#include <string>

using std::string;

constexpr int MAX_COURSES = 5;  // constexpr is similar to const, since c++11

class Student {
  string name;
  int age;
  string courses[MAX_COURSES];
  int count;
 public:
  Student();
  void parse(const string &infoString);
  // Generate string representation of a student
  string toStr();
};

class StudentGroup {
  int capacity;  // must be declared before students so it will be initialized first in the constructor
  Student *students;  // dynamic array
  int size;
  bool loaded;
  bool saved;
 public:

  StudentGroup();
  ~StudentGroup();
  bool loadFile(const string &filePath);
  bool saveFile(string filePath);
};


#endif //COP3014_2021F_FILE_IO_DEMO_STUDENT_GROUP_HPP_
