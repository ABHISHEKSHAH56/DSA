 
// 1. You are given two strings s1 and s2.
// 2. You have to find the minimum number of operations needed to convert s1 to s2.
//    Operations allowed are - 
//    Insert - You can insert any character in s1.
//    Remove - You can remove any character in s1.
//    Replace - You can replace any character in s1 with any other character.

 
 #include <bits/stdc++.h>
 using namespace std;
 
 
 int minDistance(string w, string w2) {
        vector<vector<int>>dp(w.size()+1,vector<int>(w2.size()+1));
        for(int i=0; i<dp.size(); i++)
        {
            for(int j=0 ; j<dp[0].size(); j++){
                if(i==0) dp[i][j]=j;
                else if(j==0) dp[i][j]=i;
                else{
                    if(w[i-1]==w2[j-1]) {
                        dp[i][j]=dp[i-1][j-1]; 
                    }
                    else {
                        dp[i][j]=1+min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]));
                    }
                    
                }
            }
        }
        return dp[w.size()][w2.size()];
        
    }