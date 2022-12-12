#include <iostream>
using namespace std;

class Student
{
protected:
  int roll_number;

public:
  void set_roll_number(int r)
  {
    roll_number = r;
  }

  void get_roll_number(void)
  {
    cout << "Roll number is: " << roll_number << endl;
  }
};

class Test : virtual public Student
{
protected:
  float maths, physics;

public:
  void set_marks(float m1, float m2)
  {
    maths = m1;
    physics = m2;
  }
  void get_marks(void)
  {
    cout << "Maths: " << maths << endl
         << "Physics: " << physics << endl;
  }
};

class Sports : virtual public Student
{
protected:
  float score;

public:
  void set_score(float sc)
  {
    score = sc;
  }

  void get_score(void)
  {
    cout << "Score is: " << score << endl;
  }
};

class Result : public Test, public Sports
{
private:
  float total;

public:
  void display_total(void)
  {
    total = maths + physics + score;
    get_roll_number();
    get_marks();
    get_score();
    cout << "Total number is: " << total << endl;
  }
};

int main()
{
  Result res;
  res.set_roll_number(19);
  res.set_marks(92.0, 85.5);
  res.set_score(90);
  res.display_total();

  return 0;
}