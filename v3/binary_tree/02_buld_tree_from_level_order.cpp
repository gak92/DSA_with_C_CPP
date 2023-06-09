#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node
{
public:
  int data;
  node *left;
  node *right;

  node(int data)
  {
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

node *buildTree(node *root)
{
  cout << "Enter the data: ";
  int data;
  cin >> data;
  root = new node(data);

  if (data == -1)
  {
    return NULL;
  }

  cout << "Enter the data for inserting in left of " << data << ": ";
  root->left = buildTree(root->left);

  cout << "Enter the data for insertng in right of " << data << ": ";
  root->right = buildTree(root->right);

  return root;
}

void levelOrderTraversal(node *root)
{
  queue<node *> q;
  q.push(root);
  q.push(NULL); // just to get next line seperator

  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();

    if (temp == NULL)
    {
      cout << endl;
      if (!q.empty())
        q.push(NULL);
    }
    else
    {
      cout << temp->data << " ";
      if (temp->left)
        q.push(temp->left);

      if (temp->right)
        q.push(temp->right);
    }
  }
}

void buildFromLevelOrderTraversal(node *&root)
{
  queue<node *> q;
  cout << "Enter data for root: ";
  int data;
  cin >> data;
  root = new node(data);
  q.push(root);

  while (!q.empty())
  {
    node *temp = q.front();
    q.pop();

    cout << "Enter left node for " << temp->data << " : ";
    int leftData;
    cin >> leftData;
    if (leftData != -1)
    {
      temp->left = new node(leftData);
      q.push(temp->left);
    }

    cout << "Enter right node for " << temp->data << " : ";
    int rightData;
    cin >> rightData;
    if (rightData != -1)
    {
      temp->right = new node(rightData);
      q.push(temp->right);
    }
  }
}

int main()
{
  node *root = NULL;
  // creating tree
  // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
  /*
                  1
          3                 5
      7       11       17
  */
  // root = buildTree(root);

  // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1
  buildFromLevelOrderTraversal(root);

  // level Order Traversal
  cout << "\nLevel Order Traversal: " << endl;
  levelOrderTraversal(root);

  return 0;
}