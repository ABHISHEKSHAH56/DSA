//pilondromic partitions with minium cut 
#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr)
{ 
    vector<vector<int>>dp(arr.size()-1,vector<int>(arr.size()-1));
    for(int g=0; g<arr.size(); g++)
    {
        for(int i=0, j=g; j<dp.size(); i++,j++)
        {
            if(g==0) dp[i][j]=0;
            else if(g==1) dp[i][j]=arr[i]*arr[j]*arr[j+1];
            else{
                int min=INT_MAX;
                for(int k=i; k<j; k++)
                {
                    int lc=dp[i][k];
                    int rc=dp[k+1][j];
                    int mc=arr[i]*arr[k+1]*arr[j+1];
                    int total=lc+rc+mc;
                    if(total<min) min=total;
                }
                dp[i][j]=min;
            }
        }
    }
    
    
   
}