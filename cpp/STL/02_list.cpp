#include<iostream>
#include<list>
using namespace std;

void display(list<int> &lst)
{
  list<int> :: iterator it;
  for(it=lst.begin(); it!=lst.end(); it++)
  {
    cout << *it << " "; 
  }
  cout << endl;
}

int main()
{
  list<int> list1;  // list of length 0
  list1.push_back(4);
  list1.push_back(7);
  list1.push_back(11);
  list1.push_back(199);
  list1.push_back(19);
  list1.push_back(21);
  list1.push_back(40);

  display(list1);

  // remove from end
  list1.pop_back();
  display(list1);

  // remove from start
  list1.pop_front();
  display(list1);

  list1.push_back(9);
  list1.push_back(9);
  display(list1);

  // remove an element in middle anywhere (remove all occurrences)
  list1.remove(9);
  display(list1);

  list<int> list2(7); // list of size 7
  list<int> :: iterator it;
  it = list2.begin();
  *it = 41;
  it++;
  *it = 70;
  it++;
  *it = 99;
  it++;
  display(list2);

  list1.sort();
  display(list1);

  list2.sort();
  display(list2);

  list1.merge(list2);
  display(list1);


  return 0;
}
