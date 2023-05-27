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

void insertAtPosition(Node *&head, int position, int data)
{
  Node *temp = head;
  int count = 1;

  while (count < position - 1)
  {
    temp = temp->next;
    count++;
  }

  Node *nodeToInsert = new Node(data);
  nodeToInsert->next = temp->next;
  temp->next = nodeToInsert;
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

  insertAtPosition(head, 4, 11);
  cout << "Linked list is: ";
  printLL(head);

  return 0;
}