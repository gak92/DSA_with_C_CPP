/*

*/

#include <bits/stdc++.h>

/********************************************************************

    Following is the representation of the Singly Linked List Node:

    class node{
        public:
            int data;
            node * next;
            node(int data){
                this->data=data;
                this->next=NULL;
            }
    };

********************************************************************/

class node
{
public:
  int data;
  node *next;
  node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

node *findMid(node *head)
{
  node *slow = head;
  node *fast = head->next;

  while (fast != NULL && fast->next != NULL)
  {
    slow = slow->next;
    fast = fast->next->next;
  }
  return slow;
}

node *merge(node *left, node *right)
{
  if (left == NULL)
    return right;
  if (right == NULL)
    return left;

  node *res = new node(-1);
  node *temp = res;

  while (left != NULL && right != NULL)
  {
    if (left->data <= right->data)
    {
      temp->next = left;
      left = left->next;
      temp = temp->next;
    }
    else
    {
      temp->next = right;
      right = right->next;
      temp = temp->next;
    }
  }
  while (left != NULL)
  {
    temp->next = left;
    left = left->next;
    temp = temp->next;
  }
  while (right != NULL)
  {
    temp->next = right;
    right = right->next;
    temp = temp->next;
  }
  res = res->next;
  return res;
}

node *mergeSort(node *head)
{
  // Write your code here.
  // base case
  if (head == NULL || head->next == NULL)
    return head;

  // break linked list into two halves
  node *mid = findMid(head);

  node *left = head;
  node *right = mid->next;
  mid->next = NULL;

  // recursve call
  left = mergeSort(left);
  right = mergeSort(right);

  // merge both parts
  node *res = merge(left, right);
  return res;
}

int main()

{

  return 0;
}