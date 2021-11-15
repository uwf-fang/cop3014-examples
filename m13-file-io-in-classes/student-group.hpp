/**
 * Ian Fang on 10/25/21.
 */

#ifndef COP3014_2021F_FILE_IO_DEMO_STUDENT_GROUP_HPP_
#define COP3014_2021F_FILE_IO_DEMO_STUDENT_GROUP_HPP_

#include <string>

using std::string;

const int MAX_COURSES = 5;

class Student {
  string name;
  int age;
  string courses[MAX_COURSES];
  bool empty = true;
 public:
  // default contructor, create an empty object
  // must followed by a call of the parse function to add contents
  Student();
  // create a student object from a text with all info in it
  explicit Student(const string &all_info_string);

  // parse information of a student from a text with all info in it
  void parse(const string &all_info_string);

  // Generate string representation of a student
  string toStr();

  bool isEmpty();
};

class StudentGroup {
  Student *students;  // dynamic array
  int size = 0;
  int capacity = 40;
  bool loaded = false;
  bool saved = false;
 public:

  StudentGroup();
  explicit StudentGroup(const string &filePath);
  ~StudentGroup();
  bool loadFile(const string &filePath);
  bool isLoaded();
  bool saveFile(string filePath);
};


#endif //COP3014_2021F_FILE_IO_DEMO_STUDENT_GROUP_HPP_
