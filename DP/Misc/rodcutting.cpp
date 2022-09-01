#include<bits/stdc++.h>
using namespace std;

//1. cut startgey 
//2. left right startgey 

int rodcutting(vector<int>arr )
{
    vector<int>dp(arr.size()+1);
    dp[0]=0;
    dp[1]=arr[0];
    for(int i=2; i<dp.size(); i++)
    {
        int maxi=INT_MIN;
        for(int j=0; j<i; j++)
        {
            maxi=max(maxi,arr[i-j-1]+dp[j]);
        }
        dp[i]=maxi;
    }

}

//2 left right startgey 

int rodcutting(vector<int>arr )
{
    vector<int>dp(arr.size()+1);
    vector<int>np(arr.size()+1);
    for(int i=1; i<dp.size(); i++)
    {
        np[i]=arr[i-1];
    }
    dp[0]=0;
    dp[1]=np[1];
    for(int i=2; i<dp.size(); i++)
    {
        dp[i]=np[i];
        int l=1;
        int r=i-1;
        while(l<=r)
        {
            if(dp[l]+dp[r]>dp[i]) dp[i]=dp[l]+dp[r];
            l++;
            r--;
        }
        
    }

}