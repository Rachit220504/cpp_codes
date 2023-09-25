#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number of people:";
    cin>>n;
    int i;
    cout<<"Enter from 1 to n who have sword:";
    cin>>i;
    int ans;
    int dis = (int)(n-pow(2,floor(log2(n))));
    ans = ((i+dis*2-1)%n)+1;
    cout<<ans;
}