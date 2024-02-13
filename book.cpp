#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>

#include "util.h"
#include "book.h"


using namespace std;

Book::Book(const std::string category, const std::string name, double price, int qty, const std::string isbn, const std::string author) :
    Product(category, name, price, qty),
    isbn_(isbn),
    author_(author)
{

}

Book::~Book()
{

}

std::set<std::string> Book::keywords() const
{
  set<string> name_set = parseStringToWords(convToLower(getName()));
  set<string> author_set = parseStringToWords(convToLower(getAuthor()));
  set<string> keywords = setUnion(name_set, author_set);
  keywords.insert(getISBN());
  cout << getISBN() << endl;
  return keywords;
}

std::string Book::displayString() const
{
  string s = getName();
  s.append("\n");
  s.append("Author: ");
  s.append(getAuthor());
  s.append(" ISBN: ");
  s.append(getISBN());
  s.append("\n");
  s.append(to_string(getPrice()));
  s.append(" ");
  s.append(to_string(getQty()));
  s.append(" left.");

  return s;
}

std::string Book::getAuthor() const
{
  return author_;
}

std::string Book::getISBN() const
{
  return isbn_;
}

void Book::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << "\n" << isbn_ << "\n" << author_ << endl;
}






