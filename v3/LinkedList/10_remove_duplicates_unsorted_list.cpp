#include <bits/stdc++.h>

/****************************************************************
    Following is the class structure of the Node class:
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
*****************************************************************/
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

Node *removeDuplicates(Node *head)
{
  // Write your code here

  //**************************************************************
  // Solution # 3 - O(n) (Time Limit exceed for few test cases)
  // use mappings
  // if(head == NULL)
  //     return NULL;

  // Node* prev = NULL;
  // Node* curr = head;
  // map<int, int> visited;

  // while(curr != NULL)
  // {
  //     if(!visited[curr->data])
  //     {
  //         visited[curr->data] = 1;
  //         prev = curr;
  //         curr = curr->next;
  //     }
  //     else
  //     {
  //         Node* nodeToDelete = curr;
  //         prev->next = curr->next;
  //         delete nodeToDelete;
  //         curr = curr->next;

  //     }
  // }
  // return head;

  ///////////////////////////////////////////////

  Node *current = head;
  Node *prev = NULL;
  unordered_map<int, int> visited;

  if (current == NULL)
  {
    return NULL;
  }

  while (current != NULL)
  {
    if (!visited[current->data])
    {
      visited[current->data] = 1;

      prev = current;
      current = current->next;
    }
    else
    {
      Node *nextNode = current->next;
      prev->next = nextNode;

      delete (current);
      current = nextNode;
    }
  }

  return head;
  //////////////////////////////////////////////

  //**************************************************************
  // Solution # 2 - O(nlogn)
  // Sort list first and then remove duplicate

  //**************************************************************
  // Solution #1 - O(n^2) (Time Limit Exceed)
  /*
  Node* curr = head;

  while(curr != NULL)
  {
      Node* temp = curr;

      while(temp->next != NULL)
      {
          if( curr->data == temp->next->data)
          {
              Node* nodeToDelete = temp->next;
              temp->next = temp->next->next;
              delete nodeToDelete;

          }
          else
          {
              temp = temp->next;
          }
      }

      curr = curr->next;
  }
  return head;
  */
}

int main()
{

  return 0;
}
