/*
  https://www.codingninjas.com/codestudio/problems/reverse-list-in-k-groups_983644
*/

Node *kReverse(Node *head, int k)
{
  // Write your code here.
  // base case
  if (head == NULL)
    return NULL;

  // Reverse first k nodes
  Node *prev = NULL;
  Node *curr = head;
  Node *forward = NULL;
  int count = 0;

  while (curr != NULL && count < k)
  {
    forward = curr->next;
    curr->next = prev;
    prev = curr;
    curr = forward;
    count++;
  }

  // Recursion call
  if (forward != NULL)
  {
    head->next = kReverse(forward, k);
  }

  // return head of reversed linked list
  return prev;
}