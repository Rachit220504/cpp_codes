#include<bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr,int low,int high)
{
    if(low>=high)
    return;
    int first=low;
    int second=low+1;
    while(second<=high)
    {
        if(arr[first]>arr[second])
        swap(arr[first],arr[second]);
        first++;second++;
    }
    bubbleSort(arr,low,high-1);
}
int main()
{
    int n;
    cout<<"Enter nnumbers of elements:";
    cin>>n;
    vector<int>arr(n);
    for(int i=0;i<n;i++)
    {
        cout<<"Enter element:";
        cin>>arr[i];
    }

    bubbleSort(arr,0,n-1);
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}