#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;

int hash(string &str, int tableLen) {
  //return hash function of sum of strings mod table size
  int sum;
  for (int i = 0; i < str.length(); ++i) {
    cout << str[i] << " " << (int)str[i] << "\n";
    sum = sum + (int)(str[i]);
  }
  return sum % tableLen;
}

int main() {

  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third
  const int TABLE_LEN = 20;
  vector<int> v(TABLE_LEN);
  string input;
  cin >> input;
  v.push_back(hash(input, TABLE_LEN));
  copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}