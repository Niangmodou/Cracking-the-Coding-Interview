/*
Remove Duplicates 2.2
Implement an algorithm to find the k-th to last elemnt of a singly linked list
*/
#include <iostream>

using namespace std;

struct Node{
  Node* next;
  int data;
  Node(int data,Node* next = nullptr) : data(data){}
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
}

int kthToLast(Node* head,int k){
  int n = 0;
  int pos;
  Node* p = head;
  while(p->next){
    p = p->next;
    n++;
  }
  p = head;
  pos = n-k;
  for(int i = 0;i < pos; ++i){
    p = p->next;
  }
  return p->data;
}

int main() {
  Node* head = new Node(1);
  push_back(head, 1);
  push_back(head, 2);
  push_back(head, 3);
  push_back(head, 4);
  push_back(head, 5);
  push_back(head, 6);
  push_back(head, 7);
  push_back(head, 8);
  cout << "List: ";
  
  cout << "Kth to Last: " << kthToLast(head,5);
  
}