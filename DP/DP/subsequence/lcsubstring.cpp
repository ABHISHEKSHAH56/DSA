#include <bits/stdc++.h>
#include <vector>
using namespace std;
int solve(string s1,string s2)
{
    //max le ke chalna hoga!!
    vector<vector<int>>dp(s1.length()+1,vector<int>(s2.length()+1));
    for(int i=0; i<s1.length(); i++)
    {
        for(int j=0; j<dp[0].size(); j++)
        {
            if(i==0 || j==0) dp[i][j]=0;
            else{
                if(s1[i]==s2[j]) dp[i][j]=1+dp[i-1][j-1];
                else dp[i][j]=0;
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
    string s2;
    cin>>s1;
    cin>>s2;
    cout<<solve(s1,s2)<<endl;
}