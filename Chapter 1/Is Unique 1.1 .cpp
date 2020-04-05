/*
Cracking the Coding Interview 1.1
Implement an algorithm to determine if a strng has all unique
characters. What if you cannot use additional data structures?
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <set>

using namespace std;

//Using set -> O(n)
bool isUnique(const string& s){
  set<char> mySet;
  //Insert all elements of string into a set
  for(char c : s) mySet.insert(c);
  //If the sizes are equal items are unique
  return mySet.size() == s.size();
}

//Without using auxilary data structure -> O(nlogn)
bool isUnique2(string& s){
  //Sort string
  sort(s.begin(),s.end());
  //If adjacent elements are the same then s is not unique
  for(int i = 1; i < s.size(); ++i){
    if(s[i-1] == s[i]) return false;
  }
  return true;
}
int main() {
  string s1 = "HELLO";
  string s2 = "MODOU";
  string s3 = "CODING";

  cout << boolalpha;
  cout << isUnique(s1) << endl;
  cout << isUnique(s2) << endl;
  cout << isUnique(s3) << endl;

  cout << "--------------------" << endl;

  cout << isUnique2(s1) << endl;
  cout << isUnique2(s2) << endl;
  cout << isUnique2(s3) << endl;
}