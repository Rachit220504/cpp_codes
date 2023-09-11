#include<bits/stdc++.h>
using namespace std;


int findAns(vector<int>&v,int n){
    int ans=0,a=0,b=0;

    for(int i=0;i<n;i++){
        a=max(v[i],a);
        ans+=a-v[i];
    }

    int i = n-1;
    while(v[i]!=a){
        b=max(v[i],b);
        ans-=a-b;
        i--;
    }
    return ans;
}
int main(){
    int n;
    cout<<"Enter number of elements:";
    cin>>n;

    vector<int> v;
    cout<<"Enter elements:-"<<endl;
    for(int i=0;i<n;i++){
        int a;
        cin>>a;
        v.push_back(a);
    }

    int ans=findAns(v,n);
    cout<<"Output : "<<ans<<endl;
    return 0;
}