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
}
int main(){}