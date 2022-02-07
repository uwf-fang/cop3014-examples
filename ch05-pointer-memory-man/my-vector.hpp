#ifndef MY_VECTOR_HPP
#define MY_VECTOR_HPP

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
