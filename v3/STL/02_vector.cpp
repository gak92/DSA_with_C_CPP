#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int> v)
{
  cout << "Elements: ";
  for (int ele : v)
  {
    cout << ele << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> v;

  cout << "Capacity (memory): " << v.capacity() << endl;
  cout << "Size (elements in vector): " << v.size() << endl;

  v.push_back(1);
  cout << "Capacity (memory): " << v.capacity() << endl;
  cout << "Size (elements in vector): " << v.size() << endl;

  v.push_back(2);
  cout << "Capacity (memory): " << v.capacity() << endl;
  cout << "Size (elements in vector): " << v.size() << endl;

  v.push_back(3);
  cout << "Capacity (memory): " << v.capacity() << endl;
  cout << "Size (elements in vector): " << v.size() << endl;

  cout << "Element at 2nd index: " << v.at(2) << endl;
  cout << "Array empty or not: " << v.empty() << endl;
  cout << "First element: " << v.front() << endl;
  cout << "Last element: " << v.back() << endl;

  cout << "Before Pop --------- " << endl;
  printVector(v);

  v.pop_back();
  // cout << "Popped Element: " << v.pop_back() << endl;
  cout << "After Pop --------- " << endl;
  printVector(v);
  cout << "Capacity (memory): " << v.capacity() << endl;
  cout << "Size (elements in vector): " << v.size() << endl;

  // Clearing Vector
  v.clear();
  cout << "After clear vector: " << endl;
  cout << "Size (elements in vector): " << v.size() << endl;

  // Create vector by defining size and initial value
  vector<int> a(5, 1);
  printVector(a);

  // Create vector using other vector
  vector<int> copy(a);
  printVector(copy);

  return 0;
}