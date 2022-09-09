#include <iostream>
using namespace std;

#include "store.hpp"

Store::Store(): storeName("") {}

Store::Store(const string & storeName): storeName(storeName) {}

void Store::addItem(StoreItem item) {
  items.push_back(item);
}

void Store::print() const {
  cout << "Store: " << storeName << endl;
  cout << "----------------\n";
  for (int i = 0; i < items.size(); ++i)
    items.at(i).print();
}

