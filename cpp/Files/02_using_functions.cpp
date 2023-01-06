#include<iostream>
#include<fstream>

using namespace std;

int main()
{
  // ofstream fout;
  // fout.open("sample.txt");
  // fout << "This is again some more text" << endl;
  // fout << "This is second line";
  // fout.close();

  ifstream fin;
  string s;
  fin.open("sample.txt");
  // fin >> s;
  // cout << s;

  cout << fin.eof() << endl;
  while(fin.eof() == 0)
  {
    getline(fin, s);
    cout << s << endl;
  }
  cout << fin.eof() << endl;
  fin.close();

  return 0;
}