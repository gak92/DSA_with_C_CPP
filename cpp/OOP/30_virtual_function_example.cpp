#include<iostream>
#include<cstring>
using namespace std;

class CWH
{
  protected:
    string title;
    float rating;
  public:
    CWH(string s, float r)
    {
      title = s;
      rating = r;
    }
    virtual void display()
    {

    }
};

class CWHVideo : public CWH
{
  float videoLength;
  public:
    CWHVideo(string s, float r, float vl):CWH(s,r)
    {
      videoLength = vl;
    }
    void display()
    {
      cout << "Video title: " << title << endl;
      cout << "Video Rating: " << rating << endl;
      cout << "Video Length: " << videoLength << endl;
    }
};

class CWHText : public CWH
{
  int words;
  public:
    CWHText(string s, float r, int wc):CWH(s,r)
    {
      words = wc;
    }
    void display()
    {
      cout << "Article title: " << title << endl;
      cout << "Article Rating: " << rating << endl;
      cout << "Article words: " << words << endl;
    }
};

int main()
{
  string title;
  float rating, videoLen;
  int words;

  // for CWHVideo
  title = "JavaScript Tutorial";
  rating = 4.5;
  videoLen = 9.30;
  CWHVideo jsVideo(title, rating, videoLen);
  // jsVideo.display();

  // for CWHText
  title = "Django Tutorial";
  rating = 4.1;
  words = 419;
  CWHText djText(title, rating, words);
  // djText.display();

  CWH *tuts[2];
  tuts[0] = &jsVideo;
  tuts[1] = &djText;

  tuts[0]->display();
  tuts[1]->display();


  return 0;
}

/*
RULES FOR Virtual Functions:
1- They cannot be static.
2- They are accessed by object pointers.
3- Virtual function can be a friend of another class.
4- A virtual function in base class might not be used.
5- If virtual function is defined in base class, there is no necessity to redefine it in derived class.
*/
