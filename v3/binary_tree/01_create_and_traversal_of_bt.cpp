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
  root = buildTree(root);

  // level Order Traversal
  cout << "\nLevel Order Traversal: " << endl;
  levelOrderTraversal(root);

  return 0;
}