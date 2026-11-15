#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

// Enqueue operation
void enqueue(int value)
{
    if (rear == SIZE - 1)
    {
        cout << "Queue Overflow!\n";
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }

        rear++;
        queue[rear] = value;

        cout << value << " inserted into queue.\n";
    }
}

// Dequeue operation
void dequeue()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue Underflow!\n";
    }
    else
    {
        cout << queue[front] << " removed from queue.\n";
        front++;
    }
}

// Display queue
void display()
{
    if (front == -1 || front > rear)
    {
        cout << "Queue is empty.\n";
    }
    else
    {
        cout << "Queue elements: ";

        for (int i = front; i <= rear; i++)
        {
            cout << queue[i] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int choice, value;

    do
    {
        cout << "\n--- QUEUE OPERATIONS ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: ";
                cin >> value;
                enqueue(value);
                break;

            case 2:
                dequeue();
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}