#ifndef STORE_H
#define STORE_H

#include <string>
#include <vector>
#include "store-item.hpp"

class Store
{
public:
  Store();
  explicit Store(std::string name);
  void addItem(StoreItem item);
  void print() const;

private:
  std::string name;
  std::vector<StoreItem> items;
};

#endif