#include <bits/stdc++.h>
using namespace std;
//we take all at atime 
int coinpermutaions(int sum ,vector<int> coins ,int n )
{
    vector<int> dp(sum+1);
    dp[0]=1;
    for(int amt=1; amt<sum+1; amt++)
    {
        for(auto coin:coins)
        {
            if(coin<=amt)
            {
                dp[amt]+=dp[amt-coin];
            }
        }
    }
    return dp[sum];
}