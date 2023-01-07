#include<iostream>
#include<vector>
using namespace std;

template <class T>
void display(vector<T> v)
{
  cout << "Vector elements are: ";
  for(int i=0; i<v.size(); i++)
  {
    cout << v[i] << " ";
    // cout << v.at(i) << " ";
  }
  cout << endl;
}

int main()
{
  vector<int> v1;
  // int element, size;

  // cout << "Enter the size of the vector: ";
  // cin >> size;

  // for(int i=0; i<size; i++)
  // {
  //   cout << "Enter an element: ";
  //   cin >> element;

  //   v1.push_back(element);
  // }

  // v1.pop_back();
  // display(v1);

  // vector<int> :: iterator iter = v1.begin();
  // v1.insert(iter+1, 5, 41);

  // display(v1);

  vector<char> v2(4);
  v2.push_back('c');
  display(v2);

  vector<int> v4(6,13);
  display(v4);

  return 0;
}
