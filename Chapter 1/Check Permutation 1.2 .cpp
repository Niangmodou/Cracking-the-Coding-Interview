/*
Cracking the Coding Interview 1.2
Given two strings, write a method to decide if one is a permutation of the other
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

//Sorting -> O(nlogn)
bool checkPerm(string& s1, string& s2){
  sort(s1.begin(),s1.end());
  sort(s2.begin(),s2.end());
  return s1 == s2;
}
//Auxillary Data Structure -> O(n)
bool checkPerm2(string& s1, string& s2){
  map<char,int> myMap;
  //Add elements of s1 into map with count
  for(char c : s1) myMap[c] = 0;

  for(char c : s1) myMap[c] +=1;
  //Iterate through s2 and decrement count
  for(char c : s2) myMap[c] -=1;

  for(auto iter = myMap.begin(); iter != myMap.end(); ++iter){
    if(iter->second != 0) return false;
  }
  return true;
}

int main() {
  string s1 = "HELLO";
  string s2 = "ELLOH";
  
  string s3 = "YOYOU";
  string s4 = "YOYON";

  cout << boolalpha;
  cout << checkPerm(s1,s2) << endl;
  cout << checkPerm(s3,s4) << endl;
  cout << "----------" << endl;
  cout << checkPerm2(s1,s2) << endl;
  cout << checkPerm2(s3,s4) << endl;
}