/*
CRACKING THE CODE INTERVIEW: Minimal Tree 4.2

Problem: Given a sorted(increasing order)array with unique integer elements, 
write an algorithm to create a binary search tree with minimal height
*/
#include <iostream>
#include <vector>

using namespace std;

struct Node{
  Node(int data, Node* right = nullptr, Node* left = nullptr) :
   			data(data), right(right), left(left){} 
  Node* left;
  Node* right;
  int data;
};

Node* minimalTree(vector<int>&);

int main(){

	vector<int> arr{1,2,3,4,5,6,7};
	Node* bst = minimalTree(arr);

	vector<int> arr1{1,2,3,4,5,6};
	Node* bst1 = minimalTree(arr1);

	cout << "Run Finished" << endl;
}

Node* minimalTree(vector<int>& arr){
	if(arr.size() == 0) return nullptr;

	int mid = arr.size()/2;

	Node* root = new Node(arr[mid]);

	vector<int> leftArr = vector<int>(arr.begin(),arr.begin()+mid);
	vector<int> rightArr = vector<int>(arr.begin()+mid+1, arr.end());

	root->left = minimalTree(leftArr);
	root->right = minimalTree(rightArr);

	return root;
}
