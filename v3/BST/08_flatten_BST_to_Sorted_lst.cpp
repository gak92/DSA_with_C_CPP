#include <bits/stdc++.h>
/************************************************************

    Following is the Binary Tree node structure

    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void inOrder(TreeNode<int> *root, vector<int> &v)
{
  if (root == NULL)
    return;

  inOrder(root->left, v);
  v.push_back(root->data);
  inOrder(root->right, v);
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
  vector<int> v;
  inOrder(root, v);

  int n = v.size();
  TreeNode<int> *newRoot = new TreeNode<int>(v[0]);
  TreeNode<int> *curr = newRoot;

  for (int j = 1; j < n; j++)
  {
    TreeNode<int> *temp = new TreeNode<int>(v[j]);
    curr->left = NULL;
    curr->right = temp;
    curr = temp;
  }

  curr->right = NULL;
  curr->left = NULL;

  return newRoot;
}
