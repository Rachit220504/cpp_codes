#include<bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr,int low,int high)
{
    if(low>=high)
    {
        return;
    }
    int min=low;
    for(int i=low+1;i<=high;i++)
    {
        if(arr[min]>arr[i])
        {
            min=i;
        }
    }
    swap(arr[min],arr[low]);
    selectionSort(arr,low+1,high);
}

int main()
{
    int n;
    cout<<"Enter numbers of elements";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element:";
        cin>>arr[i];
    }

    selectionSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}