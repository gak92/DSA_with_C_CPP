/*
https://leetcode.com/problems/binary-tree-preorder-traversal/description/

Given the root of a binary tree, return the preorder traversal of its nodes' values.



Example 1:


Input: root = [1,null,2,3]
Output: [1,2,3]
Example 2:

Input: root = []
Output: []
Example 3:

Input: root = [1]
Output: [1]


Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100


Follow up: Recursive solution is trivial, could you do it iteratively?

*/

/******************************************************************************/
/*
 * Definition for a binary tree node.
 */
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
  void preOrderRecursive(TreeNode *root, vector<int> &res)
  {
    if (root == NULL)
      return;
    res.push_back(root->val);
    preOrderRecursive(root->left, res);
    preOrderRecursive(root->right, res);
  }

  vector<int> preOrderIterative(TreeNode *root)
  {
    vector<int> res;
    if (root == NULL)
      return res;
    stack<TreeNode *> st;
    st.push(root);
    cout << st.top() << endl;

    while (!st.empty())
    {
      TreeNode *temp = st.top();
      cout << temp->val << endl;
      res.push_back(temp->val);
      st.pop();
      if (temp->right)
        st.push(temp->right);
      if (temp->left)
        st.push(temp->left);
    }
    return res;
  }

  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> res;
    // preOrderRecursive(root, res);
    res = preOrderIterative(root);
    return res;
  }
};

int main()
{
  Solution s;
  TreeNode *root = new TreeNode(1);
  root->right = new TreeNode(2);
  root->right->left = new TreeNode(3);
  vector<int> res = s.preorderTraversal(root);
  for (int i = 0; i < res.size(); i++)
  {
    cout << res[i] << " ";
  }
  cout << endl;
  return 0;
}