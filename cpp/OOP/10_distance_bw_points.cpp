#include <iostream>
#include <cmath>
using namespace std;

class Point
{
  float x, y;
  friend float distanceBwPoints(Point, Point);

public:
  Point(float a, float b)
  {
    x = a;
    y = b;
  }

  void displayPoints(void)
  {
    cout << "Point is: (" << x << ", " << y << ")" << endl;
  }
};

float distanceBwPoints(Point p1, Point p2)
{
  float d;

  d = sqrt(pow((p2.y - p1.y), 2) + pow((p2.x - p1.y), 2));
  return d;
}

int main()
{
  Point p1(1, 1);
  p1.displayPoints();

  Point p2(1, 1);
  p2.displayPoints();

  float distance;
  distance = distanceBwPoints(p1, p2);
  cout << "Distance between points is: " << distance << endl;

  return 0;
}