#include <iostream>
using namespace std;

class Stack
{
public:
  int *arr;
  int size;
  int top;

  Stack(int size)
  {
    this->size = size;
    arr = new int[size];
    top = -1;
  }

  void push(int element)
  {
    if (size - top > 1)
    {
      top++;
      arr[top] = element;
    }
    else
      cout << "Stack Overflow" << endl;
  }

  void pop()
  {
    if (top >= 0)
      top--;
    else
      cout << "Stack Underflow" << endl;
  }

  int peek()
  {
    if (top >= 0)
      return arr[top];
    else
    {
      cout << "Stack s Empty" << endl;
      return -1;
    }
  }

  bool isEmpty()
  {
    if (top >= 0)
      return false;
    return true;
  }
};

int main()
{
  Stack st(5);

  st.push(7);
  st.push(11);
  st.push(19);

  cout << st.peek() << endl;

  st.pop();
  cout << st.peek() << endl;

  st.pop();
  cout << st.peek() << endl;

  st.pop();
  cout << st.peek() << endl;

  return 0;
}