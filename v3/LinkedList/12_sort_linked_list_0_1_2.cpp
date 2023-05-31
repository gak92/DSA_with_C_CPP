/*
  https://www.codingninjas.com/codestudio/problems/sort-linked-list-of-0s-1s-2s_1071937
*/

#include <bits/stdc++.h>

/********************************
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

********************************/

class Node
{
public:
  int data;
  Node *next;
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }
};

void insertAtTail(Node *&tail, Node *curr)
{
  tail->next = curr;
  tail = tail->next;
}

Node *sortList(Node *head)
{
  // Write your code here.

  // Solution # 2 - By changing links
  Node *zeroHead = new Node(-1);
  Node *zeroTail = zeroHead;
  Node *oneHead = new Node(-1);
  Node *oneTail = oneHead;
  Node *twoHead = new Node(-1);
  Node *twoTail = twoHead;
  Node *curr = head;

  // create 3 sublist - 0s, 1s, 2s
  while (curr != NULL)
  {
    if (curr->data == 0)
    {
      insertAtTail(zeroTail, curr);
    }
    else if (curr->data == 1)
    {
      insertAtTail(oneTail, curr);
    }
    else if (curr->data == 2)
    {
      insertAtTail(twoTail, curr);
    }

    curr = curr->next;
  }

  // merge 3 sublist
  if (oneHead->next != NULL)
  {
    zeroTail->next = oneHead->next;
  }
  else
  {
    zeroTail->next = twoHead->next;
  }

  oneTail->next = twoHead->next;
  twoTail->next = NULL;

  head = zeroHead->next;

  delete zeroHead;
  delete oneHead;
  delete twoHead;

  return head;

  //================================ Solution # 1
  /*
  int count[3] = {0,0,0};
  Node* curr = head;

  while(curr != NULL)
  {
      count[curr->data]++;
      curr = curr->next;
  }

  curr = head;
  for(int i=0; i<3; i++)
  {
      for(int j=0; j<count[i]; j++)
      {
          curr->data = i;
          curr = curr->next;
      }
  }

  return head;
  */
}

int main()
{

  return 0;
}