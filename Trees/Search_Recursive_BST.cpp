#include <stdio.h>
#include <malloc.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data)
{
  struct node *n = (struct node *)malloc(sizeof(struct node));
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void inorder(struct node *root)
{
  if (root != NULL)
  {
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
  }
}

int isBST(struct node *root) // 5
{
  static struct node *prev = NULL; //  prev = NULL
  if (root != NULL)
  {
    if (!isBST(root->left))
    {
      return 0;
    }
    if (prev != NULL && root->data <= prev->data)
    {
      return 0;
    }
    prev = root;
    return isBST(root->right);
  }
  else
  {
    return 1;
  }
}

struct node *recursiveSearch(struct node *root, int key)
{
  if (root == NULL)
    return NULL;
  if (root->data == key)
    return root;
  else if (key < root->data)
  {
    return recursiveSearch(root->left, key);
  }
  else
  {
    return recursiveSearch(root->right, key);
  }
}

int main()
{
  struct node *p = createNode(5);
  struct node *p1 = createNode(3);
  struct node *p2 = createNode(6);
  struct node *p3 = createNode(1);
  struct node *p4 = createNode(4);

  //        5
  //      /   \
  //     3     6
  //    / \
  //   1   4

  p->left = p1;
  p->right = p2;
  p1->left = p3;
  p1->right = p4;

  // printf("\nInOrder Traversal: ");
  // inorder(p);

  // printf("\nIs tree BST: %d", isBST(p));

  struct node *n = recursiveSearch(p, 6);

  if (n != NULL)
  {
    printf("Element Found: %d", n->data);
  }
  else
  {
    printf("Element not Found");
  }

  return 0;
}