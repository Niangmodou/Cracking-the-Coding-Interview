/*
CRACKING THE CODING INTERVIEW: 8.1 Triple Step
Problem: A child is running up a staircase with n steps and can hop 
either 1 step, 2 steps, or 3 steps at a time. Implement a method to 
count how many possible ways the child can run up the stairs.
*/
#include <iostream>
#include <vector>

using namespace std;

int tripleStepRecurr(int);
int tripleStepMemo(int);
int tripleStepHelper(int,vector<int>&);

int main(){

	cout << tripleStepRecurr(4) << endl;

	cout << tripleStepMemo(7) << endl;
	cout << tripleStepMemo(11) << endl;
	
}

//Recursive:
int tripleStepRecurr(int n){
	if(n == 0) return 1;
	else if(n < 0) return 0;
	else return tripleStepRecurr(n-1) +
			    tripleStepRecurr(n-2) + 
				tripleStepRecurr(n-3);
} 

//Memoized:
int tripleStepMemo(int n){
	vector<int> memo = vector<int>(n+1,-1);
	return tripleStepHelper(n,memo);
}

int tripleStepHelper(int n, vector<int>& memo){
	if(n == 0) return 1;
	else if(n < 0) return 0;
	else if(memo[n] != -1) return memo[n];
	else{
	memo[n] = tripleStepHelper(n-1,memo) + 
			  tripleStepHelper(n-2,memo) + 
			  tripleStepHelper(n-3,memo);
	return memo[n];
	}
}

