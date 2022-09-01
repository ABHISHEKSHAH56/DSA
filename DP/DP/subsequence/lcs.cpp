#include <bits/stdc++.h>
#include <vector>
using namespace std;
int solve(string s1,string s2)
{
    vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1));
    for(int i=s1.length(); i>=0; i--)
    {
        for(int j=s2.length(); j>=0; j--)
        {
            if(i==s2.length() || j==s1.length()) dp[i][j]=0;
            else if(s1[i]==s2[j]) dp[i][j]=1+dp[i+1][j+1];
            else dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
        }
    }
    for(auto it:dp)
    {
        for(auto x:it)
        {
            cout<<x<<" ";
        }
        cout<<endl;
    }
    return dp[0][0];
}
int main(){
    string s1;
    string s2;
    cin>>s1>>s2;
    cout<<solve(s1,s2)<<endl;
}