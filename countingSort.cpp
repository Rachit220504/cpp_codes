#include <iostream>
#include <cstdlib>
#include <climits>

using namespace std;

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int maximum(int arr[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }
    return max;
}

void countingSort(int arr[], int n)
{
    int max = maximum(arr, n);
    int *count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[arr[i]] = count[arr[i]] + 1;
    }
    int i = 0;
    int j = 0;

    while (i < max + 1)
    {
        if (count[i] != 0)
        {
            arr[j] = i;
            count[i] = count[i] - 1;
            j++;
        }
        else
        {
            i++;
        }
    }
    delete[] count;
}

int main()
{
    int n;
    cout << "Enter number of Elements:";
    cin >> n;

    int *arr = new int[n];
    cout << "Enter elements:-" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sorting:- ";
    print(arr, n);
    cout << endl;
    countingSort(arr, n);
    cout << "After sorting:- ";
    print(arr, n);

    delete[] arr; // Free the dynamically allocated memory
    return 0;
}
