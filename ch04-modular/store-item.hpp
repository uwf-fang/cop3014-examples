#ifndef STORE_ITEM_HPP
#define STORE_ITEM_HPP

#include <string>

class StoreItem {
 private:
  std::string name;
 public:
  StoreItem();
  explicit StoreItem(const std::string &name);  // avoid StoreItem item = "Item name";
  ~StoreItem();
  bool equals(const StoreItem & other) const;
  std::string getName() const;
  void setName(const std::string &name);
  void print() const;
};

#endif