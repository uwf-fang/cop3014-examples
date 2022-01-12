#ifndef MY_CLASS_HPP
#define MY_CLASS_HPP

class MyClass {
  private:  // optional, anything not in the public section is private
  int value;
  void doubleVal();  // private helper
  public:
  MyClass();  // default constructor
  MyClass(int value);  // parameterized constructor
  int getValue() const;  // accessor/getter
  void setValue(int value);  // mutator/setter
  int getDoubledValue();  // general public method
};  // WARNING: must have ; here

#endif // MY_CLASS_HPP