#include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }
    };

*************************************************************/

class TreeNode
{

public:
  int data;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int data)
  {
    this->data = data;
    left = NULL;
    right = NULL;
  }

  ~TreeNode()
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

void inOrder(TreeNode<int> *root, vector<int> &v)
{
  if (root == NULL)
    return;

  inOrder(root->left, v);
  v.push_back(root->data);
  inOrder(root->right, v);
}

vector<int> mergeArray(vector<int> a, vector<int> b)
{
  vector<int> res(a.size() + b.size());

  int i = 0, j = 0, k = 0;
  while (i < a.size() && j < b.size())
  {
    if (a[i] < b[j])
    {
      res[k++] = a[i];
      i++;
    }
    else
    {
      res[k++] = b[j];
      j++;
    }
  }

  while (i < a.size())
  {
    res[k++] = a[i];
    i++;
  }
  while (j < b.size())
  {
    res[k++] = b[j];
    j++;
  }
  return res;
}

TreeNode<int> *inOrderToBST(int start, int end, vector<int> &in)
{
  if (start > end)
    return NULL;

  int mid = (start + end) / 2;
  TreeNode<int> *temp = new TreeNode<int>(in[mid]);
  temp->left = inOrderToBST(start, mid - 1, in);
  temp->right = inOrderToBST(mid + 1, end, in);

  return temp;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
  // step #1 - BST to inOrder
  vector<int> inorder1, inorder2;
  inOrder(root1, inorder1);
  inOrder(root2, inorder2);

  // step #2 - Merge two Array/Vector
  vector<int> merged = mergeArray(inorder1, inorder2);

  // step #3 - inOrder(Array) to BST
  TreeNode<int> *newRoot = inOrderToBST(0, merged.size() - 1, merged);
  return newRoot;
}
