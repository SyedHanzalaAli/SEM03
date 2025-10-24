// The most suitable queue data structure for this messaging application is a FIFO (First-In, First-Out) Queue (also known as a Simple Linear Queue).

#include <iostream>
#include <string>
using namespace std;

class MessageQueue
{
    string arr[10];
    int front, rear, size;

public:
    MessageQueue()
    {
        front = -1;
        rear = -1;
        size = 10;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(string msg)
    {
        if (isFull())
            return;
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = msg;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        cout << "Processing message: " << arr[front] << endl;
        front++;
    }

    void display()
    {
        if (isEmpty())
            return;
        cout << "Messages in queue: ";
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " | ";
        cout << endl;
    }
};

int main()
{
    MessageQueue mq;
    mq.enqueue("Hello!");
    mq.enqueue("How are you?");
    mq.enqueue("Meeting at 5pm.");
    mq.enqueue("Don’t forget the report.");

    mq.display();

    while (!mq.isEmpty())
    {
        mq.dequeue();
    }

    cout << "All messages processed.\n";
    return 0;
}
