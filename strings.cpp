#include <iostream>
#include <iterator>
#include <string>
#include <vector>
#include <algorithm> 
#include <sstream> //stringstream
#include <stack>

using namespace std;

//another hash function:
//object -> int hash code % table size to get table index
int hash(string &str, int tableLen) {
  //return hash function of sum of strings mod table size
  int sum;
  for (int i = 0; i < str.length(); ++i) {
    cout << str[i] << " " << (int)str[i] << "\n";
    sum = sum + (int)(str[i]) - (int)'a';
  }
  return sum % tableLen;
}

const int BASE = 10;
const int HUGE_NUM = 977;
int horner_hash(string &str) {
  int h = 0;
  for (int i = 0; i < str.length(); ++i) {
    h = (h * BASE + (int)str[i]) % HUGE_NUM;
  }
  return h;
}

string stringReverse(string &input) {
  stack<char> s;
  string::const_iterator citer = input.begin();
  for (; citer != input.end(); citer++) {
    s.push(*citer);
  }
  string output;
  while(!s.empty()) {
    output.push_back(s.top());
    s.pop();
  }
  return output;
}

string stringReverseArr(string &input) {
  string output(input);
  string::iterator left = output.begin(), right = output.end()-1;

  while (left != right) {
    char temp = *left;
    *left++ = *right;
    *right-- = temp;
  }

  return output;
}

int main() {

  string inputStr = "hello world";
  cout << stringReverseArr(inputStr) << endl;

  // constructors used in the same order as described above:
  std::vector<int> first;                                // empty vector of ints
  std::vector<int> second (4,100);                       // four ints with value 100
  std::vector<int> third (second.begin(),second.end());  // iterating through second
  std::vector<int> fourth (third);                       // a copy of third
  const int TABLE_LEN = 20;
  vector<string> v(TABLE_LEN, "!");
  string input;
  cin >> input;
  v[hash(input, TABLE_LEN)] = input;
  copy(v.begin(), v.end(), ostream_iterator<string>(cout, " "));

  cout << "\n";

  int i = 0;

  vector<int> hashNums;
  while (i < 5) {
    cin >> input;
    hashNums.push_back(horner_hash(input));
    i++;
  }

  //copy(strs.begin(), strs.end(), ostream_iterator<string>(cout, " "));
  //transform(strs.begin(), strs.end(), hashNums.begin(), horner_hash);
  copy(hashNums.begin(), hashNums.end(), ostream_iterator<int>(cout, " "));


}