#include <iostream>
#include <deque>
using namespace std;

void printDeque(deque<int> d)
{
  cout << "Elements: ";
  for (int ele : d)
  {
    cout << ele << " ";
  }
  cout << endl;
}

int main()
{
  deque<int> d;

  d.push_back(1);
  d.push_back(2);
  d.push_front(3);
  printDeque(d);

  cout << "Size (elements in deque): " << d.size() << endl;

  cout << "Element at 2nd index: " << d.at(2) << endl;
  cout << "Array empty or not: " << d.empty() << endl;
  cout << "First element: " << d.front() << endl;
  cout << "Last element: " << d.back() << endl;

  // Removing element
  d.erase(d.begin(), d.begin() + 1);
  cout << "Size after remove element: " << d.size() << endl;
  printDeque(d);

  d.pop_back();
  printDeque(d);

  return 0;
}