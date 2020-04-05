/*
Cracking the Coding Interview 1.4
Write a function to check if a string is a permutation of a palindrome
*/

#include <iostream>
#include <string>
#include <map>

using namespace std;

//Using Map -> O(n)
bool palindromePermutation(string& s1){
  map<char,int> myMap;
  //Add each item to a map
  for(char c : s1){
    if(isalpha(c)){
      c = tolower(c);
      if(myMap.find(c) != myMap.end()) myMap[c]++;
      else myMap[c] = 1;
    }
  }
  //There can only be one character with an odd count
  int oddCount = 0;
  for(auto iter = myMap.begin(); iter != myMap.end(); ++iter){
    if(iter->second%2 != 0) oddCount++;
  }

  //Checks if odd count exceeds 1
  if(oddCount > 1) return false;
  return true;
}

int main() {
  string s1 = "Tact Coa";
  string s2 = "carrace";
  string s3 = "code";
  
  cout << palindromePermutation(s1) << endl;
  cout << palindromePermutation(s2) << endl;
  cout << palindromePermutation(s3) << endl;
}