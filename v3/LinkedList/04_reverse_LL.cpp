/*
  https://www.codingninjas.com/codestudio/problems/reverse-the-singly-linked-list_799897
*/

#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

void reverse(LinkedListNode<int> *&head, LinkedListNode<int> *prev, LinkedListNode<int> *curr)
{
    if(curr == NULL)
    {
        head = prev;
        return;
    }

    LinkedListNode<int> *forward = curr->next;
    reverse(head, curr, forward);
    curr->next = prev;
}

LinkedListNode<int> * reverse2(LinkedListNode<int> *head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }

    LinkedListNode<int> *smallHead = reverse2(head->next);

    head->next->next = head;
    head->next = NULL;

    return smallHead;

}

LinkedListNode<int> *reverseLinkedList(LinkedListNode<int> *head) 
{
    // Solution #3 - Recursive (It will return head of reverse list)
    return reverse2(head);

    // Solution #2 - Recursive
    // LinkedListNode<int> *prev = NULL;
    // LinkedListNode<int> *curr = head;
    // reverse(head, prev, curr);
    // return head;

    // Solution # 1 - Iterative
    // if(head == NULL || head->next == NULL)
    // {
    //     return head;
    // }

    // LinkedListNode<int> *prev = NULL;
    // LinkedListNode<int> *curr = head;
    // LinkedListNode<int> *forward = NULL;

    // while(curr != NULL)
    // {
    //     forward = curr->next;
    //     curr->next = prev;
    //     prev = curr;
    //     curr = forward;
    // }
    // return prev;

}