#include <iostream>
#include <list>
using namespace std;

void printList(list<int> l)
{
  cout << "Elements: ";
  for (int ele : l)
  {
    cout << ele << " ";
  }
  cout << endl;
}

int main()
{
  list<int> l;

  l.push_back(11);
  l.push_back(19);
  l.push_front(7);
  printList(l);

  cout << "Size (elements in list): " << l.size() << endl;
  cout << "Array empty or not: " << l.empty() << endl;
  cout << "First element: " << l.front() << endl;
  cout << "Last element: " << l.back() << endl;

  l.erase(l.begin());
  cout << "After Erase: ";
  printList(l);

  // copy list
  list<int> n(l);
  printList(n);

  // create list with initialize value
  list<int> m(5, 100);
  printList(m);

  return 0;
}