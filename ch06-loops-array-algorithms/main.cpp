#include "search.hpp"
#include <iostream>
#include <cassert>
using namespace std;


void testLinearSearch();
void testBinarySearch();
void testLinearSearchLast();

int main() {
  testLinearSearch();
  testBinarySearch();
  testLinearSearchLast();
  return EXIT_SUCCESS;
}

void testBinarySearch() {
  int values[] = {1, 2, 3, 4 ,5, 6, 7, 8, 9, 10};
  assert(binarySearch(values, 10, 3) == 2);
  assert(binarySearch(values, 10, 1) == 0);
  assert(binarySearch(values, 10, 10) == 9);
}

void testLinearSearch() {
  int values[] = {1, 2, 3, 4 ,7, 6, 5, 9, 8, 10};
  assert(linearSearch(values, 10, 3) == 2);
  assert(linearSearch(values, 10, 1) == 0);
  assert(linearSearch(values, 10, 10) == 9);
}

void testLinearSearchLast() {
  int values[] = {9, 2, 7, 4 ,7, 10, 5, 9, 8, 0};
  assert(linearSearchLast(values, 10, 7) == 4);
  assert(linearSearchLast1(values, 10, 7) == 4);
  assert(linearSearchLast2(values, 10, 7) == 4);
}

