/*
CRACKING THE CODE INTERVIEW: 10.1 Sorted Merge
Problem: You are given two sorted arrays, A and B where A has a large enough 
buffer at the end to hold B. Write a method to merge B into A in sorted order
*/
#include <iostream>
#include <vector>

using namespace std;

void merge(vector<int>&,vector<int>&,int,int);

int main(){
	vector<int> a{1,3,5,0,0,0};
	vector<int> b{2,4,6,0,0,0};

	merge(a,b,3,3);
}

void merge(vector<int>& A, vector<int>& B, int indA, int indB){
	int mergedInd = indA + indB - 1;
	indA--;
	indB--;

	while(indB >= 0){
	  	if((A[indA] > B[indB]) && (indA >= 0)){
	      		A[mergedInd] = A[indA];
	            --indA;
	       }else {
	            A[mergedInd] = B[indB];
	            --indB;
	        }
  		--mergedInd;
	}
}