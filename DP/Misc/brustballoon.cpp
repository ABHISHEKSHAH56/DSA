// 1. You are given an array(arr) of length N which represents N number of balloons.
// 2. Each balloon is painted with a number on it.
// 3. You have to collect maximum coins by bursting all the balloons.
// 4. If you burst a balloon with index i, you will get (arr[i-1] * arr[i] * arr[i+1]) number of coins.
// 5. If arr[i-1] and arr[i+1] don't exist, then you may assume their value as 1.



#include<bits/stdc++.h>
using namespace std;

void solve(vector<int>arr){
    vector<vector<int>>dp(arr.size(),vector<int>(arr.size()));
    for(int g=0; g<arr.size(); g++)
    {
        for(int i=0,j=g; j<dp.size(); j++,i++)
        {
            int max=INT_MIN;
            for(int k=i; k<=j; k++)
            {
                int left= k==i?0 :dp[i][k-1];
                int right=k==j?0:dp[k+1][j];
                int val=arr[k];
                if(i>0) val*=arr[i-1];
                if(j!=arr.size()-1) val*=arr[j+1];
                int total=left+right+val;
                if(total>max) max=total;

            }
            dp[i][j]=max;
        }
    }
}