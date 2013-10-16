/**
  Algorithm Design Manual by Steven Skiena
  My C++ solutions to the book questions

  http://nbl.cewit.stonybrook.edu:60128/mediawiki/index.php/Main_Page
  @author Alyssa Quek 2013
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


//Algorithm Design Manual: Sorting-searching ch 4
//4-42. Implement an algorithm that takes an input array and returns only the unique elements in it.
vector<int> getUniqueElems (int *array, unsigned int size) {
  set<int> mySet;
  vector<int> uniqueElems;
  mySet.insert(array, array+size);

  set<int>::const_iterator citer = mySet.begin();
  copy(mySet.begin(), mySet.end(), back_inserter(uniqueElems));
  return uniqueElems;
}

int main () {
  int myints[] = {5,10,15, 13, 14,23,21,21,21,5}; 
  std::vector<int> v = getUniqueElems(myints, 10);
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
  return 0;
}