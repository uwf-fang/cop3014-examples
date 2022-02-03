#include <iostream>
using namespace std;

#include "store-item.hpp"

// alternative way
// StoreItem::StoreItem() = default;
StoreItem::StoreItem(): name("") {}

// alternative way
// StoreItem::StoreItem(const string & name): name(name) {}
StoreItem::StoreItem(const string & name) {
  this->name = name;
}

string StoreItem::getName() const {
  return name;
}

void StoreItem::setName(const string &name) {
  this->name = name;
}

StoreItem::~StoreItem() {
  // clean up dynamic data, not applicable in this class
}

bool StoreItem::equals(const StoreItem & other) const {
  return (this->name == other.name);  // do not use if statement
}

void StoreItem::print() const {
  cout << "Item name: " << name << endl;
}