#include <bits/stdc++.h>
using namespace std;
//minimum no of ways 
int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,INT_MAX-1);
        dp[0]=0;
        for(int ca=1; ca<dp.size(); ca++)
        {
            int mini=INT_MAX;
            for(auto coin:coins )
            {
                if(coin<=ca)
                {
                   dp[ca]=min(dp[ca],dp[ca-coin]+1);
                }
            }
           
            
        }
        //for(auto it:dp) cout<<it<<" ";
        return dp[amount]==INT_MAX-1? -1:dp[amount]; 
}
