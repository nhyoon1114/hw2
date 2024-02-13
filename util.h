#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  typename std::set<T> intersection;
  //find function is O(log n)
  //outline: for each item in s1, find if that item is in s2
  typename std::set<T>::iterator it;
  //this for loop should run n times
  for (it = s1.begin(); it != s1.end(); ++it) {
    //if the item is found in s2 then insert item into intersection
    //find function should be log n 
    if (s2.find(*it) != s2.end()) {
      intersection.insert(*it);
    }
  }
  return intersection;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  //union should just be everything in s1 plus everything in s2
  typename std::set<T> setunion = s2;
  typename std::set<T>::iterator it;
  for (it = s1.begin(); it != s1.end(); ++it) {
    setunion.insert(*it);
  }
  return setunion;
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
