#include<bits/stdc++.h>
using namespace std;

void display(vector<int>v,int n){
    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void terSort(vector<int>&v,int n){
    if(n==1){
        return;
    }
    int i=0,j=0,k=n-1;

    while(j<=k){
        if(v[j]==0){
            swap(v[i],v[j]);
            i++;j++;
        }
        else if(v[j]==1){
            j++;
        }
        else{
            swap(v[j],v[k]);
            k--;
        }
    }
    return;
}
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;
    vector<int>v;
    cout<<"Enter elements:-"<<endl;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }
    cout<<"Before Sorting:- ";
    display(v,n);
    terSort(v,n);
    cout<<"After Sorting:- ";
    display(v,n);
    return 0;
}