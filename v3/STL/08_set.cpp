#include <iostream>
#include <set>
using namespace std;

int main()
{
  set<int> s;

  // Insert function complexity - O(log n)
  s.insert(1);
  s.insert(1);
  s.insert(19);
  s.insert(11);
  s.insert(11);
  s.insert(7);
  s.insert(0);

  cout << "Set Elements: ";
  for (auto ele : s)
  {
    cout << ele << " ";
  }
  cout << endl;

  set<int>::iterator it = s.begin();
  it++;
  s.erase(it);

  cout << "After erase second element from Set: ";
  for (auto ele : s)
  {
    cout << ele << " ";
  }
  cout << endl;

  // Check if element exist
  cout << "Is 5 present in set: " << s.count(5) << endl;
  cout << "Is 11 present in set: " << s.count(11) << endl;

  // Find iterator of the find element
  set<int>::iterator itr = s.find(11);

  for (auto it = itr; it != s.end(); it++)
  {
    cout << *it << " ";
  }
  cout << endl;

  return 0;
}