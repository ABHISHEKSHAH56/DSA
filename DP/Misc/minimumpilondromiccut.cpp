// 1. You are given a string.
// 2. You have to find the minimum number of cuts required to convert the given string into palindromic partitions.
// 3. Partitioning of the string is a palindromic partitioning if every substring of the partition is a palindrome.

#include<bits/stdc++.h>
using namespace std;

int minimumcut(string s)
{
    vector<vector<bool>>checkpilondrome(s.size());
    for(int g=0; g<checkpilondrome.size(); g++)
    {
        for(int i=0, j=g; j<checkpilondrome.size(); j++,i++)
        {
            if(g==0) checkpilondrome[i][j]=true;
            else if(g==1){
                if(s[i]==s[j]) checkpilondrome[i][j]=true;
                else checkpilondrome[i][j]=false;

            }
            else
            {
                if(s[i]==s[j]) checkpilondrome[i][j]=checkpilondrome[i+1][j-1];
                else checkpilondrome[i][j]=false;
            }
            
            
        }
    }
    vector<vector<bool>>dp(s.size());
    for(int g=0; g<s.size(); g++)
    {
        for(int i=0,j=g; j<s.size(); j++,i++)
        {
            if(g==0) dp[i][j]=0;
            else if(g==1){
                if(s[i]==s[j]) dp[i][j]=0;
                else dp[i][j]=1;
            }
            else{
                int min=INT_MAX;
                for(int k=i; k<j; k++)
                {
                    int left=dp[i][k];
                    int right=dp[k+1][j];
                    if(left+right+1<min) min=left+right+1;
                }
                dp[i][j]=min;

            }
        }
    }
    //with suffix 
    vector<int>dps(s.size());
    dps[0]=0;
    for(int j=1; j<s.size(); j++)
    {    
        int min=INT_MAX;
        for(int k=j; k>=1; k--)
        {
           
            if(checkpilondrome[k][j])
            {
                if(dps[k-1]<min) min=dps[k-1];
            } 
        }
        dps[j]=1+min;
    }

}