#include<bits/stdc++.h>
using namespace std;
#define m 1000000007

int countFriendsPairings(int n) 
    { 
        // code here
        vector<long long >dp(n+1);
        dp[1]=1;
        dp[2]=2;
        for(int i=3; i<=n; i++)
        {
            dp[i]=(dp[i-1]%m+dp[i-2]*(i-1)%m)%m;
        }
       
        
        return dp[n];
}