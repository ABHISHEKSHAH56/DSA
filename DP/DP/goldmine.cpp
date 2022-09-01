#include<bits/stdc++.h>
using namespace std;
int maxGold(int n, int m, vector<vector<int>> arr)
    {
        // code here
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        for(int j=m-1; j>=0; j--)
        {
            for(int i=0; i<n; i++)
            {
                if(j==m-1) dp[i][j]=arr[i][j];
                else if(i==0) dp[i][j]=max(dp[i][j+1],dp[i+1][j+1])+arr[i][j];
                else if(i==n-1 && n!=1) dp[i][j]=max(dp[i][j+1],dp[i-1][j+1])+arr[i][j];
                else{
                    dp[i][j]=max(dp[i][j+1],max(dp[i+1][j+1],dp[i-1][j+1])) +arr[i][j];
                }
                
            }
        }
        int max=INT_MIN;
        for(auto it:dp) if(max<it[0]) max=it[0];
        return max;
    }