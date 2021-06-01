// Given the root to a binary tree, implement serialize(root), which serializes the tree into a string, 
// and deserialize(s), which deserializes the string back into the tree.

// For example, given the following Node class

// class Node:
//     def __init__(self, val, left=None, right=None):
//         self.val = val
//         self.left = left
//         self.right = right

// The following test should pass:

// node = Node('root', Node('left', Node('left.left')), Node('right'))
// assert deserialize(serialize(node)).left.left.val == 'left.left'

#include <bits/stdc++.h>
using namespace std;

// define a node
struct Node {
  int val;
  struct Node *left, *right;
};

// initialise node
Node* newNode(int key) {
  Node *temp = new Node;
  temp -> val = key;
  temp -> left = temp -> right = NULL;
  return temp;
}

// following preorder traversal of tree, i.e., root > left > right
string serialize(Node *root) {
  if (root == NULL) {
    return "#";
  }
  string s = to_string(root -> val) + " " + serialize(root -> left) + " " + serialize(root -> right);
  return s;
}

void deserialize(Node *root, string s) {
  
}

int main() {
  
  return 0;
}