#ifndef STORE_HPP
#define STORE_HPP

#include "store-item.hpp"
#include <string>
#include <vector>

class Store {
 private:
  std::string storeName;
  std::vector<StoreItem> items;

 public:
  Store();
  explicit Store(const std::string & name);
  void addItem(StoreItem item);
  void print() const;
};

#endif