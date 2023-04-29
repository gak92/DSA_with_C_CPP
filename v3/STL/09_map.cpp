#include <iostream>
#include <map>
using namespace std;

int main()
{
  map<int, string> mp;

  mp[1] = "I";
  mp[7] = "coding";
  mp[3] = "love";
  mp.insert({11, "very much"});

  cout << "Initial Map: " << endl;
  for (auto ele : mp)
  {
    cout << ele.first << " --> " << ele.second << endl;
  }

  // Finding key
  cout << "Find 3: " << mp.count(3) << endl;

  // Erase
  cout << "After erase: " << endl;
  mp.erase(3);
  for (auto ele : mp)
  {
    cout << ele.first << " --> " << ele.second << endl;
  }

  // Find
  auto it = mp.find(7);
  for (auto itr = it; itr != mp.end(); itr++)
  {
    cout << (*itr).first << " ------>  " << (*itr).second << endl;
  }

  return 0;
}