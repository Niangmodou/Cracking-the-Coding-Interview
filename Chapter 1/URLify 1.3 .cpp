/*
Cracking the Coding Interview 1.3
Write a method to replace all spaces in a string with '%20'
*/
#include <iostream>
#include <string>

using namespace std;

string urlIFY(const string& s){
  string retStr = "";
  for(char c : s){
    if(c == ' ') retStr += "%20";
    else retStr+=c;
  }
  return retStr;
}

int main() {
  string s1 = "Modou Kebe Niang";
  string s2 = "Mr John Smith";
  cout << boolalpha;
  cout << urlIFY(s1) << endl;
  cout << urlIFY(s2) << endl;
}