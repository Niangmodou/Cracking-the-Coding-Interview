/*
Partition 2.4
Write Code to partition a linked list around a single value x, such that all nodes less than x come before all nodes greater than or equal to z.
*/
#include <iostream>

using namespace std;

struct Node{
  Node* next;
  int data;
  Node(int data = 0,Node* next = nullptr) : data(data){}
};


void printList(Node* head){
  if(!head) return;
  Node* p = head;
  while(p){
    cout << p->data << " ";
    p = p->next;
  }
  cout << endl;
}

void push_back(Node* head,int newData){
  if(head == nullptr){
    head = new Node(newData);
    return;
  }
  while(head->next){
    head = head->next;
  }
  Node* newNode = new Node(newData);
  head->next = newNode;
}

void deleteFirst(Node*& head){
  Node* delNode = head;
  head = head->next;
  delete delNode;
}

void partition(Node*& head, int x){
  Node* lessThan = new Node();
  Node* greaterThan = new Node();
  Node* p = head;

  while(p){
    if(p->data >= x) push_back(greaterThan,p->data);

    else push_back(lessThan, p->data);
    p = p->next;
  }
  deleteFirst(lessThan);
  deleteFirst(greaterThan);
  
  head = lessThan;
  while(lessThan->next) lessThan = lessThan->next;
  lessThan->next = greaterThan;
}

int main() {
  Node* head = new Node(3);
  push_back(head, 5);
  push_back(head, 8);
  push_back(head, 10);
  push_back(head, 2);
  push_back(head, 1);
  push_back(head, 6);
  push_back(head, 1);
  push_back(head, 9);
  cout << "Before: ";
  printList(head);
  cout << "After: ";
  partition(head,5);
  printList(head);

}