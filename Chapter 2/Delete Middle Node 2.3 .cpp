/*
Delete Middle Node 2.3
Implement an algorithm to delete a node in the middle(any node 
but the first or last node) of a singly linked list, given only 
access to that node
*/
#include <iostream>

using namespace std;

struct Node{
  Node* next;
  int data;
  Node(int data,Node* next = nullptr) : data(data){}
};

Node* MIDNODE = new Node(0);

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

void delMidNode(Node* head, Node* midNode){
  Node* prev = nullptr;
  Node* currNode = head;

  while(currNode->next){
    if(currNode == midNode) 
      prev->next = currNode->next;
    prev = currNode;
    currNode = currNode->next;
  }
}

int main() {
  Node* head = new Node(0);
  push_back(head, 1);
  push_back(head, 2);
  push_back(head, 3);
  push_back(head, 4);
  push_back(head, 5);
  push_back(head, 6);
  push_back(head, 7);
  push_back(head, 8);
  cout << "Before: ";
  printList(head);
  cout << "After: ";
  delMidNode(head, MIDNODE);
  printList(head);
  
  
}