#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main()
{
  // create map
  unordered_map<string, int> mp;

  // insert into map #1
  pair<string, int> p1 = make_pair("coding", 1);
  mp.insert(p1);

  // insert into map #2
  pair<string, int> p2("love", 2);
  mp.insert(p2);

  // insert into map #3
  mp["very"] = 3;

  // Accessing value for key
  cout << mp["love"] << endl;
  cout << mp.at("coding") << endl;

  // it will terminate the program
  // cout << mp.at("unknownKey") << endl;

  // it will return 0
  cout << mp["unknownKey"] << endl;

  // now it will give same result
  cout << mp.at("unknownKey") << endl;

  // check size of map
  cout << "Size: " << mp.size() << endl;

  // check if key present
  cout << "is key present: " << mp.count("something") << endl;
  cout << "is key present: " << mp.count("love") << endl;

  mp.erase("love");
  cout << "Now size is: " << mp.size() << endl;

  // Accessing all elements in map
  for (auto ele : mp)
  {
    cout << ele.first << " --> " << ele.second << endl;
  }

  // Access using iterator
  unordered_map<string, int>::iterator it = mp.begin();
  while (it != mp.end())
  {
    cout << it->first << " ---> " << it->second << endl;
    it++;
  }

  return 0;
}