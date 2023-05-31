/*
  https://practice.geeksforgeeks.org/problems/check-if-linked-list-is-pallindrome/1
*/

/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

#include <bits/stdc++.h>
class Node
{
public:
  int data;
  Node *next;
  Node(int x)
  {
    this->data = x;
    this->next = NULL;
  }
};

class Solution
{
private:
  bool checkPalindrome(vector<int> arr)
  {
    int start = 0;
    int end = arr.size() - 1;

    while (start <= end)
    {
      if (arr[start] != arr[end])
      {
        return false;
      }
      start++;
      end--;
    }
    return true;
  }

  Node *getMid(Node *head)
  {
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    return slow;
  }

  Node *reverse(Node *head)
  {
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while (curr != NULL)
    {
      forward = curr->next;
      curr->next = prev;
      prev = curr;
      curr = forward;
    }

    return prev;
  }

public:
  // Function to check whether the list is palindrome.
  bool isPalindrome(Node *head)
  {
    // Your code here

    // Solution # 2 - Reverse list after mid and then compare
    // Time Complexity - O(n) Space Complexity - O(1)
    if (head->next == NULL)
      return true;
    // step 1 - Find middle of linked list
    Node *mid = getMid(head);

    // step 2 - Reverse the half linked list after mid
    Node *temp = mid->next;
    mid->next = reverse(temp);

    // step 3 - Compare both half
    Node *head1 = head;
    Node *head2 = mid->next;
    while (head2 != NULL)
    {
      if (head1->data != head2->data)
      {
        return false;
      }
      head1 = head1->next;
      head2 = head2->next;
    }

    return true;

    // Solution # 1 - Copy linked list into an array and then check for palindrome
    // Time Complexity - O(n), Space Complexity - O(n)
    /*
    vector<int> arr;
    Node* temp = head;

    while(temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }

    return checkPalindrome(arr);
    */
  }
};

//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T, i, n, l, firstdata;
  cin >> T;
  while (T--)
  {

    struct Node *head = NULL, *tail = NULL;
    cin >> n;
    // taking first data of LL
    cin >> firstdata;
    head = new Node(firstdata);
    tail = head;
    // taking remaining data of LL
    for (i = 1; i < n; i++)
    {
      cin >> l;
      tail->next = new Node(l);
      tail = tail->next;
    }
    Solution obj;
    cout << obj.isPalindrome(head) << endl;
  }
  return 0;
}

int main()
{

  return 0;
}