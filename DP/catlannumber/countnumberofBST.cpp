#include<bits/stdc++.h>
using namespace std;

int numberofbst(int n){
    vector<int>dp(n+1);
    dp[0]=1;
    dp[1]=1;
    for(int i=2; i<=n; i++){
        int l=0; 
        int r=i-1;
        while(l<=i-1){
            dp[i]+=dp[l]*dp[r];
            l++;
            r--;
        }
    }
}