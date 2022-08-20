#include <bits/stdc++.h>
using namespace std;

void solve(vector<int> box,int ci ,int ti,int lb)
{
    
    if(ci>ti)
    {
        for(int i=lb+1; i<box.size(); i++)
        {
            cout<<box[i]<<" ";
        }
        cout<<endl;
        return ;
    }
    
    for(int i=0; i<box.size(); i++)
    {
        if(box[i]==0)
        {
            box[i]=1;
            solve(box,ci+1,ti,i);
            box[i]=0;
        }
    }
}


int main()
{
    //for number box 
    int n;
    int r;
    cin>>n>>r;
    vector<int>arr(n);
    solve(arr,1,r,-1);
}