/*
https://leetcode.com/problems/intersection-of-two-linked-lists/description/
*/

#include <stdio.h>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
  {
    int l1 = 0, l2 = 0;
    ListNode *curr = headA;

    while (curr != NULL)
    {
      curr = curr->next;
      l1++;
    }

    curr = headB;
    while (curr != NULL)
    {
      curr = curr->next;
      l2++;
    }

    int diff = abs(l2 - l1);
    if (l1 > l2)
      swap(headA, headB);

    ListNode *p = headA;
    ListNode *q = headB;
    while (diff != 0)
    {
      q = q->next;
      diff--;
    }

    while (p != q)
    {
      p = p->next;
      q = q->next;
    }

    return p;
  }
};

int main()
{
  // ListNode *headA = new ListNode(4, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5)))));
  // ListNode* headB = new ListNode(5, new ListNode(0, new ListNode(1, new ListNode(8, new ListNode(4, new ListNode(5)))));

  ListNode *headA = new ListNode(1);
  headA->next = new ListNode(9);
  headA->next->next = new ListNode(1);
  headA->next->next->next = new ListNode(2);
  headA->next->next->next->next = new ListNode(4);

  ListNode *headB = new ListNode(3);
  headB->next = headA->next->next->next;

  Solution s;
  cout << s.getIntersectionNode(headA, headB)->val << endl;
  return 0;
}