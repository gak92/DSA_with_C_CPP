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

Node *inOrderSuccessor(Node *root, int val)
{
  Node *successor = NULL;
  Node *curr = root;

  while (curr != NULL)
  {
    if (val >= curr->data)
    {
      curr = curr->right;
    }
    else
    {
      successor = curr;
      curr = curr->left;
    }
  }
  return successor;
}

Node *inOrderPredecessor(Node *root, int val)
{
  Node *predecessor = NULL;
  Node *curr = root;

  while (curr != NULL)
  {
    if (val <= curr->data)
    {
      curr = curr->left;
    }
    else
    {
      predecessor = curr;
      curr = curr->right;
    }
  }
  return predecessor;
}

Node *minValue(Node *root)
{
  Node *temp = root;
  while (temp->left != NULL)
  {
    temp = temp->left;
  }
  return temp;
}

Node *maxValue(Node *root)
{
  Node *temp = root;
  while (temp->right != NULL)
  {
    temp = temp->right;
  }
  return temp;
}

Node *deleteFromBST(Node *root, int val)
{
  if (root == NULL)
    return root;

  if (root->data == val)
  {
    // 0 child
    if (root->left == NULL && root->right == NULL)
    {
      delete root;
      return NULL;
    }

    // 1 child
    // left child
    if (root->left != NULL && root->right == NULL)
    {
      Node *temp = root->left;
      delete root;
      return temp;
    }

    // right child
    if (root->left == NULL && root->right != NULL)
    {
      Node *temp = root->right;
      delete root;
      return temp;
    }

    // 2 child
    if (root->left != NULL && root->right != NULL)
    {
      int min = minValue(root->right)->data;
      root->data = min;
      root->right = deleteFromBST(root->right, min);
      return root;
    }
  }

  else if (root->data > val)
  {
    root->left = deleteFromBST(root->left, val);
    return root;
  }

  else
  {
    root->right = deleteFromBST(root->right, val);
    return root;
  }
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
  // 50 20 70 10 30 90 110 -1
  takeinput(root);

  cout << "Prnt BST:" << endl;
  levelOrderTraversal(root);

  cout << "\ninOrder: ";
  inOrderTraversal(root);

  cout << "\npreOrder: ";
  preOrderTraversal(root);

  cout << "\npostOrder: ";
  postOrderTraversal(root);

  cout << "\nMin Value: " << minValue(root)->data << endl;
  cout << "\nMax Value: " << maxValue(root)->data << endl;

  cout << "\nSuccessor: " << inOrderSuccessor(root, 30)->data << endl;
  cout << "\nPredecessor: " << inOrderPredecessor(root, 30)->data << endl;

  // Deletion
  root = deleteFromBST(root, 50);

  cout << "Prnt BST:" << endl;
  levelOrderTraversal(root);

  return 0;
}