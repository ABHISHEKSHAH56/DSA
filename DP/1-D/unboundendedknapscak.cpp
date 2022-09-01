#include <bits/stdc++.h>
using namespace std;
//maximum no of ways 
int coincombinations(int mw ,vector<int> wt,vector<int>profit  )
{
    vector<int> dp(mw+1);
    dp[0]=0;
    for(int cap=1; cap<dp.size(); cap++)
    {
        int maxi=0;
        for(int j=0; j<wt.size(); j++ )
        {
           
            if(wt[j]<=cap)
            {
                maxi=max(maxi,dp[cap-wt[j]]+profit[j]);
            }
        }
        dp[cap]=maxi;
    }
    return dp[mw];
}