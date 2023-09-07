#include<bits/stdc++.h>
using namespace std;


int func(vector<int> &arr,int low,int high)
{
    int pivot=arr[low];
    int i=low;
    int j=high;
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1)
        {
            i++;
        }
        while(arr[j]>pivot && j>=low+1)
        {
            j--;
        }
        if(i<j)
        {
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[low],arr[j]);
    return j;
}
void quickSort(vector<int> &arr,int low,int high)
{
    if(low<high)
    {
        int partIndex=func(arr,low,high);
        quickSort(arr,low,partIndex-1);
        quickSort(arr,partIndex+1,high);
    }
}
int main()
{
    int n;
    cout<<"Enter numbers of elements:";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element:";
        cin>>arr[i];
    }
    quickSort(arr,0,n);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}