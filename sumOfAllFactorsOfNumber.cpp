#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter number:";
    cin>>n;

    cout<<"sum of all factors of "<<n<<" = ";
    int i=1;
    int sum = 0;
    while(i<=n){
        if(n%i==0){
            sum+=i;
        }
        i++;
    }
    cout<<sum;
    return 0;
}