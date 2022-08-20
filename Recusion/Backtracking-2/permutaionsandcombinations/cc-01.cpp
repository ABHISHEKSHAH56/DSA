#include <bits/stdc++.h>
using namespace std;

void solve(int cb ,int tb ,int ssf,int ts,string asf){
    
    if(cb>tb){
        if(ts==ssf){
        cout<<asf<<endl;
        return ;
    }

    }
    
    solve(cb+1,tb,ssf,ts,asf+"_");
    solve(cb+1,tb,ssf+1,ts,asf+"i");
}


int main()
{
    //for number box 
    int n;
    int r;
    cin>>n>>r;
    vector<int>arr(n);
    solve(1,n,0,r,"");
}