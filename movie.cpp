#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

#include "util.h"
#include "movie.h"


using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, std::string genre, std::string rating) :
    Product(category, name, price, qty),
    genre_(genre), 
    rating_(rating)
{

}

Movie::~Movie()
{

}

std::set<std::string> Movie::keywords() const
{
  set<string> keywords = parseStringToWords(convToLower(getName()));
  keywords.insert(convToLower(getGenre()));

  return keywords;
}

std::string Movie::displayString() const
{
  string s = getName();
  s.append("\n");
  s.append("Genre: ");
  s.append(getGenre());
  s.append(" Rating: ");
  s.append(getRating());
  s.append("\n");
  s.append(to_string(getPrice()));
  s.append(" ");
  s.append(to_string(getQty()));
  s.append(" left.");

  return s;
}

std::string Movie::getGenre() const
{
  return genre_;
}

std::string Movie::getRating() const
{
  return rating_;
}

void Movie::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << genre_ << "\n" << rating_ << endl;
}

