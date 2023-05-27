#include <iostream>
using namespace std;

class Node
{
public:
  int data;
  Node *next;

  // constructur
  Node(int data)
  {
    this->data = data;
    this->next = NULL;
  }

  // destructor
  ~Node()
  {
    int value = this->data;
    // free memory
    if (this->next != NULL)
    {
      delete next;
      this->next = NULL;
    }
    cout << " memory is free for node with data " << value << endl;
  }
};

void printLL(Node *&head)
{
  Node *temp = head;

  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  cout << endl;
}

void insertAtHead(Node *&head, int data)
{
  Node *temp = new Node(data);
  temp->next = head;
  head = temp;
}

void insertAtTail(Node *&tail, int data)
{
  Node *temp = new Node(data);
  tail->next = temp;
  tail = tail->next;
}

void insertAtPosition(Node *&head, Node *&tail, int position, int data)
{
  // insert at start
  if (position == 1)
  {
    insertAtHead(head, data);
    return;
  }
  Node *temp = head;
  int count = 1;

  while (count < position - 1)
  {
    temp = temp->next;
    count++;
  }

  if (temp->next == NULL)
  {
    insertAtTail(tail, data);
    return;
  }

  Node *nodeToInsert = new Node(data);
  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
}

void deleteAtPosition(Node *&head, Node *&tail, int position)
{
  if (position == 1)
  {
    // delete at start
    Node *temp = head;
    head = head->next;
    temp->next = NULL;
    delete temp;
  }
  else
  {
    // deleting middle or last node
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
    curr->next = NULL;
    delete curr;
  }
}

int main()
{
  Node *node1 = new Node(5);

  cout << "Node address: " << node1 << endl;
  cout << "Node data: " << node1->data << endl;
  cout << "Next node address: " << node1->next << endl;

  Node *head = node1;
  Node *tail = node1;

  cout << "Linked list is: ";
  printLL(head);

  insertAtHead(head, 12);
  cout << "Linked list is: ";
  printLL(head);

  insertAtHead(head, 7);
  cout << "Linked list is: ";
  printLL(head);

  insertAtTail(tail, 19);
  cout << "Linked list is: ";
  printLL(head);

  insertAtPosition(head, tail, 5, 11);
  cout << "Linked list is: ";
  printLL(head);

  // print head and tail
  cout << "Head: " << head->data << endl;
  cout << "Tail: " << tail->data << endl;

  // delete
  deleteAtPosition(head, tail, 5);
  cout << "Linked list is: ";
  printLL(head);

  // print head and tail
  cout << "Head: " << head->data << endl;
  cout << "Tail: " << tail->data << endl;

  return 0;
}