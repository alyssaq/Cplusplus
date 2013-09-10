/**
    Sorting Algorithms in C++
    Implementations for fun

    @author Alyssa Quek 2013
*/
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
#include <sstream> //stringstream
#include <string>

using namespace std;
typedef std::vector<int>::iterator iterator;


// print a vector
void print(const vector<int>& v) {
  copy(v.begin(), v.end() - 1, ostream_iterator<int>(cout, ", "));
  cout << *(v.end() - 1) << endl;
}

//concatenate vector into a string
string vector2string(const vector<int>& v) {
  ostringstream sstream;
  copy(v.begin(), v.end() - 1, ostream_iterator<int>(sstream, ", "));
  sstream << *(v.end() - 1);
  
  return sstream.str();
}

//functor to increment an integer by 2 
int incrementBy2(int i) { return i + 2; }

/*
  Insertion sort: start from the beginning and incrementally insert the 
  remaining elements to keep the array sorted
  O(n^2)
*/
vector<int> insertionSort(const vector<int>& items) {
  vector<int> sortedItems = items;
  int temp;

  for(int i = 1; i < items.size(); i++) {
    for (int j = 0; j < i; j++){
      if (sortedItems[i] < sortedItems[j]) {
        temp = sortedItems[i];
        sortedItems[i] = sortedItems[j];
        sortedItems[j] = temp;
      }
    }
    print(sortedItems);
  }

  return sortedItems;

}


int main() {
  int myints[] = {16,277,3,-2,24,-54,-1,0,56,87,7,-7};
  vector<int> items (myints, myints + sizeof(myints) / sizeof(int));
  print(items);
  vector<int> sortedItems = insertionSort(items);
  print(sortedItems);

  string s = vector2string(sortedItems);
  cout << s << "\n";

  transform(sortedItems.begin(), sortedItems.end(), sortedItems.begin(), incrementBy2);
  print(sortedItems);

}