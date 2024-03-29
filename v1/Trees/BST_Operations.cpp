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

struct node *iterativeSearch(struct node *root, int key)
{
  while (root != NULL)
  {
    if (key == root->data)
      return root;
    else if (key < root->data)
    {
      root = root->left;
    }
    else
    {
      root = root->right;
    }
  }
  return NULL;
}

void insert(struct node *root, int key)
{
  struct node *prev = NULL;
  while (root != NULL)
  {
    prev = root;
    if (key == root->data)
    {
      printf("Cannot insert duplicate element %d", key);
      return;
    }
    else if (key < root->data)
      root = root->left;
    else
      root = root->right;
  }
  struct node *newNode = createNode(key);
  if (key < prev->data)
    prev->left = newNode;
  else
    prev->right = newNode;
}

struct node *inOrderPredecessor(struct node *root)
{
  root = root->left;
  while (root->right != NULL)
  {
    root = root->right;
  }
  return root;
}

struct node *deleteNode(struct node *root, int value)
{
  struct node *iPre;
  if (root == NULL)
    return NULL;
  if (root->left == NULL && root->right == NULL)
  {
    free(root);
    return NULL;
  }

  // search for the node
  if (value < root->data)
    root->left = deleteNode(root->left, value);
  else if (value > root->data)
    root->right = deleteNode(root->right, value);
  else
  {
    iPre = inOrderPredecessor(root);
    root->data = iPre->data;
    root->left = deleteNode(root->left, iPre->data);
  }
  return root;
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

  // IS TREE BST
  // printf("\nIs tree BST: %d", isBST(p));

  // SEARCH IN BST
  // struct node *n = recursiveSearch(p, 6);
  // if (n != NULL)
  //   printf("\nElement Found: %d", n->data);
  // else
  //   printf("\nElement not Found");

  // struct node *m = iterativeSearch(p, 6);
  // if (m != NULL)
  //   printf("\nElement Found: %d", m->data);
  // else
  //   printf("\nElement not Found");

  // INSERTION IN BST
  // insert(p, 7);
  // printf("\nAfter insert: ");
  // inorder(p);

  // DELETION IN BST
  inorder(p);
  printf("\nAfter deletion:");
  deleteNode(p, 5);
  inorder(p);

  return 0;
}