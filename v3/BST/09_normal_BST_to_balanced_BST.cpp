/*************************************************************
    Following is the Binary Serach Tree node structure

    template <typename T>
    class TreeNode
    {
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
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };

*************************************************************/
void inOrder(TreeNode<int> *root, vector<int> &v)
{
  if (root == NULL)
    return;

  inOrder(root->left, v);
  v.push_back(root->data);
  inOrder(root->right, v);
}

TreeNode<int> *inOrderToBST(int start, int end, vector<int> v)
{
  if (start > end)
    return NULL;

  int mid = (start + end) / 2;
  TreeNode<int> *root = new TreeNode<int>(v[mid]);
  root->left = inOrderToBST(start, mid - 1, v);
  root->right = inOrderToBST(mid + 1, end, v);

  return root;
}

TreeNode<int> *balancedBst(TreeNode<int> *root)
{
  // Write your code here.
  vector<int> v;
  inOrder(root, v);
  int n = v.size();

  return inOrderToBST(0, n - 1, v);
}
