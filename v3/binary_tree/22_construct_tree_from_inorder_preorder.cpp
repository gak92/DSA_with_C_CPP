//{ Driver Code Starts
//

#include <bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;

  Node(int x)
  {
    data = x;
    left = NULL;
    right = NULL;
  }
};

void printPostOrder(Node *root)
{
  if (root == NULL)
    return;
  printPostOrder(root->left);
  printPostOrder(root->right);
  cout << root->data << " ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution
{
private:
  void createMap(int in[], map<int, int> &nodeToindex, int n)
  {
    for (int j = 0; j < n; j++)
      nodeToindex[in[j]] = j;
  }

  int findPos(int in[], int start, int end, int element, int n)
  {
    for (int j = start; j <= end; j++)
    {
      if (element == in[j])
        return j;
    }
    return -1;
  }

  Node *solve(int in[], int pre[], int &preOrderindex, int inOrderStart, int inOrderEnd, int n)
  {
    if (preOrderindex >= n || inOrderStart > inOrderEnd)
    {
      return NULL;
    }

    int element = pre[preOrderindex++];
    Node *root = new Node(element);
    int position = findPos(in, inOrderStart, inOrderEnd, element, n);

    root->left = solve(in, pre, preOrderindex, inOrderStart, position - 1, n);
    root->right = solve(in, pre, preOrderindex, position + 1, inOrderEnd, n);

    return root;
  }

public:
  Node *buildTree(int in[], int pre[], int n)
  {
    // Code here
    int preOrderindex = 0;
    // map<int, int> nodeToindex;

    // createMap(in, nodeToindex, n);

    Node *res = solve(in, pre, preOrderindex, 0, n - 1, n);
    return res;
  }
};

//{ Driver Code Starts.
int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;

    int inorder[n], preorder[n];
    for (int i = 0; i < n; i++)
      cin >> inorder[i];
    for (int i = 0; i < n; i++)
      cin >> preorder[i];
    Solution obj;
    Node *root = obj.buildTree(inorder, preorder, n);
    printPostOrder(root);
    cout << endl;
  }
}

// } Driver Code Ends