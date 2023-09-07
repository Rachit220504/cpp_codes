#include<bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &arr, int i,int n)
{
    if(i>n)return;
    int j=i;
    while(j>0&&arr[j-1]>arr[j])
    {
        swap(arr[j-1],arr[j]);
        j--;
    }
    insertionSort(arr,i+1,n);
}


int main()
{
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element:";
        cin>>arr[i];
    }
    insertionSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}