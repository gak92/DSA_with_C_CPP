/*
https://leetcode.com/problems/same-tree/description/

Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.



Example 1:


Input: p = [1,2,3], q = [1,2,3]
Output: true
Example 2:


Input: p = [1,2], q = [1,null,2]
Output: false
*/

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
#include <stdio.h>
#include <vector>
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

class Solution
{
public:
  // check if two trees are identical
  bool isSameTree(TreeNode *p, TreeNode *q)
  {
    // if both are null, trees are identical
    if (p == NULL && q == NULL)
      return true;
    // if one is null and other is not, trees are not identical
    if (p == NULL || q == NULL)
      return false;
    // if values are not same, trees are not identical
    if (p->val != q->val)
      return false;

    // check left and right subtrees recursively
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);

    // return true if both left and right subtrees are identical
    return left && right;
  }
};

int main()
{
  TreeNode *p = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode *q = new TreeNode(1, new TreeNode(2), new TreeNode(3));

  Solution s;
  bool result = s.isSameTree(p, q);
  printf("Result: %d\n", result);
  return 0;
}