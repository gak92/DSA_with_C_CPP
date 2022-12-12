#include <iostream>
using namespace std;

/*
                      Public Derivation     Private Derivation    Protected Derivation
Private members:        Not inherit           Not inherit           Not inherit
Protected member:       Protected             Private               Protected
Public members:         Public                Private               Protected
*/

class Student
{
protected:
  int roll_number;

public:
  void set_roll_number(int);
  void get_roll_number(void);
};

void Student ::set_roll_number(int r)
{
  roll_number = r;
}

void Student ::get_roll_number(void)
{
  cout << "Roll number is: " << roll_number << endl;
}

class Exam : public Student
{
protected:
  float maths;
  float physics;

public:
  void set_marks(float, float);
  void get_marks(void);
};

void Exam ::set_marks(float m1, float m2)
{
  maths = m1;
  physics = m2;
}

void Exam ::get_marks(void)
{
  cout << "Math marks is: " << maths << endl;
  cout << "Math marks is: " << physics << endl;
}

class Result : public Exam
{
  float percentage;

public:
  void display()
  {
    get_roll_number();
    get_marks();
    cout << "The percentage is: " << (maths + physics) / 2 << endl;
  }
};

int main()
{
  Result ally;
  ally.set_roll_number(19);
  ally.set_marks(92.0, 90.0);
  ally.display();

  return 0;
}