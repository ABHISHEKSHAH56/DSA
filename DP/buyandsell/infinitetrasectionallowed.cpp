// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are required to print the maximum profit you can make if you are allowed infinite transactions.
// Note - There can be no overlapping transaction. One transaction nee
#include<bits/stdc++.h>
using namespace std;
int  transactions(vector<int> arr) {

    // write your code here buying date
    int bd=0;
    int sd=0;
    int profit=0;
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i]>=arr[i-1]) sd++;
        else{
            profit+=arr[sd]-arr[bd];
            sd=bd=i;
        }
    }
    return profit;

}