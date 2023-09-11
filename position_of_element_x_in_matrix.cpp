#include<bits/stdc++.h>
using namespace std;

int a,b;

bool findPos(vector<vector<int>>&v,int r,int c,int x){
    for(int i=0;i<r;i++)
        {
            if(v[i][0]<=x && v[i][c-1]>=x)
            {
                for(int j=0;j<c;j++)
                {
                    if(x==v[i][j])
                    {
                        a=i;b=j;
                        return true;
                    }
                }
            }
        }
        return false;
}

int main(){
    int r,c;
    cout<<"Enter number of rows:";
    cin>>r;
    cout<<"Enter number of colums:";
    cin>>c;
    vector<vector<int>>v;
    
    cout<<"Enter elements:-"<<endl;
    
    for(int i=0;i<r;i++){
        vector<int>temp;
        for(int j=0;j<c;j++){
            int k;
            cin>>k;
            temp.push_back(k);
        }
        v.push_back(temp);
    }

    int x;
    cout<<"Enter x:";
    cin>>x;

    bool isThere = findPos(v,r,c,x);
    if(isThere){
        cout<<"Element x is present at the position ("<<a<<","<<b<<")."<<endl;
    }else{
        cout<<"Element x is not present."<<endl;
    }
    return 0;
}