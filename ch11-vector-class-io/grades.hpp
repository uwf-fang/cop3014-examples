#ifndef GRADES_HPP
#define GRADES_HPP

#include <string>
#include <vector>

class Grade {
  std::string name;
  double midterm1;
  double midterm2;
  double finalExam;
 public:
  Grade(const std::string &text);
  void parse(const std::string &text);
  std::string toStr();
};

class Grades {
  std::vector<Grade> grades;
 public:
  bool load(std::string path);
  bool save(std::string path);
};

#endif // GRADES_HPP
