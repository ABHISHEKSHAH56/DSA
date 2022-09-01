// 1. You are given a number n, representing the number of bridges on a river.
// 2. You are given n pair of numbers, representing the north bank and south bank co-ordinates of each bridge.
// 3. You are required to print the count of maximum number of non-overlapping bridges.

#include<bits/stdc++.h>
using namespace std;

void solve(vector<pair<int,int>>arr)
{
    //sort on the basis of north 
    //find LIS of south on the basis of north 
    sort(arr.begin(),arr.end());
    vector<int>dp(arr.size());
    int omax=0;
    for(int i=0; i<dp.size(); i++){
        int maxi=0; 
        for(int j=0; j<i; j++)
        {
            if(arr[j].second<=arr[i].second)
            {
                if(dp[j]>maxi) maxi=dp[j];
            }
        }
        dp[i]=1+maxi;
        if(dp[i]>omax) omax=dp[i]; 
    }
}