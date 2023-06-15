#include <bits/stdc++.h>
/*
    Following is the Binary Tree node structure:

    class BinaryTreeNode {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };
*/
template <typename T>
class BinaryTreeNode
{
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;

  BinaryTreeNode(T data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }
};

bool searchInBST(BinaryTreeNode<int> *root, int x)
{
  // Write your code here.
  // solution #2 - iterative
  BinaryTreeNode<int> *temp = root;

  while (temp != NULL)
  {
    if (temp->data == x)
      return true;

    if (temp->data > x)
      temp = temp->left;
    else
      temp = temp->right;
  }
  return false;

  // solution #1 - Recursive
  // if(root == NULL)
  //     return false;

  // if(root->data == x)
  //     return true;

  // if(root->data > x)
  //     return searchInBST(root->left, x);

  // else if (root->data < x)
  //     return searchInBST(root->right, x);
}