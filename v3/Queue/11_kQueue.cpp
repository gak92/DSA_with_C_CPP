#include <iostream>
using namespace std;

class kQueue
{
public:
  int n, k, freespot;
  int *arr, *next, *front, *rear;

  kQueue(int n, int k)
  {
    this->n = n;
    this->k = k;
    arr = new int[n];
    next = new int[n];
    front = new int[k];
    rear = new int[k];
    freespot = 0;

    for (int j = 0; j < k; j++)
    {
      front[j] = -1;
      rear[j] = -1;
    }

    for (int j = 0; j < n; j++)
    {
      next[j] = j + 1;
    }
    next[n - 1] = -1;
  }

  void enqueue(int data, int qn)
  {
    if (freespot == -1)
    {
      cout << "No empty space" << endl;
      return;
    }

    int index = freespot;   // get index of freespot
    freespot = next[index]; // update freespot

    // check if 1st element
    if (front[qn - 1] == -1)
    {
      front[qn - 1] = index;
    }
    else
    {
      // link new element to the prev element
      next[rear[qn - 1]] = index;
    }

    next[index] = -1;     // update next
    rear[qn - 1] = index; // update rear
    arr[index] = data;    // push element
  }

  int dequeue(int qn)
  {
    if (front[qn - 1] == -1)
    {
      cout << "Queue Underflow" << endl;
      return -1;
    }

    int index = front[qn - 1];   // get indext to pop element
    front[qn - 1] = next[index]; // update front

    // manage freespot
    next[index] = freespot;
    freespot = index;

    return arr[index];
  }
};

int main()
{
  kQueue q(10, 3);

  q.enqueue(10, 1);
  q.enqueue(20, 1);
  q.enqueue(15, 2);
  q.enqueue(25, 1);

  cout << q.dequeue(1) << endl;
  cout << q.dequeue(2) << endl;
  cout << q.dequeue(1) << endl;
  cout << q.dequeue(1) << endl;

  cout << q.dequeue(1) << endl;

  return 0;
}