/*
  https://www.codingninjas.com/codestudio/problems/flatten-a-linked-list_1112655
*/

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
  int data;
  Node* next;
  Node* child;

  Node(int data) {
    this->data = data;
    this->next = NULL;
    this->child = NULL;
  }
};

*****************************************************************/
class Node
{
public:
  int data;
  Node *next;
  Node *child;

  Node(int data)
  {
    this->data = data;
    this->next = NULL;
    this->child = NULL;
  }
};

Node *merge(Node *left, Node *right)
{
  if (left == NULL)
    return right;
  if (right == NULL)
    return left;

  Node *res = new Node(-1);
  Node *temp = res;

  while (left != NULL && right != NULL)
  {
    if (left->data <= right->data)
    {
      temp->child = left;
      // left = left->next;
      left = left->child;
      temp = temp->child;
    }
    else
    {
      temp->child = right;
      right = right->child;
      temp = temp->child;
    }
  }
  while (left != NULL)
  {
    temp->child = left;
    // left = left->next;
    left = left->child;
    temp = temp->child;
  }
  while (right != NULL)
  {
    temp->child = right;
    right = right->child;
    temp = temp->child;
  }
  res = res->child;
  return res;
}

Node *flattenLinkedList(Node *head)
{
  // Write your code here
  if (head == NULL || head->next == NULL)
    return head;

  Node *down = head;

  Node *right = head->next;
  right = flattenLinkedList(right);
  down->next = NULL;

  Node *res = merge(down, right);
  return res;
}

/*
Node *mergeLists(Node *a,Node *b){

    Node *temp= new Node(0);

    Node *res=temp;

    while(a && b){

        if(a->data<b->data){
            temp->child=a;
            temp=temp->child;
            a=a->child;
        }

    else{
      temp->child=b;
      temp=temp->child;
      b=b->child;
    }
  }

    if(a){
        temp->child=a;
    }
    else{
        temp->child=b;
    }

    return res->child;
}



Node* flattenLinkedList(Node* head) {

    if(!head->next){
        return head;
    }

    Node *down= head;
    Node *right = head->next;
    right= flattenLinkedList(right);
    down->next= NULL;

    Node *ans=mergeLists(down,right);

    return ans;
}
*/

int main()
{

  return 0;
}