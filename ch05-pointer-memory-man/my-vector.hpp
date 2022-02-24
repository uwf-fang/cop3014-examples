#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

class MyVector {
private:
  int *array;
  int arrSize;
  int capacity;
  // re-allocate when runing out of space
  void reAllocate();
public:
  MyVector();
  MyVector(int size);
  // destructor
  ~MyVector();
  int size() const;
  // return reference to allow assignment like v.at(0) = 10;
  int &at(int index);
  void push_back(int value);
  int pop_back();
  void remove(int index);
};

#endif
