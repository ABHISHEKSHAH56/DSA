#include <bits/stdc++.h>
using namespace std;

void solve(int cb ,int tb ,vector<int> items,int ssf,int ts ,string asf)
{
    if(cb>tb)
    {
        if(ssf==ts)
        {
            //print 
        }
    }
    //me is items ke baitha rha hu 
    for(int i=0; i<ts; i++)
    {
        if(items[i]==0)
        {
            items[i]=1;
            solve(cb+1,tb,items,ssf+1,ts,asf+"("+to_string(i+1)+") ");
            items[i]=0;
        }
    }
    solve(cb+1,tb,items,ssf,ts,asf+"0");
}


int main()
{
    //for number box 
    int n;
    int r;
    cin>>n>>r;
    vector<int>arr(n);
    solve(1,n,arr,0,r,"");
}