// This problem was asked by Google.

// An XOR linked list is a more memory efficient doubly linked list. Instead of
// each node holding next and prev fields, it holds a field named both, which is an
// XOR of the next node and the previous node. Implement an XOR linked list; it has
// an add(element) which adds the element to the end, and a get(index) which
// returns the node at index.

#include <bits/stdc++.h>
#include <cinttypes>
using namespace std;

class Node {
  public : int data;
  Node* xnode;
};

Node* Xor(Node* x, Node* y) {
  return reinterpret_cast<Node*>(
    reinterpret_cast<uintptr_t>(x) ^ reinterpret_cast<uintptr_t>(y)
  );
}

void insert(Node** head_ref, int data) {
  Node* newNode = new Node();
  newNode -> data = data;

  newNode -> xnode = Xor(*head_ref, NULL);

  if (*head_ref != NULL) {
    (*head_ref) -> xnode = Xor(newNode, (*head_ref) -> xnode);
  }

  *head_ref = newNode;
}

Node* returnToFront(Node* head) {
  Node* curr = head;
  Node* prev = NULL;
  Node *next;

  while (curr != NULL) {
    next = Xor(prev, curr -> xnode);
    prev = curr;
    curr = next;
  }
  return prev;
}

void add(Node* head, int newbie) {
  head = returnToFront(head);
  insert(&head, newbie);
}

void printIndex(Node* head, int idx) {
  cout << "Head value = " << head -> data << "\n";
  Node* curr = head;
  Node* prev = NULL;
  Node* next;
  int cnt = 0;
  while (curr != NULL)
  {
    if (cnt == idx) {
      cout << "Node found, value = " << curr -> data << "\n";
      return;
    }
    cnt++;
    next = Xor(prev, curr -> xnode);
    prev = curr;
    curr = next;
  }
  
} 

int main() {
  int testcases;
  cin >> testcases;
  for (int testcase = 0; testcase < testcases; testcase++) {
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 100);
    insert(&head, 1000);
    insert(&head, 10000);
 
    head = returnToFront(head);

    printIndex(head, 1);

    add(head, 15000);

    printIndex(head, 4);
  }
  return 0;
}