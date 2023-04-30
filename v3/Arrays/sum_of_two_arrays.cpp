/*
 https://www.codingninjas.com/codestudio/problems/sum-of-two-arrays_893186
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void printVector(vector<int> v)
{
  cout << "Vector elements: ";
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

vector<int> reverse(vector<int> v)
{
  int start = 0;
  int end = v.size() - 1;

  while (start <= end)
  {
    swap(v[start], v[end]);
    start++;
    end--;
  }

  return v;
}

vector<int> findArraySum(vector<int> a, vector<int> b)
{
  int i = a.size();
  int j = b.size();
  vector<int> res;
  int carry = 0;
  int sum = 0;

  while (i >= 0 && j >= 0)
  {
    sum = a[i] + b[j] + carry;
    carry = sum / 10;
    sum = sum % 10;
    res.push_back(sum);
    i--;
    j--;
  }

  while (i >= 0)
  {
    sum = a[i] + carry;
    carry = sum / 10;
    sum = sum % 10;
    res.push_back(sum);
    i--;
  }

  while (j >= 0)
  {
    sum = b[j] + carry;
    carry = sum / 10;
    sum = sum % 10;
    res.push_back(sum);
    j--;
  }

  while (carry != 0)
  {
    sum = carry;
    carry = sum / 10;
    sum = sum % 10;
    res.push_back(sum);
  }

  return reverse(res);
}

int main()
{
  // vector<int> a = {1, 2, 3, 4};
  // vector<int> b = {6};

  vector<int> a = {1, 2, 3};
  vector<int> b = {9, 9};

  vector<int> res = findArraySum(a, b);
  printVector(res);

  return 0;
}