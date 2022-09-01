#include <bits/stdc++.h>
#include <vector>
using namespace std;
int solve(string s1)
{
    vector<int>dp(s1.size()+1,0);
    map<char,int>mp;
    dp[0]=1;
    for(int i=1; i<dp.size(); i++)
    {
        dp[i]=2*dp[i-1];
        if(mp.find(s1[i-1])!=mp.end())
        {
            dp[i]-=dp[mp[s1[i-1]]-1];
        }
        mp[s1[i-1]]=i;
    }
    return dp[s1.size()];
}
int main(){
    string s1;   
    cin>>s1;
    cout<<solve(s1)<<endl;
}