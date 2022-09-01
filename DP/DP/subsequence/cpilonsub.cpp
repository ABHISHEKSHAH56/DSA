#include <bits/stdc++.h>
#include <vector>
using namespace std;
int solve(string s1)
{
    vector<vector<int>>dp(s1.length(),vector<int>(s1.length()));
    for(int g=0; g<s1.length(); g++)
    {
        for(int i=0, j=g; j<dp.size(); i++,j++)
        {
            if(g==0) dp[i][j]=1;
            else if(g==1) dp[i][j]= s1[i]==s1[j]? 3:2;
            else{
                if(s1[i]==s1[j]) dp[i][j]=1+dp[i+1][j]+dp[i][j-1];
                else dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            }
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
    cin>>s1;
    cout<<solve(s1)<<endl;
}