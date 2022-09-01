// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed two transactions at-most.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).
#include <bits/stdc++.h>
using namespace std;

int transection(vector<int>arr)
{
    //max profit if sold today least so far 
    int mpist=0;
    int leastsf=arr[0];
    //max profit if sold  up to today !!
    vector<int> dp(arr.size());
    for(int i=1; i<arr.size(); i++)
    {
        if(leastsf<arr[i]) leastsf=arr[i];
        mpist=arr[i]-leastsf;
        if(mpist>dp[i-1]) dp[i]=mpist;
        else dp[i]=dp[i-1];
    }
    //maximum profit if buy today 
    int mpibt=0;
   
    vector<int>dpright(arr.size()) ;
     //maximum  after today
    int maxat=arr[arr.size()-1];
    for(int i=arr.size()-2; i>=0; i--)
    {
        if(maxat<arr[i]) maxat=arr[i];
        mpibt=maxat-arr[i];
        if(mpibt>dp[i+1]) dp[i]=mpibt;
        else dp[i]=dp[i+1];
    }

    int op=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(dp[i]+dpright[i]>op) op=dp[i]+dpright[i];
    }
    return op;

}
