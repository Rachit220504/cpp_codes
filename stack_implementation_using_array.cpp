#include <iostream>
using namespace std;

int stack[100], counter = 0;

void push(int n)
{
    if (counter == n)
    {
        cout << "Stack overflowed." << endl;
    }
    else
    {
        int x;
        cout << "Enter element to be inserted: ";
        cin >> x;
        stack[counter] = x;
        counter++;
    }
}

void pop(int n)
{
    if (counter == 0)
    {
        cout << "Stack underflowed." << endl;
    }
    else
    {
        int popped_element;
        popped_element = stack[--counter];
        cout << "Popped Element: " << popped_element << endl;
    }
}

void top(void)
{
    if (counter == 0)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        int a;
        a = stack[counter - 1];
        cout << "Top element: " << a << endl;
    }
}

void display(void)
{
    if (counter == 0)
    {
        cout << "Stack is empty." << endl;
    }
    else
    {
        cout << "Stack elements: ";
        for (int i = 0; i < counter; i++)
        {
            cout << stack[i] << " ";
        }
        cout << endl;
    }
}

int main()
{
    int n;
    cout << "Enter size of array (max = 100): ";
    cin >> n;

    if (n > 100)
    {
        cout << "Size exceeded." << endl;
    }
    else
    {
        while (true)
        {
            cout << "1. Push\n2. Pop\n3. Top\n4. Display\n5. Exit\n";
            int choice;
            cout << "Enter choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    push(n);
                    break;
                }
                case 2:
                {
                    pop(n);
                    break;
                }
                case 3:
                {
                    top();
                    break;
                }
                case 4:
                {
                    display();
                    break;
                }
                case 5:
                {
                    return 0;
                }
                default:
                {
                    cout << "Invalid choice." << endl;
                }
            }
        }
    }

    return 0;
}
