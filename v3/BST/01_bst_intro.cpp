#include <iostream>
#include <queue>
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

void levelOrderTraversal(Node *root)
{
  queue<Node *> q;
  q.push(root);
  q.push(NULL);

  cout << "Level Order Traversal: " << endl;
  while (!q.empty())
  {
    Node *temp = q.front();
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
  cout << endl;
}

void inOrderTraversal(Node *root)
{
  if (root == NULL)
    return;

  inOrderTraversal(root->left);
  cout << root->data << " ";
  inOrderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
  if (root == NULL)
    return;

  cout << root->data << " ";
  preOrderTraversal(root->left);
  preOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
  if (root == NULL)
    return;

  postOrderTraversal(root->left);
  postOrderTraversal(root->right);
  cout << root->data << " ";
}

Node *insertToBST(Node *root, int data)
{
  if (root == NULL)
  {
    root = new Node(data);
    return root;
  }

  if (data > root->data)
    root->right = insertToBST(root->right, data);
  else
    root->left = insertToBST(root->left, data);

  return root;
}

void takeinput(Node *&root)
{
  int data;
  cin >> data;

  while (data != -1)
  {
    root = insertToBST(root, data);
    cin >> data;
  }
}

int main()
{
  Node *root = NULL;

  cout << "Take input to create BST" << endl;
  takeinput(root);

  cout << "Prnt BST:" << endl;
  levelOrderTraversal(root);

  cout << "\ninOrder: ";
  inOrderTraversal(root);

  cout << "\npreOrder: ";
  preOrderTraversal(root);

  cout << "\npostOrder: ";
  postOrderTraversal(root);

  return 0;
}