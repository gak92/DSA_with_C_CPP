#include <bits/stdc++.h>
using namespace std;

class CircularQueue
{
public:
    // Initialize your data structure.
    int *arr;
    int size;
    int front;
    int rear;
    CircularQueue(int n)
    {
        // Write your code here.
        size = n;
        arr = new int[size];
        front = rear = -1;
    }

    // Enqueues 'X' into the queue. Returns true if it gets pushed into the stack, and false otherwise.
    bool enqueue(int value)
    {
        // Write your code here.
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1)))
            return false;

        if (front == -1) // push 1st element
            front = rear = 0;
        else if (rear == size - 1) // rear at then so go back to 1st index
            rear = 0;
        else
            rear++;        // normal case just increase rear
        arr[rear] = value; // insert value
        return true;
    }

    // Dequeues top element from queue. Returns -1 if the stack is empty, otherwise returns the popped element.
    int dequeue()
    {
        // Write your code here.
        if (front == -1) // queue is empty
            return -1;

        int res = arr[front];
        arr[front] = -1;

        if (front == rear) // single element
            front = rear = -1;
        else if (front == size - 1) // front at the end of array
            front = 0;
        else
            front++; // normal case

        return res;
    }
};

int main()
{

    return 0;
}