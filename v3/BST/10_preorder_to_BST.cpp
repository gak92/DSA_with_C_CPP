#include <bits/stdc++.h>
/*
    Following is the class structure of BinaryTreeNode class for referance:

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

        ~BinaryTreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
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

  ~BinaryTreeNode()
  {
    if (left)
    {
      delete left;
    }
    if (right)
    {
      delete right;
    }
  }
};

BinaryTreeNode<int> *solve(vector<int> &preorder, int mini, int maxi, int &j)
{
  if (j >= preorder.size())
    return NULL;

  if (preorder[j] < mini || preorder[j] > maxi)
    return NULL;

  BinaryTreeNode<int> *root = new BinaryTreeNode<int>(preorder[j++]);
  root->left = solve(preorder, mini, root->data, j);
  root->right = solve(preorder, root->data, maxi, j);
  return root;
}

BinaryTreeNode<int> *preorderToBST(vector<int> &preorder)
{
  // Write your code here.
  int mini = INT_MIN;
  int maxi = INT_MAX;
  int j = 0;

  return solve(preorder, mini, maxi, j);
}
