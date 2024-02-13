#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

#include "util.h"
#include "clothing.h"


using namespace std;

Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand) :
    Product(category, name, price, qty),
    size_(size), 
    brand_(brand)
{

}

Clothing::~Clothing()
{

}

std::set<std::string> Clothing::keywords() const 
{
  set<string> name_set = parseStringToWords(convToLower(getName()));
  set<string> brand_set = parseStringToWords(convToLower(getBrand()));
  set<string> keywords = setUnion(name_set, brand_set);

  return keywords;
}

std::string Clothing::displayString() const
{
  string s = getName();
  s.append("\n");
  s.append("Size: ");
  s.append(getSize());
  s.append(" Brand: ");
  s.append(getBrand());
  s.append("\n");
  s.append(to_string(getPrice()));
  s.append(" ");
  s.append(to_string(getQty()));
  s.append(" left.");

  return s;
}

std::string Clothing::getSize() const
{
  return size_;
}

std::string Clothing::getBrand() const
{
  return brand_;
}



void Clothing::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << size_ << "\n" << brand_ << endl;
}



