#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;
    
    int sum=0;
    set<int> s;
    int a;
    while(n){
        a=n%10;
        n=n/10;

        if(s.find(a)==s.end()){
            sum+=a;
            s.insert(a);
        }
    }

    cout<<"Sum = "<<sum<<endl;
    return 0;
}