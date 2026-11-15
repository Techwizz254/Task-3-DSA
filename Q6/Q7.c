#include <stdio.h>
#define SIZE 5

int deque[SIZE];
int front = -1;
int rear = -1;

// Check if deque is full
int isFull()
{
    return (front == (rear + 1) % SIZE);
}

// Check if deque is empty
int isEmpty()
{
    return (front == -1);
}

// Front insertion
void insertFront(int value)
{
    if (isFull())
    {
        printf("Deque Overflow!\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        front = (front - 1 + SIZE) % SIZE;
    }

    deque[front] = value;
}

// Rear insertion
void insertRear(int value)
{
    if (isFull())
    {
        printf("Deque Overflow!\n");
        return;
    }

    if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear = (rear + 1) % SIZE;
    }

    deque[rear] = value;
}

// Front deletion
void deleteFront()
{
    if (isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted: %d\n", deque[front]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front = (front + 1) % SIZE;
    }
}

// Rear deletion
void deleteRear()
{
    if (isEmpty())
    {
        printf("Deque Underflow!\n");
        return;
    }

    printf("Deleted: %d\n", deque[rear]);

    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        rear = (rear - 1 + SIZE) % SIZE;
    }
}

// Display deque
void display()
{
    if (isEmpty())
    {
        printf("Deque is empty!\n");
        return;
    }

    int i = front;

    printf("Deque elements: ");

    while (1)
    {
        printf("%d ", deque[i]);

        if (i == rear)
            break;

        i = (i + 1) % SIZE;
    }

    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n--- DOUBLE ENDED QUEUE ---\n");
        printf("1. Front Insertion\n");
        printf("2. Rear Insertion\n");
        printf("3. Front Deletion\n");
        printf("4. Rear Deletion\n");
        printf("5. Display\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertFront(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertRear(value);
                break;

            case 3:
                deleteFront();
                break;

            case 4:
                deleteRear();
                break;

            case 5:
                display();
                break;

            case 6:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 6);

    return 0;
}