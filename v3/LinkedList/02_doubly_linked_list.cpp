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

void insertAtHead(Node *&head, int data)
{
  Node *newNode = new Node(data);
  newNode->next = head;
  head->prev = newNode;
  head = newNode;
}

void insertAtTail(Node *&tail, int data)
{
  Node *newNode = new Node(data);
  newNode->prev = tail;
  tail->next = newNode;
  tail = newNode;
}

int main()
{
  Node *node1 = new Node(11);
  Node *head = node1;
  Node *tail = node1;

  printDLL(head);
  cout << "Length of doubly linked list: " << getLength(head) << endl;

  // insert at head
  insertAtHead(head, 7);
  printDLL(head);
  insertAtHead(head, 4);
  printDLL(head);
  insertAtHead(head, 3);
  printDLL(head);

  // insert at tail
  insertAtTail(tail, 19);
  printDLL(head);
  cout << "Head: " << head->data << endl;
  cout << "Tail: " << tail->data << endl;
  insertAtTail(tail, 27);
  printDLL(head);
  cout << "Head: " << head->data << endl;
  cout << "Tail: " << tail->data << endl;

  return 0;
}