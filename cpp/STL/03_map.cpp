#include<iostream>
#include<map>
#include<string>
using namespace std;

int main()
{
  map<string, int> marks;
  marks["jack"] = 99;
  marks["steve"] = 92;
  marks["sara"] = 95;

  marks.insert({{"koruu", 85}, {"Kozumu", 89}});

  map<string, int> :: iterator itr;
  for(itr=marks.begin(); itr!=marks.end(); itr++)
  {
    cout << (*itr).first << " " << (*itr).second << endl;
  }

  return 0;
}