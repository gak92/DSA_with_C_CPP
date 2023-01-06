#include<iostream>
#include<fstream>
using namespace std;
/*
Usefull classes to work with files in C++
1- fstreambase
2- ifstream (derived from fstreambase)
3- ofstream (derived from fstreambase)
*/

int main()
{
  string st1 = "Some text to write in file";
  string st2;

  // Open file using constructor and write into it
  ofstream out("sample.txt");
  out << st1;

  // Open file using constructor and read from it
  ifstream in("sample2.txt");
  getline(in, st2);
  cout << st2;

  return 0;
}