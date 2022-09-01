 #include<bits/stdc++.h>
 using namespace std;
 bool part(int n,int arr[],int k)
    {
        vector<vector<int>>dp(n+1,vector<int>(k+1));
        for(int i=0; i<n+1; i++)
        {
            for(int j=0; j<k+1; j++)
            {
                if(j==0) dp[i][j]=true;
                else if(i==0) dp[i][j]=false;
                else {
                    if(arr[i-1]<=j)
                    {
                        dp[i][j]=dp[i-1][j] || dp[i][j-arr[i-1]];
                    }
                    else dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][k];
    }
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0; 
        for(int i=0; i<N; i++) sum+=arr[i];
        if(sum%2!=0) return 0;
        //if we find  subset sum /2  then there will a another set which sum equal to sum/2
        return part(N,arr,sum/2);
        
    }