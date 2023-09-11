#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int x)
{
    for (int i = 2; i * i <= x; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int n, print = 0;
    cout<<"Enter number:";
    cin>>n;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            if (checkPrime(i))
            {
                cout<<i<<" ";
                print++;
            }
            if (checkPrime(n / i))
            {
                cout<<n / i<<" ";
                print++;
            }
        }
    }
    if (print == 0)
    {
        cout<<n;
    }
    return 0;
}