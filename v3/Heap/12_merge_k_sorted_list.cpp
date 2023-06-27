/************************************************************

    Following is the linked list node structure

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
#include <bits/stdc++.h>
class compare
{
public:
  bool operator()(Node<int> *a, Node<int> *b)
  {
    return a->data > b->data;
  }
};

Node<int> *mergeKLists(vector<Node<int> *> &listArray)
{
  // Write your code here.
  priority_queue<Node<int> *, vector<Node<int> *>, compare> minheap;
  int k = listArray.size();

  for (int i = 0; i < k; i++)
  {
    if (listArray[i] != NULL)
      minheap.push(listArray[i]);
  }

  Node<int> *head = NULL;
  Node<int> *tail = NULL;

  while (!minheap.empty())
  {
    Node<int> *temp = minheap.top();
    minheap.pop();

    if (head == NULL)
    {
      head = temp;
      tail = temp;
      if (tail->next != NULL)
        minheap.push(tail->next);
    }
    else
    {
      tail->next = temp;
      tail = temp;
      if (tail->next != NULL)
        minheap.push(tail->next);
    }
  }

  return head;
}
