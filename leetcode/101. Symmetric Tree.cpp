/*

https://leetcode.com/problems/symmetric-tree/description/

Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).


Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false


Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100


Follow up: Could you solve it both recursively and iteratively?
*/

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution
{
public:
  bool dfs(TreeNode *left, TreeNode *right)
  {
    if (!left && !right)
      return true;
    if (!left || !right)
      return false;

    bool l, r;

    if (left->val == right->val)
    {
      l = dfs(left->left, right->right);
      r = dfs(left->right, right->left);
    }
    return l && r;
  }

  bool isSymmetric(TreeNode *root)
  {

    // Recursive Solution
    // if(!root) return true;
    // return dfs(root->left, root->right);

    // Iterative Solution
    queue<TreeNode *> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty())
    {
      TreeNode *left = q.front();
      q.pop();
      TreeNode *right = q.front();
      q.pop();

      if (!left && !right)
        continue;
      if (!left || !right)
        return false;
      if (left->val != right->val)
        return false;

      q.push(left->left);
      q.push(right->right);
      q.push(left->right);
      q.push(right->left);
    }

    return true;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1, new TreeNode(2, new TreeNode(3), new TreeNode(4)), new TreeNode(2, new TreeNode(4), new TreeNode(3)));
  Solution s;
  cout << s.isSymmetric(root) << endl;
  return 0;
}