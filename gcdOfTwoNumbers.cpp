#include<bits/stdc++.h>
using namespace std;

int main(){

    int a,b;
    cout<<"Enter number 1:";
    cin>>a;
    cout<<"Enter number 2:";
    cin>>b;
    int gcd;

    int i=2;
    int isprimeA=0;
    while(i<=a){
        if(a%i!=0){
            break;
        }
        if(i==a){
            isprimeA=1;
        }
        i++;
    }
    int j=2;
    int isprimeB=0;
    while(j<=b){
        if(b%j!=0){
            break;
        }
        if(j==b){
            isprimeB=1;
        }
        j++;
    }

    if(isprimeA==1 || isprimeB==1){
        cout<<"gcd = "<<1<<endl;
        return 0;
    }

    //logic 1
    int c;
    if(a<=b){
        c=a;
    }else{
        c=b;
    }
    while(c){
        if(a%c==0 && b%c==0){
            gcd=c;
            break;
        }
        else{
            c--;
        }
    }

    //logic 2
    int lcm;
    if(a>=b){
        lcm=a;
    }else{
        lcm=b;
    }

    while(lcm){
        if(lcm%a==0 && lcm%b==0){
            break;
        }else{
            lcm++;
        }
    }
    gcd = (a*b)/lcm;

    //logic 3

    int r,q;
    if(a<=b){
        r=a%b;
        q=a/b;
    }else{
        r=b%a;
        q=b/a;
    }
    while(r){
        a=b;
        b=r;
        r=a%b;
    }
    gcd=b;

    cout<<"gcd = "<<gcd<<endl;
    return 0;
}