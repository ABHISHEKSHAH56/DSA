    //  For 123 -> there are 3 encodings. abc, aw, lc
    //  For 993 -> there is 1 encoding. iic 
    //  For 013 -> This is an invalid input. A string starting with 0 will not be passed.
    //  For 103 -> there is 1 encoding. jc
    //  For 303 -> there are 0 encodings. But such a string maybe passed. In this case 
    //  print 0.

#include <bits/stdc++.h>
using namespace std;

int decoding(map<char,int>mp,string decode)
{
    vector<int>dp(decode.size());
    dp[0]=1;
    for(int i=1; i<dp.size(); i++)
    {
        if(decode[i-1] =='0' && decode[i] =='0') dp[i]=0;
        else if(decode[i-1] !='0' && decode[i] =='0')
        {
           if(decode[i-1]=='1' || decode[i-1]=='2') dp[i]= i>=2 ? dp[i-2] :1;
           else dp[i]=0;
        }  
        else if(decode[i-1] =='0' && decode[i] !='0')  dp[i]=dp[i-1];
        else {
            if(decode[i-1]=='1' || decode[i-1]=='2') dp[i]=i>=2 ? dp[i-2] :1 +dp[i-1];
            else dp[i]=dp[i-1];
        }

    }
}