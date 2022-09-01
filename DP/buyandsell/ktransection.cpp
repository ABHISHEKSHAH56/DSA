// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are given a number k, representing the number of transactions allowed.
// 3. You are required to print the maximum profit you can make if you are allowed k transactions at-most.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

#include<bits/stdc++.h>
using namespace std; 

void transactions(vector<int> arr, int k) {
  //write your code here
  vector<vector<int>>dp(k,vector<int>(arr.size()));
  //dp[i][j]--->i--transections j--day ---agr jth day pe  max k transection allowed  hota to x profit kaam kama lete 
  for(int i=0; i<k; i++)
  {
    for(int j=0; j<arr.size(); j++)
    {
        if(i==0 || j==0) dp[i][j]=0;
        else{
            int tmaxi=INT_MIN;
            for(int k=0; k<j; k++)
            {
                int todayp=arr[j]-arr[k]+dp[i][k];
                if(todayp>tmaxi) tmaxi=todayp;
            }
            dp[i][j]=max(dp[i][j-1],tmaxi);

        }
        


    }
  }
}

int main()
{

}