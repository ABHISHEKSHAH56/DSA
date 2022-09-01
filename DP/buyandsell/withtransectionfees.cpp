// 1. You are given a number n, representing the number of days.
// 2. You are given n numbers, where ith number represents price of stock on ith day.
// 3. You are give a number fee, representing the transaction fee for every transaction.
// 4. You are required to print the maximum profit you can make if you are allowed infinite transactions, but has to pay "fee" for every closed transaction.
// Note - There can be no overlapping transaction. One transaction needs to be closed (a buy followed by a sell) before opening another transaction (another buy).

#include<bits/stdc++.h>
using namespace std;

int  transactions(vector<int> arr, int fee) {
// write your code here buy state profit 
    int obsp=-arr[0];
    int ossp=0;
    for(int i=1; i<arr.size(); i++)
    {
        int nssp=0;
        int nbsp=0;
        if(ossp-arr[i]>obsp) nbsp=ossp-arr[i];
        else nbsp=obsp;
        if(obsp+arr[i]-fee>ossp) ossp=obsp+arr[i]-fee;
        else nssp=obsp;
        ossp=nssp;
        obsp=nbsp;
    }
    return ossp;
}