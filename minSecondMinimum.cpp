#include<bits/stdc++.h>
using namespace std;

vector<int> checkMIN2ndMIN(vector<int> v)
{
    int min = v[0];
    int Smin = v[0];

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] <= min)
        {
            if (Smin >= min)
            {
                Smin = min;
            }
            min = v[i];
        }
        else
        {
            if (Smin >= v[i])
            {
                Smin = v[i];
            }
        }
    }
    vector<int> ans;
    ans.push_back(min);
    ans.push_back(Smin);
    return ans;
}

int main()
{
    int n;
    cout << "Enter number of elements:";
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int a;
        printf("Enter element %d:", i + 1);
        cin >> a;
        v.push_back(a);
    }
    if (v.size() == 0)
    {
        cout << "No minimum and 2nd minimum" << endl;
    }
    else if (v.size() == 1)
    {
        printf("minimum = %d\n", v[0]);
        printf("No second minimum.");
    }
    else if (v.size() == 2)
    {
        if (v[0] <= v[1])
        {
            printf("minimum = %d\n", v[0]);
            printf("2nd minimum = %d\n", v[1]);
        }
        else
        {
            printf("minimum = %d\n", v[1]);
            printf("2nd minimum = %d\n", v[0]);
        }
    }
    else if (v.size() >= 3)
    {
        vector<int> ans;
        ans = checkMIN2ndMIN(v);
        printf("minimum = %d\n", ans[0]);
        printf("2nd minimum = %d\n", ans[1]);
    }

    return 0;
}
