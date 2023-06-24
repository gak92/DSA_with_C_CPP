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

void convertedIntoSortedDLL(TreeNode<int> *root, TreeNode<int> *&head)
{
  if (root == NULL)
    return;

  convertedIntoSortedDLL(root->right, head);

  root->right = head;
  if (head != NULL)
    head->left = root;
  head = root;

  convertedIntoSortedDLL(root->left, head);
}

TreeNode<int> *mergeLinkedList(TreeNode<int> *head1, TreeNode<int> *head2)
{
  TreeNode<int> *head = NULL;
  TreeNode<int> *tail = NULL;

  while (head1 != NULL && head2 != NULL)
  {
    if (head1->data < head2->data)
    {
      if (head == NULL)
      {
        head = head1;
        tail = head1;
        head1 = head1->right;
      }
      else
      {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
      }
    }
    else
    {
      if (head == NULL)
      {
        head = head2;
        tail = head2;
        head2 = head2->right;
      }
      else
      {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
      }
    }
  }

  while (head1 != NULL)
  {
    tail->right = head1;
    head1->left = tail;
    tail = head1;
    head1 = head1->right;
  }
  while (head2 != NULL)
  {
    tail->right = head2;
    head2->left = tail;
    tail = head2;
    head2 = head2->right;
  }
  return head;
}

int count(TreeNode<int> *head)
{
  TreeNode<int> *temp = head;
  int cnt = 0;
  while (temp != NULL)
  {
    cnt++;
    temp = temp->right;
  }
  return cnt;
}

TreeNode<int> *SortedLLToBST(TreeNode<int> *&head, int n)
{
  if (n <= 0 || head == NULL)
    return NULL;

  TreeNode<int> *left = SortedLLToBST(head, n / 2);
  TreeNode<int> *root = head;
  root->left = left;

  head = head->right;
  root->right = SortedLLToBST(head, n - n / 2 - 1);
  return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
  // Solution # 1
  /*
  // step #1 - BST to inOrder
  vector<int> inorder1, inorder2;
  inOrder(root1, inorder1);
  inOrder(root2, inorder2);

  // step #2 - Merge two Array/Vector
  vector<int> merged = mergeArray(inorder1, inorder2);

  // step #3 - inOrder(Array) to BST
  TreeNode<int>* newRoot = inOrderToBST(0, merged.size()-1, merged);
  return newRoot;
  */

  // Solution # 2
  // step # 1 BST to LL (in-place)
  TreeNode<int> *head1 = NULL;
  convertedIntoSortedDLL(root1, head1);
  head1->left = NULL;

  TreeNode<int> *head2 = NULL;
  convertedIntoSortedDLL(root2, head2);
  head2->left = NULL;

  // step # 2 - merge two Linked List
  TreeNode<int> *merged = mergeLinkedList(head1, head2);

  // step # 3 - Linked List to BST
  return SortedLLToBST(merged, count(merged));
}
