#include<bits/stdc++.h>
using namespace std;

int maxEnvelopes(vector<vector<int>>& env) {
        int n = env.size();
        sort(env.begin(), env.end(), cmp);
        
      
        //i will find lis on the basis of height 
        vector<int> dp(env.size());
        int omax=0;
        for(int i=0; i<dp.size(); i++ )
        {
            int max=0;
            for(int j=0; j<i; j++)
            {
                if(env[i][1]>env[j][1] && env[i][0]>env[j][0]) if(dp[j]>max) max=dp[j];
            }
            dp[i]=1+max;
            if(dp[i]>omax) omax=dp[i];
        }
        return omax;;
        
        
    }