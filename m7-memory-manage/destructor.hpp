#ifndef DESCRUCTOR_HPP
#define DESCRUCTOR_HPP
class MyVector {
private:
  int *array;
  int size;
  int capacity;
public:
  MyVector();
  MyVector(int size);
  ~MyVector();  // destructor, no parameter
  int getSize();
  int getVal(int index);
};

#endif
