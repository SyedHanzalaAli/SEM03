#include <iostream>
using namespace std;

class Queue
{
    int arr[10];
    int front, rear, size;

public:
    Queue()
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

    void enqueue(int val)
    {
        if (isFull())
            return;
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = val;
    }

    void dequeue()
    {
        if (isEmpty())
            return;
        front++;
    }

    void display()
    {
        if (isEmpty())
            return;
        for (int i = front; i <= rear; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    int peek()
    {
        if (!isEmpty())
            return arr[front];
        return -1;
    }
};

int main()
{
    Queue q;
    int customers[] = {13, 7, 4, 1, 6, 8, 10};
    int n = 7;

    for (int i = 0; i < n; i++)
        q.enqueue(customers[i]);

    cout << "Queue before checkouts: ";
    q.display();

    cout << "\nProcessing customers...\n";
    while (!q.isEmpty())
    {
        cout << "Serving customer ID: " << q.peek() << endl;
        q.dequeue();
    }

    cout << "\nAll customers checked out.\n";
    return 0;
}
