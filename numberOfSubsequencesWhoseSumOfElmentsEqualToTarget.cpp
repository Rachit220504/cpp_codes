#include<bits/stdc++.h>
using namespace std;

int findSum(int index,int tempSum,int actSum,int arr[],int n)
{
    if(index==n)
    {
        if(tempSum==actSum)
        {
            return 1;
        }
        return 0;
    }
    tempSum+=arr[index];
    int l=findSum(index+1,tempSum,actSum,arr,n);
    tempSum-=arr[index];
    int r=findSum(index+1,tempSum,actSum,arr,n);
    return l+r;
}
int main()
{
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    int arr[n];
    cout<<"Enter elements:-"<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum;
    cout<<"Enter the sum to be find:";
    cin>>sum;
    printf("%d",findSum(0,0,sum,arr,n));
    return 0;
}