// 1. You are given a number n, representing the number of elements.
// 2. You are given n numbers, representing the contents of array of length n.
// 3. You are required to print the length of longest increasing subsequence of array.

#include <bits/stdc++.h>
using namespace std;
//dp[i]--longest length in inceasing subsequence which end with arr[i]

void LIS(vector<int> arr,int n)
{
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
}