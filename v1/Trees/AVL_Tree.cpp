#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *left;
  struct Node *right;
  int height;
};

int getHeight(struct Node *n)
{
  if (n == NULL)
    return 0;
  return n->height;
}

struct Node *createNode(int key)
{
  struct Node *node = (struct Node *)malloc(sizeof(struct Node));
  node->data = key;
  node->left = NULL;
  node->right = NULL;
  node->height = 1;
  return node;
}

int getBalanceFactor(struct Node *n)
{
  if (n == NULL)
    return 0;
  return getHeight(n->left) - getHeight(n->right);
}

int max(int a, int b)
{
  return a > b ? a : b;
}

struct Node *rightRotate(struct Node *y)
{
  struct Node *x = y->left;
  struct Node *T2 = x->right;

  x->right = y;
  y->left = T2;

  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

  return x;
}

struct Node *leftRotate(struct Node *x)
{
  struct Node *y = x->right;
  struct Node *T2 = y->left;

  y->left = x;
  x->right = T2;

  y->height = max(getHeight(y->right), getHeight(y->left)) + 1;
  x->height = max(getHeight(x->right), getHeight(x->left)) + 1;

  return y;
}

struct Node *insert(struct Node *node, int key)
{
  if (node == NULL)
    return createNode(key);
  if (key < node->data)
    node->left = insert(node->left, key);
  else if (key > node->data)
  {
    node->right = insert(node->right, key);
    // return node;
  }

  node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
  int bf = getBalanceFactor(node);

  // Left Left
  if (bf > 1 && key < node->left->data)
    return rightRotate(node);

  // Right Right
  if (bf < -1 && key < node->right->data)
    return leftRotate(node);

  // Left Right
  if (bf > 1 && key > node->left->data)
  {
    node->left = leftRotate(node->left);
    return rightRotate(node);
  }

  // Right Left
  if (bf < -1 && key < node->right->data)
  {
    node->right = rightRotate(node->right);
    return leftRotate(node);
  }

  return node;
}

void preorder(struct Node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
  }
}

int main()
{
  struct Node *root = NULL;
  root = insert(root, 1);
  root = insert(root, 2);
  root = insert(root, 4);
  root = insert(root, 5);
  root = insert(root, 6);
  root = insert(root, 3);

  preorder(root);

  return 0;
}