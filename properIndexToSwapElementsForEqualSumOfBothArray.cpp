#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> A;
    vector<int>B;

    int sumA = 0;
    int sumB = 0;

    int n,m;
    cout<<"Enter number of Elements in A:";
    cin>>n;
    cout<<"Enter number of elements in B:";
    cin>>m;
    cout<<"Enter elements of A:-"<<endl;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        A.push_back(a);
        sumA+=a;
    }
    cout<<"Enter elements of B:-"<<endl;
    for(int i=0;i<m;i++){
        int a;
        cin>>a;
        B.push_back(a);
        sumB+=a;
    }   

    int diff = (abs(sumA-sumB))/2;
    int index1=-1,index2;
    unordered_map<int,int> mp;
    if(sumA<sumB){
        for(int i=0;i<n;i++){
            mp[B[i]]=i;
        }
        for(int i=0;i<m;i++){
            if(mp.find(A[i]+diff)!=mp.end()){
                int f = A[i]+diff;
                index1=mp[f];
                index2=i;
                break;
            }
        }
        if(index1!=-1)
        cout<<index2<< ","<<index1<<endl;
        else
        cout<<"No such index exist.";
      
    }
    else if(sumA>sumB){
        for(int i=0;i<n;i++){
            mp[A[i]]=i;
        }
        for(int i=0;i<m;i++){
            if(mp.find(B[i]+diff)!=mp.end()){
                int f = B[i]+diff;
                index1=mp[f];
                index2=i;
                break;
            }
        }      
        if(index1!=-1)
        cout<<index1<< ","<<index2<<endl;
        else
        cout<<"No such index exist.";

    }else {
        cout<<"Sum already equal."<<endl;
    }

    return 0;
}