#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *prev;
  Node *next;

  // constructor
  Node(int data)
  {
    this->data = data;
    this->prev = NULL;
    this->next = NULL;
  }

  // destructor
  ~Node()
  {
    int val = this->data;
    if (next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << "Memory free for node with data " << val << endl;
  }
};

void printDLL(Node *&head)
{
  Node *temp = head;

  cout << "Doubly linked list: ";
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }
  cout << endl;
}

int getLength(Node *&head)
{
  Node *temp = head;
  int length = 0;
  while (temp != NULL)
  {
    length += 1;
    temp = temp->next;
  }
  return length;
}

void insertAtHead(Node *&head, Node *&tail, int data)
{
  if (head == NULL)
  {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  }
  else
  {
    Node *newNode = new Node(data);
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
  }
}

void insertAtTail(Node *&head, Node *&tail, int data)
{
  if (head == NULL)
  {
    Node *newNode = new Node(data);
    head = newNode;
    tail = newNode;
  }
  else
  {
    Node *newNode = new Node(data);
    newNode->prev = tail;
    tail->next = newNode;
    tail = newNode;
  }
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
  // insert at 1st position (insert at start)
  if (position == 1)
  {
    insertAtHead(head, tail, data);
    return;
  }

  // insert at last position (insert at tail)
  Node *temp = head;
  int count = 1;
  while (count < position - 1)
  {
    temp = temp->next;
    count++;
  }

  if (temp->next == NULL)
  {
    insertAtTail(head, tail, data);
    return;
  }

  // insert at any middle position
  Node *newNode = new Node(data);
  newNode->next = temp->next;
  temp->next->prev = newNode;
  newNode->prev = temp;
  temp->next = newNode;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
  if (position == 1)
  {
    Node *temp = head;
    temp->next->prev = NULL;
    head = temp->next;
    temp->next = NULL;
    delete temp;
  }
  else
  {
    Node *prev = NULL;
    Node *curr = head;
    int count = 1;
    while (count < position)
    {
      prev = curr;
      curr = curr->next;
      count++;
    }

    prev->next = curr->next;
    if (prev->next == NULL)
      tail = prev;
    else
      curr->next->prev = prev;
    curr->next = NULL;
    curr->prev = NULL;
    delete curr;
  }
}

int main()
{
  // Node *node1 = new Node(11);
  Node *head = NULL;
  Node *tail = NULL;

  printDLL(head);
  cout << "Length of doubly linked list: " << getLength(head) << endl;

  // insert at head
  insertAtHead(head, tail, 7);
  printDLL(head);
  insertAtHead(head, tail, 4);
  printDLL(head);
  insertAtHead(head, tail, 3);
  printDLL(head);

  // insert at tail
  insertAtTail(head, tail, 19);
  printDLL(head);
  cout << "Head: " << head->data << endl;
  cout << "Tail: " << tail->data << endl;
  insertAtTail(head, tail, 27);
  printDLL(head);
  cout << "Head: " << head->data << endl;
  cout << "Tail: " << tail->data << endl;

  // insert at position
  insertAtPosition(head, tail, 4, 41);
  insertAtPosition(head, tail, 1, 2);
  insertAtPosition(head, tail, 8, 92);
  printDLL(head);

  // delete node
  deleteAtPosition(head, tail, 4);
  printDLL(head);
  cout << "Head: " << head->data << endl;
  cout << "Tail: " << tail->data << endl;

  return 0;
}