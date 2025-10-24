#include <iostream>
#include <string>
using namespace std;

class Queue
{
    string arr[20];
    int front, rear, size;

public:
    Queue()
    {
        front = -1;
        rear = -1;
        size = 20;
    }

    bool isFull()
    {
        return rear == size - 1;
    }

    bool isEmpty()
    {
        return front == -1 || front > rear;
    }

    void enqueue(string name)
    {
        if (isFull())
        {
            cout << "Queue is full.\n";
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        arr[rear] = name;
        cout << name << " joined the queue.\n";
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "No patrons in queue.\n";
            return;
        }
        cout << arr[front] << " completed their book transaction.\n";
        front++;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No patrons waiting.\n";
            return;
        }
        cout << "Patrons currently in queue:\n";
        for (int i = front; i <= rear; i++)
            cout << i - front + 1 << ". " << arr[i] << endl;
    }
};

int main()
{
    Queue libraryQueue;
    int choice;
    string name;

    while (true)
    {
        cout << "\n--- Library Queue System ---\n";
        cout << "1. Add Patron\n";
        cout << "2. Complete Transaction\n";
        cout << "3. Display Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter patron name: ";
            cin >> name;
            libraryQueue.enqueue(name);
            break;
        case 2:
            libraryQueue.dequeue();
            break;
        case 3:
            libraryQueue.display();
            break;
        case 4:
            cout << "Exiting system.\n";
            return 0;
        default:
            cout << "Invalid choice.\n";
        }
    }
}
