#include <iostream>
using namespace std;

class Queue
{
  int *arr;
  int front;
  int rear;
  int size;

public:
  Queue()
  {
    int size = 100001;
    arr = new int[size];
    front = 0;
    rear = 0;
  }

  void enqueue(int data)
  {
    if (rear == size)
      cout << "Queue is full" << endl;
    else
    {
      arr[rear] = data;
      rear++;
    }
  }

  int dequeue()
  {
    if (front == rear)
      return -1;
    else
    {
      int value = arr[front];
      arr[front] = -1;
      front++;
      if (front == rear)
      {
        front = 0;
        rear = 0;
      }
      return value;
    }
  }

  int qFront()
  {
    if (front == rear)
      return -1;
    return arr[front];
  }

  bool isEmpty()
  {
    return front == rear;
  }
};

int main()
{

  return 0;
}