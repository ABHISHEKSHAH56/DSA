// 1. You are given a number N.
// 2. You have to find the minimum number of squares that sum to N.
// 3. You can always represent a number as a sum of squares of other numbers.
//    For eg -> In worst case N can be represented as (1*1) + (1*1) + (1*1)..... N times.


//7--1^2+2^2+1^2+1^2-->4

#include<bits/stdc++.h>
using namespace std; 
int solve(int n)
{
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2; i<n; i++)
    {
        int min=INT_MAX;
        for(int j=1; j*j<=i; j++)
        {
                int rem=i-j*j;
                if(dp[rem]<min) min=dp[rem];
        }        
        dp[i]=1+min;
    }
}