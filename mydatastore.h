#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>

#include "datastore.h"

class MyDataStore : public DataStore {
  public: 
    MyDataStore();
    ~MyDataStore();

    void addProduct(Product* p);
    void addUser(User* u);
    std::vector<Product*> search(std::vector<std::string>& terms, int type);
    void dump(std::ostream& ofile);
    void viewCart(std::string username);
    void addToCart(std::string username, int search_hit_number);

  protected:
    std::map<std::set<std::string>, Product*> ProductList;
    std::map<std::string, User*> UserList;

};

#endif