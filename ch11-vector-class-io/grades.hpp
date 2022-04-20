#ifndef GRADES_HPP
#define GRADES_HPP

#include <string>
#include <vector>

class Grade {
  std::string name;
  double midterm1;
  double midterm2;
  double final
 public:
  Grade(const std::string &text);
  void parse(const std::string &text);
};

class Grades {
  std::vector<Grade> grades;
 public:
  bool load(std::string path);
  bool save();
};

#endif // GRADES_HPP
