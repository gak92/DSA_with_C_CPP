/*
  https://www.codingninjas.com/codestudio/problems/middle-of-linked-list_973250
*/

#include<bits/stdc++.h>
using namespace std;

class Node
{
public:
  int data;
  Node *next;
  Node()
  {
    this->data = 0;
    next = NULL;
  }
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
  Node(int data, Node *next)
  {
    this->data = data;
    this->next = next;
  }
};

int getLength(Node *head)
{
  int length = 0;
  while (head != NULL)
  {
    length++;
    head = head->next;
  }
  return length;
}

Node *getMiddle(Node *head)
{
  if (head == NULL || head->next == NULL)
  {
    return head;
  }
  // if(head->next->next == NULL)
  // {
  //     return head->next;
  // }

  Node *slow = head;
  Node *fast = head->next;

  while (fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      fast = fast->next;
    }
    slow = slow->next;
  }
  return slow;
}

Node *findMiddle(Node *head)
{
  // Write your code here

  // Solution # 2
  return getMiddle(head);

  // Solution # 1
  // int length = getLength(head);
  // int mid = (length/2);

  // Node *temp = head;
  // int count = 0;
  // while(count < mid)
  // {
  //     temp = temp->next;
  //     count++;
  // }

  // return temp;
}

int main()
{


  return 0;
}