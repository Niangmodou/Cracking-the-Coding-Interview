/*
Remove Duplicates 2.1
Write code to remove duplicates from an unsorted linked list
*/
#include <iostream>
#include <set>

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


//Using set to track all unique elems
void removeDups(Node* head){
  if(!head) return;
  set<int> mySet;

  Node* prev = nullptr;
  Node* currNode = head;
  
  while(currNode){
    //Data not in set
    if(mySet.find(currNode->data) == mySet.end()){
      mySet.insert(currNode->data);
      prev = currNode;
    //Data in set
    }else{
      prev->next = currNode->next;
      delete currNode;
    }
    currNode = prev->next;
  }
}
// 1->1->1->4->1->2->5->null
int main() {
  Node* head = new Node(1);
  push_back(head, 1);
  push_back(head, 2);
  push_back(head, 1);
  push_back(head, 3);
  push_back(head, 4);
  push_back(head, 5);
  push_back(head, 1);
  push_back(head, 6);
  cout << "Before: ";
  printList(head);
  removeDups(head);
  cout << "After: ";
  printList(head);
}