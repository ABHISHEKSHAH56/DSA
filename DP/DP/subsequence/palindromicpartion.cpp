//pilondromic partitions with minium cut 
#include<bits/stdc++.h>
using namespace std;

int solve(string s1)
{ int count=0;
    int maxlongest=0;
    vector<vector<int>>dp(s1.length(),vector<int>(s1.length()));
    for(int g=0; g<s1.length(); g++)
    {
        for(int i=0, j=g; j<dp.size(); i++,j++)
        {
            if(g==0) dp[i][j]=true;
            else if(g==1) dp[i][j]= s1[i]==s1[j]? true:false;
            else{
                if(s1[i]==s1[j]) dp[i][j]=dp[i][j-1];
                else dp[i][j]=false;
            }
            
        }
    }
    vector<int>ndp(s1.size());
    ndp[0]=0;
    for(int j=1; j<ndp.size(); j++)
    {
        if(dp[0][j]) ndp[j]=0;
        else{
            int min=INT_MAX;
            for(int i=j ; i>=1; i--)
            {
                if(dp[i][j]){
                    if(min>ndp[i-1])min=ndp[i-1];
                }
            }
            ndp[j]=min;
        }
    }
    
   
}