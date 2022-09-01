//catlan number --c5c0+c4c1+c3c2+c2c3+c1c4+c0c5

#include<bits/stdc++.h>
using namespace std; 

int catlannumber(int n)
{
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<dp.size(); i++)
    {
        for(int j=0; j<i; j++)
        {
            dp[i]+=dp[j]*dp[i-j-1];
        }
    }
}