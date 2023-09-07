#include<bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    int a,b;
    cout<<"Enter number 1:";
    cin>>a;
    cout<<"Enter number 2:";
    cin>>b;
    cout<<"before swapping"<<endl;
    cout<<a<<" "<<b<<endl;
    //logic 1
    a=a+b;
    b=a-b;
    a=a-b;
    //logic 2
    int c;
    a=c;
    a=b;
    b=c;
    //logic 3
    for(int i=0;i<2;i++){
        st.push(a);
        st.push(b);
    }
    for(int i=0;i<2;i++){
        if(i==0){
            a=st.top();
            st.pop();
        }
        else if(i==1){
            b=st.top();
            st.pop();
        }
    }

    cout<<"after swapping"<<endl;
    cout<<a<<" "<<b<<endl;
    return 0;
}