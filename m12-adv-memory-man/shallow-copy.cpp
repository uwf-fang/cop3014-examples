#include <iostream>

using namespace std;

class List {
 private:
  int *array;
  int size;
 public:
  List();
  List(int value, int repeat);
  ~List();
  void setValue(int index, int value);
  void print();
};

List::List() {
  array = nullptr;
  size = 0;
}

List::List(int value, int repeat) {
  size = repeat;
  array = new int[repeat];
  for (int i = 0; i < repeat; i++)
    array[i] = value;
}

List::~List() {delete [] array;}

void List::setValue(int index, int value) {
  array[index] = value;
}

void List::print() {
  for (int i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}

int main() {
  List list(10, 11);
  List list2 = list;
  List list3;

  list3 = list;

  list.print();
  list2.print();
  list3.print();

  list.setValue(4, 1);

  list.print();
  list2.print();
  list3.print();

  return 0;
}