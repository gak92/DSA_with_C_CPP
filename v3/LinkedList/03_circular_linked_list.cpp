#include <iostream>
using namespace std;

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

  ~Node()
  {
    int value = this->data;
    if (this->next != NULL)
    {
      delete next;
      next = NULL;
    }
    cout << "Free memory for node with data " << value << endl;
  }
};

void insertNode(Node *&tail, int element, int data)
{
  if (tail == NULL)
  {
    // empty list
    Node *newNode = new Node(data);
    tail = newNode;
    newNode->next = newNode;
  }
  else
  {
    // non empty list
    Node *curr = tail;
    while (curr->data != element)
    {
      curr = curr->next;
    }

    // element found in curr node
    Node *newNode = new Node(data);
    newNode->next = curr->next;
    curr->next = newNode;
  }
}

void deleteNode(Node *&tail, int value)
{
  if (tail == NULL)
  {
    cout << "List is empty, please check again." << endl;
    return;
  }
  else
  {
    Node *prev = tail;
    Node *curr = prev->next;

    while (curr->data != value)
    {
      prev = curr;
      curr = curr->next;
    }
    prev->next = curr->next;

    // 1-node linked list
    if (curr == prev)
    {
      tail = NULL;
    }

    // >= 2-node linked list
    else if (tail == curr)
    {
      tail = prev;
    }
    curr->next = NULL;
    delete curr;
  }
}

void printCLL(Node *tail)
{
  if (tail == NULL)
  {
    cout << "List is empty" << endl;
    return;
  }

  cout << "Circular linked list: ";
  Node *temp = tail;
  do
  {
    cout << tail->data << " ";
    tail = tail->next;
  } while (tail != temp);
  cout << endl;
}

int main()
{
  // insert node
  Node *tail = NULL;
  insertNode(tail, 5, 3);
  printCLL(tail);
  insertNode(tail, 3, 7);
  printCLL(tail);
  insertNode(tail, 7, 11);
  printCLL(tail);
  insertNode(tail, 11, 19);
  printCLL(tail);
  insertNode(tail, 3, 4);
  printCLL(tail);

  // delete node
  deleteNode(tail, 3);
  printCLL(tail);

  return 0;
}