/**
 * @file student-group.hpp
 * @author Ian Fang
 * @brief Declarations of Student and StudentGroup classes
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef STUDENT_GROUP_HPP
#define STUDENT_GROUP_HPP

#include <string>

using std::string;

constexpr int MAX_COURSES = 5;  // constexpr is similar to const, since c++11

class Student {
  string name;
  int age;
  string courses[MAX_COURSES];  // may need to implement deep copy as needed
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
 public:
  StudentGroup(int capacity = 40);
  ~StudentGroup();
  bool loadFile(const string &filePath);
  bool saveFile(string filePath);
};

#endif
