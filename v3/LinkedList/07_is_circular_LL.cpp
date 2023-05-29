/*
  https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232

*/

bool isCircular(Node *head)
{
  // Write your code here.

  // floyd cycle detection
  if (head == NULL)
    return true;

  if (head->next == NULL)
    return false;

  Node *slow = head;
  Node *fast = head;

  while (slow != NULL && fast != NULL)
  {
    fast = fast->next;
    if (fast != NULL)
    {
      fast = fast->next;
    }

    slow = slow->next;
    if (slow == fast)
      break;
  }

  if (slow == fast && slow == head)
    return true;
  return false;

  /*
      if(head == NULL)
          return true;

      Node* temp = head;
      map<Node*, bool> visited;

      while(temp != NULL)
      {
          if(visited[temp])
              return true;

          visited[temp] = true;
          temp = temp->next;
      }

      return false;
  */

  /*
  if(head == NULL)
      return true;

  Node* temp = head->next;

  while(temp != NULL && temp != head)
  {
      temp = temp->next;
  }

  if(temp == head)
      return true;
  else
      return false;
  */

  /*
  if(head == NULL)
      return true;

  Node* slow = head;
  Node* fast = head->next;

  while(fast != NULL && fast->next != NULL)
  {
      if(slow == fast)
          return true;

      slow = slow->next;
      fast = fast->next->next;
  }
  return false;
  */
}
