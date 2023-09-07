#include <iostream>
using namespace std;

struct Queue
{
    int size;
    int f;
    int r;
    int *arr;
};

void display(Queue *q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        cout << q->arr[i] << " ";
    }
    cout << endl;
}

bool isEmpty(Queue *q)
{
    return q->f == q->r;
}

bool isFull(Queue *q)
{
    return q->r == (q->size) - 1;
}

void enqueue(Queue *q, int val)
{
    if (isFull(q))
    {
        cout << "Queue Overflow." << endl;
    }
    else
    {
        q->r++;
        q->arr[q->r] = val;
    }
}

int dequeue(Queue *q)
{
    int a = -1;
    if (isEmpty(q))
    {
        cout << "Queue is empty." << endl;
    }
    else if (q->f != q->r)
    {
        q->f++;
        a = q->arr[q->f];
    }
    return a;
}

int main()
{
    Queue q;
    cout << "Enter size of queue: ";
    cin >> q.size;
    q.f = -1;
    q.r = -1;
    q.arr = new int[q.size];

    if (isEmpty(&q))
    {
        cout << "Queue is empty." << endl;
    }

    while (true)
    {
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Display queue" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            int val;
            cout << "Enter value to be inserted: ";
            cin >> val;
            enqueue(&q, val);
            break;
        }
        case 2:
        {
            int x = dequeue(&q);
            if (x != -1)
            {
                cout << "Dequeued element: " << x << endl;
            }
            break;
        }
        case 3:
        {
            display(&q);
            break;
        }
        case 4:
        {
            delete[] q.arr; // Free the dynamically allocated array
            return 0;
        }
        default:
        {
            cout << "Invalid choice." << endl;
        }
        }
    }

    return 0;
}
