#include<bits/stdc++.h>
using namespace std;


int sum(int n)
{
    int sum=0;
    while(n>0){
        int a = n%10;
        sum+=a;
        n=n/10;
    }
    return sum;
}
int main()
{
    int n;
    cout<<"Enter number:";
    cin>>n;
    cout<<sum(n);
    return 0;
}