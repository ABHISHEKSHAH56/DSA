#include <bits/stdc++.h>
using namespace std;
//maximum no of ways 
int coincombinations(int sum ,vector<int> coins ,int n )
{
    vector<int> dp(sum+1);
    dp[0]=1;
    for(int i=0; i<n; i++)
    {
        for(int j=coins[i]; j<sum+1; j++){
            dp[j]+=dp[j-coins[i]];
        }
    }
    return dp[sum];
}