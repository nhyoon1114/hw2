#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>


#include "util.h"
#include "mydatastore.h"

using namespace std;

MyDataStore::MyDataStore() :
  DataStore()
{

}

MyDataStore::~MyDataStore() 
{
  while (!ProductList.empty()) {
    delete (ProductList.begin()->second);
    ProductList.erase(ProductList.begin());
  }
  while(!UserList.empty()) {
    delete (UserList.begin()->second);
    UserList.erase(UserList.begin());
  }
}

void MyDataStore::addProduct(Product* p)
{
  ProductList.insert(make_pair(p->keywords(), p));
}

void MyDataStore::addUser(User* u)
{
  //set<Product*> cart;
  UserList.insert(make_pair(u->getName(), u));
}

vector<Product*> MyDataStore::search(vector<string>& terms, int type)
{
  set<Product*> itemList;
  //declare itemList
  vector<string>::iterator it = terms.begin();
  set<Product*> tempList;
  while(it != terms.end()) {
    //tempList stores (keywords, product) pair
    //if the term is in the keyword list, add pair
    tempList.clear();
    map<set<string>, Product*>::iterator it2;
    for (it2 = ProductList.begin(); it2 != ProductList.end(); ++it2) {
      //if the word *it is found in the product list keyword
      if (it2->first.find(*it) != it2->first.end()) {
        tempList.insert(it2->second);
      }
    }
    //combine itemList with tempList
    if (type == 0) {
      itemList = setIntersection(itemList, tempList);
    }
    else if (type == 1) {
      itemList = setUnion(itemList, tempList);
    }
    ++it;
  }
  vector<Product*> finalList;
  finalList.assign(itemList.begin(), itemList.end());
  return finalList;
}

void MyDataStore::dump(std::ostream& ofile)
{
  ofile << "<products>" << endl;
  map<set<string>, Product*>::iterator it;
  for (it = ProductList.begin(); it != ProductList.end(); ++it) {
    it->second->dump(ofile);
  }
  ofile << "</products>" << endl;
  ofile << "<users>" << endl;
  map<string, User*>::iterator it2;
  for (it2 = UserList.begin(); it2 != UserList.end(); ++it2) {
    it2->second->dump(ofile);
  }
  ofile << "</users>" << endl;
}
void MyDataStore::addToCart(std::string username, int hit_result_index) {

}

void MyDataStore::viewCart(std::string username) 
{
  //cout << "view cart function" << endl;
  //std::map<std::set<Product*>, User*>::iterator it = UserList.find(username);
  /*if (it == UserList.end())
  {
    cout << "Invalid username" << endl;
  }
  else {
    
  }*/
}
