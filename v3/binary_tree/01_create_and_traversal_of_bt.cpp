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

void inorderTraversal(node *root)
{
  if (root == NULL)
    return;

  inorderTraversal(root->left);
  cout << root->data << " ";
  inorderTraversal(root->right);
}

void inOrderiterative(node *root)
{
  stack<node *> st;
  node *curr = root;

  while (curr != NULL || !st.empty())
  {
    while (curr != NULL)
    {
      st.push(curr);
      curr = curr->left;
    }

    node *temp = st.top();
    st.pop();
    cout << temp->data << " ";
    curr = temp->right;
  }
}

void preOrderiterative(node *root)
{
  stack<node *> st;
  st.push(root);

  while (!st.empty())
  {
    node *temp = st.top();
    st.pop();

    cout << temp->data << " ";
    if (temp->right)
      st.push(temp->right);

    if (temp->left)
      st.push(temp->left);
  }
}

void postOrderiterative(node *root)
{
  stack<node *> st1, st2;
  st1.push(root);
  node *temp = NULL;

  while (!st1.empty())
  {
    temp = st1.top();
    st1.pop();
    st2.push(temp);

    if (temp->left)
      st1.push(temp->left);

    if (temp->right)
      st1.push(temp->right);
  }

  while (!st2.empty())
  {
    temp = st2.top();
    st2.pop();
    cout << temp->data << " ";
  }
}

void preorderTraversal(node *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preorderTraversal(root->left);
  preorderTraversal(root->right);
}

void postorderTraversal(node *root)
{
  if (root == NULL)
    return;

  postorderTraversal(root->left);
  postorderTraversal(root->right);
  cout << root->data << " ";
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

  cout << "\ninorder Traversal: ";
  inorderTraversal(root);

  cout << "\ninOrder iterative: ";
  inOrderiterative(root);

  cout << "\n\npreorder Traversal: ";
  preorderTraversal(root);

  cout << "\npreOrder iterative: ";
  preOrderiterative(root);

  cout << "\n\npostorder Traversal: ";
  postorderTraversal(root);

  cout << "\npostOrder iterative: ";
  postOrderiterative(root);

  return 0;
}