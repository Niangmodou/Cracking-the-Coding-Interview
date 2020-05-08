/*
Delete Middle Node 2.5
You have two number represented by linked list, 
where each node contains a single digit. The digits
are stored in reverse order, such that the 1's digit
is at the head of the list. Write a function that adds
the two numbers and returns the sum as a linked list.
*/
#include <iostream>

using namespace std;

struct Node{
  Node* next;
  int data;
  Node(int data = 0,Node* next = nullptr) : data(data){}
};


void printList(Node* head){
  Node* p = head;
  while(p){
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

void push_back(Node* head,int newData){
  while(head->next){
    head = head->next;
  }
  Node* newNode = new Node(newData);
  head->next = newNode;

  if(newData == 5) MIDNODE = newNode;
}

void sumLists(Node* lst1, Node* lst2){
	Node* p1 = lst1;
	Node* p2 = lst2;
	Node* newLst = new Node();
	Node* carry = 0;

	while(p1->next && p2->next){
		int curr = p1->data + p2->data + carry;
		if(carry != 0) carry = 0;
		if(curr < 10) push_back(newLst, curr);
		else{
			push_back(newLst,curr%10);
			carry = curr/10;
		}
		p1 = p1->next;
		p2 = p2->next;
	}

	while(p1){
		push_back(newLst,p1->data);
		p1 = p1->next;
	}
	while(p2){
		push_back(newLst);
		p2 = p2->next;
	}
}

int main() {
  Node* l1 = new Node(7);
  push_back(l1, 1);
  push_back(l1, 6);
  cout << "List1: ";
  printList(l1);

  Node* l2 = new Node(5);
  push_back(l2, 9);
  push_back(l2, 2);
  cout << "List2: ";
  printList(l2);

  cout << "lst1 + lst2:  ";
  Node* newLst = sumLists(l1,l2);
  printList(newLst);
}