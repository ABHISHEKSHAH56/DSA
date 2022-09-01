// 1. You are given a number n, representing the number of elements.
// 2. You are given n numbers, representing the contents of array of length n.
// 3. You are required to print the length of longest bitonic subsequence of array.
// Note -> bitonic subsequence begins with elements in increasing order, followed by elements in decreasing order.



#include<bits/stdc++.h>
using namespace std;

int solve(int n,vector<int>arr){
    vector<int>dp(n);
    dp[0]=1;
    for(int i=1; i<n; i++)
    {   int max=0;
        for(int j=0; j<i; j++)
        {
            if(arr[i]>arr[j])
            {
                if(dp[j]>max)max=dp[j];
            }
        }
        dp[i]=1+max;
    }
    vector<int>ndp(n);
   // ndp[0]=1;
    for(int i=n-1; i>=0; i--)
    {   int max=0;
        for(int j=n-1; j>i; j--)
        {
            if(arr[j]<=arr[i])
            {
                if(ndp[j]>max)max=ndp[j];
            }
        }
        ndp[i]=1+max;
    }

    int ans=0; 
    for(int i=0; i<n; i++)
    {
        int x=dp[i]+ndp[i]-1;
        if(x>ans) ans=x;
    }
    return ans;
}