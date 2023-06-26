#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *left;
  Node *right;

  Node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

void inOrderTraversal(Node *root, vector<int> &arr)
{
  if (root == NULL)
    return;

  inOrderTraversal(root->left, arr);
  arr.push_back(root->data);
  inOrderTraversal(root->right, arr);
}

void preOrderTraversal(Node *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void printArray(vector<int> arr)
{
  cout << "Array elements: ";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void BSTToMinHeap(Node *root, vector<int> arr, int &i)
{
  if (root == NULL)
    return;

  root->data = arr[i];
  i += 1;
  BSTToMinHeap(root->left, arr, i);
  BSTToMinHeap(root->right, arr, i);
}

int main()
{
  Node *root = new Node(4);
  root->left = new Node(2);
  root->right = new Node(6);

  root->left->left = new Node(1);
  root->left->right = new Node(3);
  root->right->left = new Node(5);
  root->right->right = new Node(7);

  vector<int> arr;
  inOrderTraversal(root, arr);
  printArray(arr);

  int i = 0;
  BSTToMinHeap(root, arr, i);

  cout << "Pre Order Traversal: ";
  preOrderTraversal(root);
  cout << endl;

  return 0;
}