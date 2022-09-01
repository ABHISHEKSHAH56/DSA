// 1. You are given a matrix of 0's and 1's.
// 2. You have to find the maximum size square sub-matrix with all 1's.

#include<bits/stdc++.h>
using namespace std;
//team as weakest as it !!
int maxsquare(vector<vector<int>>arr)
{
    vector<vector<int>>dp(arr.size());
    int n=arr.size();
    for(int i=arr.size()-1; i>=0; i--)
    {
        for(int j=arr.size()-1; j>=0; j--)
        {
            if(i==n-1 || j==n-1) dp[i][j]=arr[i][j];
            else {
                dp[i][j]=arr[i][j] ==0 ?0: 1+ min(dp[i][j+1],min(dp[i+1][j],dp[i+1][j+1]));
            }

        }
    }
}
 int main()
 {

 }