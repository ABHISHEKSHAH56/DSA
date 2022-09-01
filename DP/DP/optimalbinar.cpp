#include<bits/stdc++.h>
using namespace std;

int solve (vector<int>freq,vector<int>key)
{
    int n=key.size();
    vector<vector<int>>dp(key.size(),vector<int>(key.size()));
    for(int g=0; g<n; g++)
    {
        for(int i=0,j=g; j<n; j++, i++)
        {
            if(g==0) dp[i][j]=freq[i];
            else if(g==1)
            {
                int f1=freq[i];
                int f2=freq[j];
                dp[i][j]=min(f1+2*f2,f2+2*f1);
            }
            else{
                int min=INT_MAX;
                int fs=0;
                for(int x=i; x<=j; x++) fs+=freq[x];
                for(int k=i; k<j; k++){
                    int left= k==i ? 0 : dp[i][k-1];
                    int right= k==j ? 0:  dp[k+1][j];
                    if(left+right+fs<min) min=left+right+fs;
                }
                dp[i][j]=min;
            }
        }
    }
    
}