'''
CRACKING THE CODING INTEREVIEW 16.2 Number Swapper
Write a fucntion to swap two numbers in place without temporary
varaibles
'''

#include <iostream>

using namespace std;

void numberSwapper(int& a,int& b);

int main(){
	int a = 5, b = 2;
	cout << a << " " << b << endl;

	numberSwapper(a,b);

	cout << a << " " << b << endl;
}

void numberSwapper(int& a, int& b){
	a -= b;
	b += a;
	a = b - a;
}