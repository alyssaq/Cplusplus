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
#include <assert.h>

using namespace std;
typedef std::vector<int>::iterator iterator;
typedef std::vector<int>::const_iterator citerator;

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
    //print(sortedItems);
  }

  return sortedItems;
}

int findAndDeleteMinItem(std::vector<int> &items) {
  int min = 100000;
  vector<int>::iterator min_iter = items.begin();
  for (vector<int>::iterator iter = items.begin(); iter != items.end(); iter++) {
    if (*iter < min) {
      min = *iter;
      min_iter = iter;
    }
  }
  items.erase(min_iter);
  return min;
}

/*
  Selection sort: Keep finding the min item O(n)
  push it into a sorted array and delete.
  O(n^2). 
  Heapsort: Use a prioirity queue and speed it to O(n log n)
  Find and delete takes O(log n) instead of O(n)

*/
vector<int> selectionSort(const vector<int>& items) {
  vector<int> tempItems = items;
  vector<int> sortedItems;

  for(citerator iter = items.begin(); iter != items.end(); iter++) {
    sortedItems.push_back(findAndDeleteMinItem(tempItems));
  }
  return sortedItems;
}

/*
  Merge sort: O(n log n)
  Using a temp vector to avoid recreating temp arrays during the split
 */
void merge_helper(vector<int> &items, int start, int end, vector<int> &temp) {
  if (start + 1 == end) return; //base case: one item

  int i = 0;
  int len = (end - start);
  int mid = start + len / 2;
  //pointer index to the start of the left and right subarrays
  int l = start, r = mid;

  merge_helper(items, start, mid, temp); //mergeSort first half
  merge_helper(items, mid, end, temp);  //mergeSort second half

  for (i = 0; i < len; i++) {
    /* Check if there are items in the left to compare.
    If there are, compare the left with right.
    If there is nothing to compare in the right, just add the left
    */
    if (l < mid && (r == end || items[l] < items[r])) {
      temp[i] = items[l++];
    } else {
      temp[i] = items[r++];
    }
  }

  //Copy the temp sorted array back to the original items
  copy(temp.begin(), temp.begin() + len, items.begin() + start);
}

vector<int> mergeSort(const vector<int> &v) {
  vector<int> temp;
  vector<int> items(v);
  temp.resize(items.size());
  merge_helper(items, 0, items.size(), temp);
  return items;
}

int main() {
  int myints[] = {16,277,3,-2,24,-54,-1,0,56,87,7,-7};
  vector<int> items (myints, myints + sizeof(myints) / sizeof(int));
  print(items);

  vector<int> sortedItems = insertionSort(items);
  string s = vector2string(sortedItems);
  assert(s == "-54, -7, -2, -1, 0, 3, 7, 16, 24, 56, 87, 277");

  sortedItems = mergeSort(items);
  s = vector2string(sortedItems);
  assert(s == "-54, -7, -2, -1, 0, 3, 7, 16, 24, 56, 87, 277");

  sortedItems = selectionSort(items);
  s = vector2string(sortedItems);
  assert(s == "-54, -7, -2, -1, 0, 3, 7, 16, 24, 56, 87, 277");

  transform(sortedItems.begin(), sortedItems.end(), sortedItems.begin(), incrementBy2);
  print(sortedItems);

}